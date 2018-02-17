/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent(): randomiseButton("Pick New Colour From ValueTree")
{
    setSize (600, 400);
    
    const XmlElement demoData = *XmlDocument::parse (BinaryData::demo_data_xml);
    
    colourDataFromXML = ValueTree::fromXml(demoData);
    
    addAndMakeVisible(colouredSquare);
    addAndMakeVisible(randomiseButton);
    
    randomiseButton.addListener(this);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::buttonClicked (Button*)
{
    currentColour = (currentColour + 1) % 4;
    
    auto child = colourDataFromXML.getChild(currentColour);
    
    colouredSquare.setColourFromHexCode(child.getPropertyAsValue("ColourCode", nullptr).toString());
    colouredSquare.repaint();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void MainContentComponent::resized()
{
    randomiseButton.setBounds(50, 100, 130, 70);
    
    colouredSquare.setBounds(getLocalBounds().removeFromRight(400).withSizeKeepingCentre(250, 250));
}
