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
    
    addAndMakeVisible(submitButton);
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
    colourName = colourNameInput.getText();
    
    if (colourName.isEmpty())
        return;
    
    auto colourEntryToEdit = colourCodesAndNames.getChild(valueTreeEntryActiveOnOpen);
    
    if (!colourEntryToEdit.isValid())
        return;
    
    colourEntryToEdit.setProperty("ColourCode", "0x" + colourCode, nullptr);
    colourEntryToEdit.setProperty("ColourName", colourName, nullptr);
    
    setVisible(false);
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
    
    auto bottomBar = bounds.removeFromBottom(bounds.proportionOfHeight(0.2f));
    
    const int sideMargin = bottomBar.proportionOfWidth(0.05f);
    
    bottomBar.removeFromLeft(sideMargin);
    bottomBar.removeFromRight(sideMargin);
    
    if (bottomBar.getHeight() > 25)
        bottomBar = bottomBar.withSizeKeepingCentre(bottomBar.getWidth(), 25);
    
    const int textEditorWidth = bounds.proportionOfWidth(0.6f);
    const int submitButtonWidth = bounds.proportionOfWidth(0.2f);
    
    colourNameInput.setBounds(bottomBar.removeFromLeft(textEditorWidth));
    submitButton.setBounds(bottomBar.removeFromRight(submitButtonWidth));
    colourSelector.setBounds(bounds);
    
}
