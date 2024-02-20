/*
  ==============================================================================

    KarplusStrongSound.h
    Created: 19 Feb 2024 4:18:59pm
    Author:  Ruari Molyneux

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class KarplusStrongSound : public juce::SynthesiserSound
{
public:
    KarplusStrongSound() {}
    bool appliesToNote(int /*midiNoteNumber*/) override { return true; }
    bool appliesToChannel(int /*midiChannel*/) override { return true; }
};
