/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "ColourEditor.h"


//==============================================================================
MainContentComponent::MainContentComponent(): randomiseButton("Pick New Colour From ValueTree")
{
    const XmlElement demoData = *XmlDocument::parse (BinaryData::demo_data_xml);
    
    colourDataFromXML = ValueTree::fromXml(demoData);
    
    colouredSquare = std::make_unique<ColourPalleteDisplay>(colourDataFromXML);
    
    addAndMakeVisible(*colouredSquare);
    
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
        ColourEditor* colourSelector = new ColourEditor(colourDataFromXML, currentColour);
        
        colourSelector->setSize (300, 450);
        
        CallOutBox::launchAsynchronously (colourSelector, b->getScreenBounds(), nullptr);
    }
    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainContentComponent::resized()
{
    randomiseButton.setBounds(50, 100, 130, 70);
    editColourButton.setBounds(50, 205, 130, 70);
    
    colouredSquare->setBounds(getLocalBounds().removeFromRight(400).withSizeKeepingCentre(250, 250));
}
