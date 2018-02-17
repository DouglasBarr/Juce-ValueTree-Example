/*
  ==============================================================================

    ColourPalleteDisplay.h
    Created: 17 Feb 2018 10:50:04am
    Author:  Douglas Barr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/** Displays a colour entry in a ValueTree.
 *
 *  Shows a box filled with the given colour, it's name and it's hex colour code.
 */

class ColourPalleteDisplay: public Component, public ValueTree::Listener
{
public:
    
    ColourPalleteDisplay(ValueTree tree);
    
    void paint (Graphics& g) override;
    
    /** Tries to find a node in the ValueTree using the given index. If it exists, then the colour data is 
     *  extracted and the display updated.
     */
    void pickNewColourFromValueTree (int childIndex);
    
    //=================================
    
    // All the listeners for the ValueTree class. Most of these aren't being used at the moment.
    
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
    
    /** Ths should store a reference to the main parent node of the ValueTree set up in MainComponent
     */
    ValueTree colourCodesAndNames;
        
    Colour fillColour { Colours::antiquewhite };
    String colourName { "Antique White" };
    String colourCode { "#faebd7" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourPalleteDisplay)
};

