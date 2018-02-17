/*
  ==============================================================================

    ColourPalleteDisplay.h
    Created: 17 Feb 2018 10:50:04am
    Author:  Douglas Barr

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


class ColourPalleteDisplay: public Component
{
public:
    
    ColourPalleteDisplay()
    {
    }
    
    ColourPalleteDisplay(const String& colourCode, const String& colourName);
    
    void paint (Graphics& g) override;
    
    void setColourFromHexCodeAndName (const String& newHexCode, const String& colourName);
    
private:
    
    Colour fillColour { Colours::antiquewhite };
    String colourName { "Antique White" };
};

#pragma once
