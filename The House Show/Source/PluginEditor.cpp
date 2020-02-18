/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TheHouseShowAudioProcessorEditor::TheHouseShowAudioProcessorEditor (TheHouseShowAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 450);
   
    //Saturation knob
    saturationSlider.addListener(this);
    saturationSlider.setSliderStyle(Slider::Rotary);
    saturationSlider.setBounds(0.5, 75, 175, 175);
    saturationSlider.setRange(1.0f, 10.0f);
    addAndMakeVisible(saturationSlider);
    addAndMakeVisible (saturationLabel);
saturationLabel.setText("Saturation", dontSendNotification);
    saturationLabel.attachToComponent (&saturationSlider, true);
    saturationLabel.setBounds(0.5, 120, 100, 40);
    
    //Delay Mix
    delay_mix_slider.addListener(this);
    delay_mix_slider.setSliderStyle(Slider::Rotary);
    delay_mix_slider.setBounds(0.5, 180, 175, 175);
    delay_mix_slider.setRange(0.0f, 100.0f);
    delay_mix_slider.setMouseDragSensitivity(15);
    //delay_mix_slider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 50);
       addAndMakeVisible(delay_mix_slider);
        addAndMakeVisible (delay_mix_label);
    delay_mix_label.setText("Delay Mix", dontSendNotification);
        delay_mix_label.attachToComponent (&delay_mix_slider, true);
        delay_mix_label.setBounds(0.5, 230, 100, 40);
    
    //Delay Feedback
    delay_fbk_slider.addListener(this);
    delay_fbk_slider.setSliderStyle(Slider::Rotary);
    delay_fbk_slider.setBounds(0.5, 290, 175, 175);
    delay_fbk_slider.setRange(0.0f, 100.0f);
    delay_fbk_slider.setMouseDragSensitivity(15);
   // delay_fbk_slider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 50);
       addAndMakeVisible(delay_fbk_slider);
     addAndMakeVisible (delay_fbk_label);
    delay_fbk_label.setText("Feedback", dontSendNotification);
        delay_fbk_label.attachToComponent (&delay_fbk_slider, true);
        delay_fbk_label.setBounds(0.5, 340, 100, 40);
    
    //Low-Shelf Filter
    low_filterSlider.addListener(this);
    low_filterSlider.setSliderStyle(Slider::LinearBar);
    low_filterSlider.setBounds(250, 120, 150, 100);
    low_filterSlider.setRange(30, 500);
    low_filterSlider.setSkewFactorFromMidPoint(150.0f);
    addAndMakeVisible(low_filterSlider);
    addAndMakeVisible(low_filterLabel);
    low_filterLabel.attachToComponent(&low_filterSlider, true);
    low_filterLabel.setBounds(300, 100, 50, 50);
    
    //High-Shelf Filter
    high_filterSlider.addListener(this);
      high_filterSlider.setSliderStyle(Slider::LinearBar);
      high_filterSlider.setBounds(250, 240, 150, 100);
      high_filterSlider.setRange(6000, 15000);
      high_filterSlider.setSkewFactorFromMidPoint(10000.0f);
      addAndMakeVisible(high_filterSlider);
      addAndMakeVisible(high_filterLabel);
      high_filterLabel.attachToComponent(&low_filterSlider, true);
      high_filterLabel.setBounds(300, 100, 50, 50);
    
    //Output gain slider
    output_gainSlider.addListener(this);
    output_gainSlider.setSliderStyle(Slider::LinearVertical);
    output_gainSlider.setBounds(400, 100, 100, 320);
    output_gainSlider.setRange(0.0f, 2.0f);
    output_gainSlider.setSkewFactorFromMidPoint(1.0f);
    output_gainSlider.setMouseDragSensitivity(15);
    output_gainSlider.setValue(processor.gainMultiplier);
    output_gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 50);
    output_gainSlider.setTextValueSuffix(" - Output Gain");
    addAndMakeVisible(output_gainSlider);

    //Wet/Dry mix slider
    EFXmixSlider.addListener(this);
    EFXmixSlider.setSliderStyle(Slider::LinearVertical);
    EFXmixSlider.setBounds(500, 100, 100, 320);
    EFXmixSlider.setRange(0.0f, 100.0f);
    EFXmixSlider.setMouseDragSensitivity(15);
    EFXmixSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
    EFXmixSlider.setTextValueSuffix(" - Dry/Wet Mix");
    addAndMakeVisible(EFXmixSlider);
    
    //Bypass Button
    
    

  
}

TheHouseShowAudioProcessorEditor::~TheHouseShowAudioProcessorEditor()
{
}

//==============================================================================
void TheHouseShowAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    ColourGradient gradient;
    auto viewBounds = getLocalBounds();
    
    gradient.point1 = viewBounds.getTopLeft().toFloat();
      gradient.point2 = viewBounds.getTopRight().toFloat();
        gradient.addColour(0.0, Colours::darkslategrey);
    gradient.addColour(1.0, Colours::black);
        g.setGradientFill(gradient);
    g.fillRect((getLocalBounds()));



    g.setColour (Colours::darkorange);
    g.setFont (80.0f);
    g.drawFittedText ("HOUSE SHOW", getLocalBounds(), Justification::topLeft, 1);
}

void TheHouseShowAudioProcessorEditor::resized()
{

}

void
TheHouseShowAudioProcessorEditor::sliderValueChanged(Slider* slider){
 
    if (slider == &output_gainSlider){
       processor.gainMultiplier = output_gainSlider.getValue();
    }
   
}


