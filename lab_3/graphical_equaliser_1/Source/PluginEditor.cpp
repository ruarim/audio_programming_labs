/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Graphical_equaliserAudioProcessorEditor::Graphical_equaliserAudioProcessorEditor (Graphical_equaliserAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), eqKnobs(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (585, 320);
    
    addAndMakeVisible(&eqKnobs);
}

Graphical_equaliserAudioProcessorEditor::~Graphical_equaliserAudioProcessorEditor()
{
}

//==============================================================================
void Graphical_equaliserAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void Graphical_equaliserAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
