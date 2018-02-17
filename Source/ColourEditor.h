/*
  ==============================================================================

    ColourEditor.h
    Created: 17 Feb 2018 2:31:43pm
    Author:  Douglas Barr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/** A component that is shown to pick a new colour and give it a name. The chosen values will overwrite a
 *  colour entry in a ValueTree.
 *
 *  This should look and behave a little bit like a modal window, but isn't.
 */

class ColourEditor
:
public Component,
public ChangeListener,
public TextButton::Listener
{
public:
    
    ColourEditor(ValueTree tree);
    
    void paint (Graphics& g) override;
    
    void resized() override;
    
    /** The ColourSelector object uses the ChangeBroadcaster/Listener pattern to provide access to it's data.
     */
    void changeListenerCallback (ChangeBroadcaster* source) override;
    
    void buttonClicked (Button* b) override;
    
    /** Makes the editor visible and sets the ColourSelector and colourName based on the colour node that index
     *  refers to in the ValueTree.
     */
    void showEditorForColourEntry (int index);
    
    /** Hides the component
     */
    void dismissColourEditor ();
    
private:
    
    int valueTreeEntryActiveOnOpen { 0 };
    
    /** Ths should store a reference to the main parent node of the ValueTree set up in MainComponent
     */
    ValueTree colourCodesAndNames;
    
    Colour fillColour { Colours::antiquewhite };
    String colourName { "Antique White" };
    String colourCode { "0xfffaebd7" };
    
    ColourSelector colourSelector;
    
    TextEditor colourNameInput;
    
    TextButton submitButton { "Submit" };
    TextButton cancelButton { "Cancel" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourEditor)
};
