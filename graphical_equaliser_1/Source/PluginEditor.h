/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "EQKnobs.h"
#include "Equalizer.h"

//==============================================================================
/**
*/
class Graphical_equaliserAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Graphical_equaliserAudioProcessorEditor (Graphical_equaliserAudioProcessor& p);
    ~Graphical_equaliserAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Graphical_equaliserAudioProcessor& audioProcessor;
    EQKnobs eqKnobs;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Graphical_equaliserAudioProcessorEditor)
};
