/*
  ==============================================================================

    ColourEditor.cpp
    Created: 17 Feb 2018 2:31:43pm
    Author:  Douglas Barr

  ==============================================================================
*/

#include "ColourEditor.h"


ColourEditor::ColourEditor (ValueTree tree)
:
colourCodesAndNames(tree)
{
    colourSelector.setName ("background");
    colourSelector.setCurrentColour (findColour (TextButton::buttonColourId));
    colourSelector.setColour (ColourSelector::backgroundColourId, Colours::transparentBlack);
    
    colourSelector.setCurrentColour(Colours::antiquewhite);
    
    colourSelector.addChangeListener(this);
    
    addAndMakeVisible(colourSelector);
    
    colourNameInput.setTextToShowWhenEmpty("Antique White", Colours::white.withMultipliedBrightness(0.95f));
    
    addAndMakeVisible(colourNameInput);
    
    submitButton.addListener(this);
    cancelButton.addListener(this);
    
    addAndMakeVisible(submitButton);
    addAndMakeVisible(cancelButton);
}

void ColourEditor::showEditorForColourEntry (int index)
{
    valueTreeEntryActiveOnOpen = index;
    
    auto colourEntry = colourCodesAndNames.getChild(valueTreeEntryActiveOnOpen);
    
    if (!colourEntry.isValid())
        return;
    
    colourName  = colourEntry.getPropertyAsValue("ColourName", nullptr).toString();
    colourCode  = colourEntry.getPropertyAsValue("ColourCode", nullptr).toString();
    
    fillColour = Colour::fromString(colourCode);
    
    colourSelector.setCurrentColour(fillColour);
    colourNameInput.setTextToShowWhenEmpty(colourName, Colours::white.withMultipliedBrightness(0.95f));
    
    setVisible(true);
}

void ColourEditor::dismissColourEditor ()
{
    setVisible(false);
}

void ColourEditor::changeListenerCallback (ChangeBroadcaster* source)
{
    if (ColourSelector* cs = dynamic_cast<ColourSelector*> (source))
    {
        fillColour = cs->getCurrentColour();
        colourCode = fillColour.toString();
    }
}

void ColourEditor::buttonClicked (Button* b)
{
    if (b == &submitButton)
    {
        auto colourEntryToEdit = colourCodesAndNames.getChild(valueTreeEntryActiveOnOpen);
        
        if (!colourEntryToEdit.isValid())
            return;
        
        colourName = colourNameInput.getText();
        
        if (colourName.isNotEmpty())
            colourEntryToEdit.setProperty("ColourName", colourName, nullptr);
        
        colourEntryToEdit.setProperty("ColourCode", "0x" + colourCode, nullptr);
    }
    
    dismissColourEditor(); // triggered on successful colour value editing or when the cancel button is pressed
}

void ColourEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black.withAlpha(0.5f));
    
    g.setColour(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillRect(getLocalBounds().withSizeKeepingCentre(320, 420));
}

void  ColourEditor::resized()
{
    auto bounds = getLocalBounds().withSizeKeepingCentre(300, 400);
    
    auto buttonArea = bounds.removeFromBottom(40).reduced(20, 5);
    auto textEditorArea = bounds.removeFromBottom(40).reduced(28, 5);
    
    colourSelector.setBounds(bounds.reduced(20));
    
    colourNameInput.setBounds(textEditorArea);
    
    submitButton.setBounds(buttonArea.removeFromLeft(buttonArea.proportionOfWidth(0.5f)).reduced(8, 0));
    cancelButton.setBounds(buttonArea.reduced(8, 0));
}
