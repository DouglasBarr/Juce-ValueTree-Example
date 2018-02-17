/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "ColourPalleteDisplay.h"
#include "ColourEditor.h"

//==============================================================================
MainContentComponent::MainContentComponent(): randomiseButton("Pick New Colour From ValueTree")
{
    const XmlElement demoData = *XmlDocument::parse (BinaryData::demo_data_xml);
    
    colourDataFromXML = ValueTree::fromXml(demoData);
    
    colouredSquare = std::make_unique<ColourPalleteDisplay>(colourDataFromXML);
    colourValueEditor = std::make_unique<ColourEditor>(colourDataFromXML);
    
    addAndMakeVisible(*colouredSquare);
    
    addChildComponent(*colourValueEditor);
    
    addAndMakeVisible(randomiseButton);
    addAndMakeVisible(editColourButton);
    
    randomiseButton.addListener(this);
    editColourButton.addListener(this);
    
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::buttonClicked (Button* b)
{
    if (b == &randomiseButton)
    {
        currentColour = (currentColour + 1) % 4;
        
        colouredSquare->pickNewColourFromValueTree(currentColour);
        colouredSquare->repaint();
    }
    else if (b == &editColourButton)
    {   
        colourValueEditor->toFront(false);
        colourValueEditor->showEditorForColourEntry(currentColour);
    }
    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainContentComponent::resized()
{
    colourValueEditor->setBounds(getLocalBounds());
    
    randomiseButton.setBounds(50, 100, 130, 70);
    editColourButton.setBounds(50, 205, 130, 70);
    
    colouredSquare->setBounds(getLocalBounds().removeFromRight(400).withSizeKeepingCentre(250, 250));
}
