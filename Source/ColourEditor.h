/*
  ==============================================================================

    ColourEditor.h
    Created: 17 Feb 2018 2:31:43pm
    Author:  Douglas Barr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


class ColourEditor
:
public Component,
public ChangeListener,
public TextButton::Listener
{
public:
    
    ColourEditor(ValueTree tree, int currentColourCode);
    
    void paint (Graphics& g) override;
    
    void resized() override;
    
    void changeListenerCallback (ChangeBroadcaster* source) override;
    void buttonClicked (Button* b) override;
    
    class JUCE_API Listener
    {
    public:
        virtual ~Listener()  {}
        virtual void valueTreeSuccessfullyUpdated () = 0;
    };
    
    void addListener (Listener* newListener)    { listeners.add(newListener); }
    void removeListener (Listener* listener)    { listeners.remove(listener); }
    
private:
    
    ListenerList<Listener> listeners;
    
    const int valueTreeEntryActiveOnOpen;
    
    ValueTree colourCodesAndNames;
    
    Colour fillColour { Colours::antiquewhite };
    String colourName { "Antique White" };
    String colourCode { "0xfffaebd7" };
    
    ColourSelector colourSelector;
    TextEditor colourNameInput;
    TextButton submitButton { "Submit" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourEditor)
};
