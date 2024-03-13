/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Graphical_equaliser_4AudioProcessorEditor::Graphical_equaliser_4AudioProcessorEditor (Graphical_equaliser_4AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), eqControls(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (585, 320);
    
    addAndMakeVisible(&eqControls);
}

Graphical_equaliser_4AudioProcessorEditor::~Graphical_equaliser_4AudioProcessorEditor()
{
}

//==============================================================================
void Graphical_equaliser_4AudioProcessorEditor::paint (juce::Graphics& g)
{

}

void Graphical_equaliser_4AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
