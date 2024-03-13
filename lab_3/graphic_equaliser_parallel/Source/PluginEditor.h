/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "EQControls.h"

//==============================================================================
/**
*/
class Graphical_equaliser_4AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Graphical_equaliser_4AudioProcessorEditor (Graphical_equaliser_4AudioProcessor&);
    ~Graphical_equaliser_4AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Graphical_equaliser_4AudioProcessor& audioProcessor;
    EQControls eqControls;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Graphical_equaliser_4AudioProcessorEditor)
};
