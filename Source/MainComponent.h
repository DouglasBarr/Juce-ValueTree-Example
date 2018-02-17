/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class ColouredComponent: public Component
{
public:
    
    ColouredComponent(): fillColour(Colours::antiquewhite)
    {
    }
    
    ColouredComponent(const String& colourCode)
    {
        setColourFromHexCode(colourCode);
    }
    
    void paint (Graphics& g) override
    {
        g.fillAll(fillColour);
    }
    
    void setColourFromHexCode (const String& newHexCode)
    {
        fillColour = Colour::fromString(newHexCode);
    }
    
private:
    
    Colour fillColour;
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
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
    
    ColouredComponent colouredSquare;
    
    TextButton randomiseButton;
    
    int currentColour { 0 };
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
