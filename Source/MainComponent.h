/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
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
