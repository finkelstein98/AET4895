/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TheHouseShowAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener

{
public:
    TheHouseShowAudioProcessorEditor (TheHouseShowAudioProcessor&);
    ~TheHouseShowAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;
    
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TheHouseShowAudioProcessor& processor;
    
    Slider output_gainSlider;
    Label output_gainLabel;
    Slider saturationSlider;
    Label saturationLabel;
    Slider delay_mix_slider;
    Label delay_mix_label;
    Slider delay_fbk_slider;
    Label delay_fbk_label;
    Slider low_filterSlider;
    Label low_filterLabel;
    Slider high_filterSlider;
    Label high_filterLabel;
    Slider EFXmixSlider;
    Label EFXmixLabel;
   
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TheHouseShowAudioProcessorEditor)
};
