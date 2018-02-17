/*
  ==============================================================================

    ColourPalleteDisplay.cpp
    Created: 17 Feb 2018 10:50:04am
    Author:  Douglas Barr

  ==============================================================================
*/

#include "ColourPalleteDisplay.h"


ColourPalleteDisplay::ColourPalleteDisplay (ValueTree tree): colourCodesAndNames(tree)
{
    pickNewColourFromValueTree (0);
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
    g.drawText(colourCode, textArea, Justification::centredRight);
}

void ColourPalleteDisplay::pickNewColourFromValueTree (int childIndex)
{
    auto child = colourCodesAndNames.getChild(childIndex);
    
    if (!child.isValid())
    {
        AlertWindow::showMessageBox(AlertWindow::AlertIconType::WarningIcon,
                                    "We can't find the colour you're looking for",
                                    "Please try again or tell the developer you hit this.");
        return;
    }
    
    colourName = child.getPropertyAsValue("ColourName", nullptr).toString();
    
    const auto fullColourCode = child.getPropertyAsValue("ColourCode", nullptr).toString();
    
    colourCode = "#" + fullColourCode.substring(4);
    
    fillColour = Colour::fromString(fullColourCode);
}
