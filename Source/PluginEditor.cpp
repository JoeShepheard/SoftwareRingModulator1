/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SoftwareRingModulatorAudioProcessorEditor::SoftwareRingModulatorAudioProcessorEditor (SoftwareRingModulatorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    
    mixSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    mixSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    mixSlider.setRange(0.0, 1.0);
    mixSlider.setValue(0.5);
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);
    
}

SoftwareRingModulatorAudioProcessorEditor::~SoftwareRingModulatorAudioProcessorEditor()
{
}

//==============================================================================
void SoftwareRingModulatorAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void SoftwareRingModulatorAudioProcessorEditor::resized()
{
    mixSlider.setBounds(getLocalBounds());
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void  SoftwareRingModulatorAudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider ==&mixSlider)
    {
        processor.level = mixSlider.getValue();
    }
}
