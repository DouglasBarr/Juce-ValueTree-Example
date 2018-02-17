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
    // The XML file has been added to the Binary using the Projucer BinaryBuilder, to make this example a bit
    // more portable.
    
    // This means that I haven't added in an example of writing to the XML file from the ValueTree, but
    // that might come later.
    
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
        
        // This just cycles through the four colour nodes stored in the ValueTree at the moment. A bit
        // odd but it'll do for the moment.
        
        currentColour = (currentColour + 1) % 4;
        
        colouredSquare->pickNewColourFromValueTree(currentColour);
    }
    else if (b == &editColourButton)
    {
        // The visibility of this is managed to make it look like a modal window, but it's not.
        
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
