/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SoftwareRingModulatorAudioProcessorEditor  : public AudioProcessorEditor,
                                                   private Slider::Listener
{
public:
    SoftwareRingModulatorAudioProcessorEditor (SoftwareRingModulatorAudioProcessor&);
    ~SoftwareRingModulatorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider *slider) override;
    
    Slider mixSlider;
    Slider frequencySlider;
    

private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoftwareRingModulatorAudioProcessor& processor;
    double currentFrequency = 500.0, targetFrequency = 500.0; // for sinewave generator
   
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftwareRingModulatorAudioProcessorEditor)
};
