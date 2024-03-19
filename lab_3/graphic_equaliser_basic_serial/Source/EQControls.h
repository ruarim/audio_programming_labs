/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.9

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "EQFilters.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    GUI components class for controling the equaliser parameterrs.
                                                                    //[/Comments]
*/
class EQControls  : public juce::Component,
                    public juce::Slider::Listener
{
public:
    //==============================================================================
    EQControls (Graphical_equaliser_2AudioProcessor& p);
    ~EQControls() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Graphical_equaliser_2AudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> lowGainKnob;
    std::unique_ptr<juce::Slider> highMidGain;
    std::unique_ptr<juce::Slider> highGainKnob;
    std::unique_ptr<juce::Slider> lowMidGainKnob;
    std::unique_ptr<juce::Slider> lowQ;
    std::unique_ptr<juce::Slider> lowMidQ;
    std::unique_ptr<juce::Slider> highMidQ;
    std::unique_ptr<juce::Slider> highQ;
    std::unique_ptr<juce::Label> lowLabel;
    std::unique_ptr<juce::Label> lowGainLabel;
    std::unique_ptr<juce::Label> lowMidLabel;
    std::unique_ptr<juce::Label> highMidLabel;
    std::unique_ptr<juce::Label> highLabel;
    std::unique_ptr<juce::Label> lowMidGainLabel;
    std::unique_ptr<juce::Label> highMidGainLabel;
    std::unique_ptr<juce::Label> highGainLabel;
    std::unique_ptr<juce::Label> lowQLabel;
    std::unique_ptr<juce::Label> lowMidQLabel;
    std::unique_ptr<juce::Label> highMidQLabel;
    std::unique_ptr<juce::Label> highQLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQControls)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

