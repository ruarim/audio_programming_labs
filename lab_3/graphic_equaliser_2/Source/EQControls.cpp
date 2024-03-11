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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EQControls.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EQControls::EQControls (Graphical_equaliser_2AudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    lowGainKnob.reset (new juce::Slider ("Low Gain"));
    addAndMakeVisible (lowGainKnob.get());
    lowGainKnob->setRange (-12, 12, 0.1);
    lowGainKnob->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    lowGainKnob->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    lowGainKnob->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    lowGainKnob->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    lowGainKnob->addListener (this);

    lowGainKnob->setBounds (0, 29, 153, 175);

    highMidGain.reset (new juce::Slider ("High Mid Gain"));
    addAndMakeVisible (highMidGain.get());
    highMidGain->setRange (-12, 12, 0.1);
    highMidGain->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    highMidGain->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    highMidGain->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    highMidGain->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    highMidGain->addListener (this);

    highMidGain->setBounds (288, 29, 153, 175);

    highGainKnob.reset (new juce::Slider ("High Gain"));
    addAndMakeVisible (highGainKnob.get());
    highGainKnob->setRange (-12, 12, 0.1);
    highGainKnob->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    highGainKnob->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    highGainKnob->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    highGainKnob->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    highGainKnob->addListener (this);

    highGainKnob->setBounds (432, 29, 153, 175);

    lowMidGainKnob.reset (new juce::Slider ("Low Mid Gain"));
    addAndMakeVisible (lowMidGainKnob.get());
    lowMidGainKnob->setRange (-12, 12, 0.1);
    lowMidGainKnob->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    lowMidGainKnob->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    lowMidGainKnob->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    lowMidGainKnob->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    lowMidGainKnob->addListener (this);

    lowMidGainKnob->setBounds (144, 29, 153, 175);

    lowQ.reset (new juce::Slider ("Low Q"));
    addAndMakeVisible (lowQ.get());
    lowQ->setRange (0.2, 12, 0.1);
    lowQ->setSliderStyle (juce::Slider::LinearHorizontal);
    lowQ->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    lowQ->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    lowQ->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    lowQ->addListener (this);

    lowQ->setBounds (18, 250, 117, 39);

    lowMidQ.reset (new juce::Slider ("Low Mid Q"));
    addAndMakeVisible (lowMidQ.get());
    lowMidQ->setRange (0.2, 12, 0.1);
    lowMidQ->setSliderStyle (juce::Slider::LinearHorizontal);
    lowMidQ->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    lowMidQ->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    lowMidQ->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    lowMidQ->addListener (this);

    lowMidQ->setBounds (162, 250, 117, 39);

    highMidQ.reset (new juce::Slider ("High Mid Q"));
    addAndMakeVisible (highMidQ.get());
    highMidQ->setRange (0.2, 12, 0.1);
    highMidQ->setSliderStyle (juce::Slider::LinearHorizontal);
    highMidQ->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    highMidQ->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    highMidQ->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    highMidQ->addListener (this);

    highMidQ->setBounds (306, 250, 117, 39);

    highQ.reset (new juce::Slider ("High Q"));
    addAndMakeVisible (highQ.get());
    highQ->setRange (0.2, 12, 0.1);
    highQ->setSliderStyle (juce::Slider::LinearHorizontal);
    highQ->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    highQ->setColour (juce::Slider::thumbColourId, juce::Colours::coral);
    highQ->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::coral);
    highQ->addListener (this);

    highQ->setBounds (450, 250, 117, 39);

    lowLabel.reset (new juce::Label ("Low Label",
                                     TRANS ("Low")));
    addAndMakeVisible (lowLabel.get());
    lowLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowLabel->setJustificationType (juce::Justification::centred);
    lowLabel->setEditable (false, false, false);
    lowLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowLabel->setBounds (4, 7, 150, 24);

    lowGainLabel.reset (new juce::Label ("Low Gain Label",
                                         TRANS ("Gain")));
    addAndMakeVisible (lowGainLabel.get());
    lowGainLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowGainLabel->setJustificationType (juce::Justification::centred);
    lowGainLabel->setEditable (false, false, false);
    lowGainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowGainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowGainLabel->setBounds (3, 208, 150, 24);

    lowMidLabel.reset (new juce::Label ("Low Mid Label",
                                        TRANS ("Low Mid")));
    addAndMakeVisible (lowMidLabel.get());
    lowMidLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowMidLabel->setJustificationType (juce::Justification::centred);
    lowMidLabel->setEditable (false, false, false);
    lowMidLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowMidLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowMidLabel->setBounds (149, 7, 150, 24);

    highMidLabel.reset (new juce::Label ("High Mid Label",
                                         TRANS ("High Mid")));
    addAndMakeVisible (highMidLabel.get());
    highMidLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highMidLabel->setJustificationType (juce::Justification::centred);
    highMidLabel->setEditable (false, false, false);
    highMidLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highMidLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highMidLabel->setBounds (292, 7, 150, 24);

    highLabel.reset (new juce::Label ("High Label",
                                      TRANS ("High")));
    addAndMakeVisible (highLabel.get());
    highLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highLabel->setJustificationType (juce::Justification::centred);
    highLabel->setEditable (false, false, false);
    highLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highLabel->setBounds (436, 7, 150, 24);

    lowMidGainLabel.reset (new juce::Label ("Low Mid Gain Label",
                                            TRANS ("Gain")));
    addAndMakeVisible (lowMidGainLabel.get());
    lowMidGainLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowMidGainLabel->setJustificationType (juce::Justification::centred);
    lowMidGainLabel->setEditable (false, false, false);
    lowMidGainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowMidGainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowMidGainLabel->setBounds (147, 208, 150, 24);

    highMidGainLabel.reset (new juce::Label ("High Mid Gain Label",
                                             TRANS ("Gain")));
    addAndMakeVisible (highMidGainLabel.get());
    highMidGainLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highMidGainLabel->setJustificationType (juce::Justification::centred);
    highMidGainLabel->setEditable (false, false, false);
    highMidGainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highMidGainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highMidGainLabel->setBounds (291, 208, 150, 24);

    highGainLabel.reset (new juce::Label ("High Gain Label",
                                          TRANS ("Gain")));
    addAndMakeVisible (highGainLabel.get());
    highGainLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highGainLabel->setJustificationType (juce::Justification::centred);
    highGainLabel->setEditable (false, false, false);
    highGainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highGainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highGainLabel->setBounds (435, 208, 150, 24);

    lowQLabel.reset (new juce::Label ("Low Q Label",
                                      TRANS ("Q")));
    addAndMakeVisible (lowQLabel.get());
    lowQLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowQLabel->setJustificationType (juce::Justification::centred);
    lowQLabel->setEditable (false, false, false);
    lowQLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowQLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowQLabel->setBounds (3, 293, 150, 24);

    lowMidQLabel.reset (new juce::Label ("Low Mid Q Label",
                                         TRANS ("Q")));
    addAndMakeVisible (lowMidQLabel.get());
    lowMidQLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    lowMidQLabel->setJustificationType (juce::Justification::centred);
    lowMidQLabel->setEditable (false, false, false);
    lowMidQLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lowMidQLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    lowMidQLabel->setBounds (147, 293, 150, 24);

    highMidQLabel.reset (new juce::Label ("High Mid Q Label",
                                          TRANS ("Q")));
    addAndMakeVisible (highMidQLabel.get());
    highMidQLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highMidQLabel->setJustificationType (juce::Justification::centred);
    highMidQLabel->setEditable (false, false, false);
    highMidQLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highMidQLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highMidQLabel->setBounds (291, 293, 150, 24);

    highQLabel.reset (new juce::Label ("High Q Label",
                                       TRANS ("Q")));
    addAndMakeVisible (highQLabel.get());
    highQLabel->setFont (juce::Font (13.00f, juce::Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.379f));
    highQLabel->setJustificationType (juce::Justification::centred);
    highQLabel->setEditable (false, false, false);
    highQLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    highQLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    highQLabel->setBounds (435, 293, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EQControls::~EQControls()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    lowGainKnob = nullptr;
    highMidGain = nullptr;
    highGainKnob = nullptr;
    lowMidGainKnob = nullptr;
    lowQ = nullptr;
    lowMidQ = nullptr;
    highMidQ = nullptr;
    highQ = nullptr;
    lowLabel = nullptr;
    lowGainLabel = nullptr;
    lowMidLabel = nullptr;
    highMidLabel = nullptr;
    highLabel = nullptr;
    lowMidGainLabel = nullptr;
    highMidGainLabel = nullptr;
    highGainLabel = nullptr;
    lowQLabel = nullptr;
    lowMidQLabel = nullptr;
    highMidQLabel = nullptr;
    highQLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EQControls::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EQControls::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EQControls::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    EQFilters* eq = processor.eq;   // get a pointer to EQFilter object from the processor reference
    float sliderValue = sliderThatWasMoved->getValue();   // get the value from the slider that was moved
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == lowGainKnob.get())
    {
        //[UserSliderCode_lowGainKnob] -- add your slider handling code here..
        eq->lowGainDb = sliderValue;
        //[/UserSliderCode_lowGainKnob]
    }
    else if (sliderThatWasMoved == highMidGain.get())
    {
        //[UserSliderCode_highMidGain] -- add your slider handling code here..
        eq->highMidGainDb = sliderValue;
        //[/UserSliderCode_highMidGain]
    }
    else if (sliderThatWasMoved == highGainKnob.get())
    {
        //[UserSliderCode_highGainKnob] -- add your slider handling code here..
        eq->highGainDb = sliderValue;
        //[/UserSliderCode_highGainKnob]
    }
    else if (sliderThatWasMoved == lowMidGainKnob.get())
    {
        //[UserSliderCode_lowMidGainKnob] -- add your slider handling code here..
        eq->lowMidGainDb = sliderValue;
        //[/UserSliderCode_lowMidGainKnob]
    }
    else if (sliderThatWasMoved == lowQ.get())
    {
        //[UserSliderCode_lowQ] -- add your slider handling code here..
        eq->lowQ = sliderValue;
        //[/UserSliderCode_lowQ]
    }
    else if (sliderThatWasMoved == lowMidQ.get())
    {
        //[UserSliderCode_lowMidQ] -- add your slider handling code here..
        eq->lowMidQ = sliderValue;
        //[/UserSliderCode_lowMidQ]
    }
    else if (sliderThatWasMoved == highMidQ.get())
    {
        //[UserSliderCode_highMidQ] -- add your slider handling code here..
        eq->highMidQ = sliderValue;
        //[/UserSliderCode_highMidQ]
    }
    else if (sliderThatWasMoved == highQ.get())
    {
        //[UserSliderCode_highQ] -- add your slider handling code here..
        eq->highQ = sliderValue;
        //[/UserSliderCode_highQ]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EQControls" componentName=""
                 parentClasses="public juce::Component" constructorParams="Graphical_equaliser_2AudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Low Gain" id="1152f571df07d36e" memberName="lowGainKnob"
          virtualName="" explicitFocusOrder="0" pos="0 29 153 175" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="-12.0" max="12.0" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="High Mid Gain" id="eccd3be99b8b824d" memberName="highMidGain"
          virtualName="" explicitFocusOrder="0" pos="288 29 153 175" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="-12.0" max="12.0" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="High Gain" id="75b7079244e40168" memberName="highGainKnob"
          virtualName="" explicitFocusOrder="0" pos="432 29 153 175" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="-12.0" max="12.0" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Low Mid Gain" id="2146b7ac693bb975" memberName="lowMidGainKnob"
          virtualName="" explicitFocusOrder="0" pos="144 29 153 175" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="-12.0" max="12.0" int="0.1"
          style="RotaryVerticalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Low Q" id="110c65b3703c29b1" memberName="lowQ" virtualName=""
          explicitFocusOrder="0" pos="18 250 117 39" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="0.2" max="12.0" int="0.1" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Low Mid Q" id="6df622c8b879c98f" memberName="lowMidQ" virtualName=""
          explicitFocusOrder="0" pos="162 250 117 39" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="0.2" max="12.0" int="0.1" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="High Mid Q" id="e3a499306740cafb" memberName="highMidQ"
          virtualName="" explicitFocusOrder="0" pos="306 250 117 39" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="0.2" max="12.0" int="0.1" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="High Q" id="383f7020219821f0" memberName="highQ" virtualName=""
          explicitFocusOrder="0" pos="450 250 117 39" thumbcol="ffff7f50"
          rotarysliderfill="ffff7f50" min="0.2" max="12.0" int="0.1" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="Low Label" id="c4efba1c1938247e" memberName="lowLabel"
         virtualName="" explicitFocusOrder="0" pos="4 7 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Low" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Low Gain Label" id="bb1cee4c4a0bf31a" memberName="lowGainLabel"
         virtualName="" explicitFocusOrder="0" pos="3 208 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Low Mid Label" id="38449a6ed3b513ef" memberName="lowMidLabel"
         virtualName="" explicitFocusOrder="0" pos="149 7 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Low Mid" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Mid Label" id="96a3b099f22ef629" memberName="highMidLabel"
         virtualName="" explicitFocusOrder="0" pos="292 7 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="High Mid" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Label" id="5f82c5523d073d0f" memberName="highLabel"
         virtualName="" explicitFocusOrder="0" pos="436 7 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="High" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Low Mid Gain Label" id="a519b6494730169d" memberName="lowMidGainLabel"
         virtualName="" explicitFocusOrder="0" pos="147 208 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Mid Gain Label" id="92275828cd771525" memberName="highMidGainLabel"
         virtualName="" explicitFocusOrder="0" pos="291 208 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Gain Label" id="b21947b03a8f93aa" memberName="highGainLabel"
         virtualName="" explicitFocusOrder="0" pos="435 208 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Low Q Label" id="f3e01b4769c82a47" memberName="lowQLabel"
         virtualName="" explicitFocusOrder="0" pos="3 293 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Low Mid Q Label" id="8d47378d8c6856c6" memberName="lowMidQLabel"
         virtualName="" explicitFocusOrder="0" pos="147 293 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Mid Q Label" id="7b257af940bc1abf" memberName="highMidQLabel"
         virtualName="" explicitFocusOrder="0" pos="291 293 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="High Q Label" id="7fe92c56fe4fb950" memberName="highQLabel"
         virtualName="" explicitFocusOrder="0" pos="435 293 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13.0"
         kerning="0.379" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

