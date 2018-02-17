/*
  ==============================================================================

    ColourPalleteDisplay.cpp
    Created: 17 Feb 2018 10:50:04am
    Author:  Douglas Barr

  ==============================================================================
*/

#include "ColourPalleteDisplay.h"

ColourPalleteDisplay::ColourPalleteDisplay(const String& colourCode, const String& colourName)
{
    setColourFromHexCodeAndName(colourCode, colourName);
}

void ColourPalleteDisplay::paint (Graphics& g)
{
    auto fillArea = getLocalBounds();
    auto textArea = fillArea.removeFromBottom(20);
    
    g.setColour(fillColour);
    g.fillRect(fillArea);
    
    g.setColour(Colours::antiquewhite);
    g.setFont(18);
    g.drawText(colourName, textArea, Justification::centredLeft);
}

void ColourPalleteDisplay::setColourFromHexCodeAndName (const String& newHexCode, const String& newColourName)
{
    fillColour = Colour::fromString(newHexCode);
    colourName = newColourName;
}
