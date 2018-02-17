/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This is designed to be a quick demo of the ValueTree handling inside Juce.
 
    There is a short XML file with four colour values which gets loaded in as a ValueTree and then passed around
    the other components. 
 
    One of the components makes changes to the ValueTree internally (the ColourEditor), and the other is a 
    ValueTree::Listener which gets updated when a change is made.
 
    The ValueTree colourDataFromXML looks like it gets passed around by value, but it's operator= is overriden so
    that the new ValueTree points at the node that is passed in.
*/

class ColourPalleteDisplay;
class ColourEditor;

class MainContentComponent
:
public Component,
public TextButton::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;
    
    void buttonClicked (Button*) override;

private:
        
    ValueTree colourDataFromXML;
    
    std::unique_ptr<ColourPalleteDisplay> colouredSquare;
    std::unique_ptr<ColourEditor> colourValueEditor;
    
    TextButton randomiseButton;
    TextButton editColourButton { "Edit current colour" };
    
    int currentColour { 0 };
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
