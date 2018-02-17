/*
  ==============================================================================

    ColourPalleteDisplay.h
    Created: 17 Feb 2018 10:50:04am
    Author:  Douglas Barr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class ColourPalleteDisplay: public Component, public ValueTree::Listener
{
public:
    
    ColourPalleteDisplay(ValueTree tree);
    
    void paint (Graphics& g) override;
    
    void pickNewColourFromValueTree (int childIndex);
    
    //=================================
    
    void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged,
                                   const Identifier& property) override;

    void valueTreeChildAdded (ValueTree& parentTree,
                              ValueTree& childWhichHasBeenAdded) override;
    
    void valueTreeChildRemoved (ValueTree& parentTree,
                                ValueTree& childWhichHasBeenRemoved,
                                int indexFromWhichChildWasRemoved) override;
    
    void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved,
                                     int oldIndex,
                                     int newIndex) override;
    
    void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override;
    
    //=================================
    
private:
    
    ValueTree colourCodesAndNames;
        
    Colour fillColour { Colours::antiquewhite };
    String colourName { "Antique White" };
    String colourCode { "#faebd7" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourPalleteDisplay)
};

