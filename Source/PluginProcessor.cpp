/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SoftwareRingModulatorAudioProcessor::SoftwareRingModulatorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

SoftwareRingModulatorAudioProcessor::~SoftwareRingModulatorAudioProcessor()
{
}

//==============================================================================
const String SoftwareRingModulatorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SoftwareRingModulatorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SoftwareRingModulatorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SoftwareRingModulatorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SoftwareRingModulatorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SoftwareRingModulatorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SoftwareRingModulatorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SoftwareRingModulatorAudioProcessor::setCurrentProgram (int index)
{
}

const String SoftwareRingModulatorAudioProcessor::getProgramName (int index)
{
    return {};
}

void SoftwareRingModulatorAudioProcessor::changeProgramName (int index, const String& newName)
{
}



//==============================================================================
void SoftwareRingModulatorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SoftwareRingModulatorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SoftwareRingModulatorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SoftwareRingModulatorAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0; // [1]
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    void updateAngleDelta();

    auto cyclesPerSample = currentSampleRate;         // [2]
    angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;                // [3]

   {
//TEMP DELELETD  //  auto sampleRate = currentSampleRate;
   // updateAngleDelta();
}

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    {

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
        
     void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill); //no &
       
        
        {
  auto level = 0.125f;
    auto* leftBuffer  = buffer.getWritePointer (0, buffer.getNumSamples());
    auto* rightBuffer = buffer.getWritePointer (1, buffer.getNumSamples());
        auto* device = AudioDeviceManager().getCurrentAudioDevice();
        auto activeInputChannels  = device->getActiveInputChannels();
        auto activeOutputChannels = device->getActiveOutputChannels();
        
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
       // auto* channelData = buffer.getWritePointer (channel);
       auto* inBuffer = buffer.getReadPointer(channel);
        auto* outBuffer = buffer.getWritePointer(channel);
    
     
        inBuffer = buffer.getReadPointer (totalNumInputChannels,
                                                                      buffer.getNumSamples());
        outBuffer = buffer.getWritePointer (totalNumInputChannels, buffer.getNumSamples());
 
                for (auto sample = 0; sample < buffer.getNumSamples(); ++sample)
                    outBuffer[sample] = inBuffer[sample];// * level;
       for (auto samples = 0; samples < buffer.getNumChannels(); ++samples)
    {
        auto currentSample = (float) std::sin (currentAngle);
        currentAngle += angleDelta;
        leftBuffer[samples]  = currentSample * level;
        rightBuffer[samples] = currentSample * level;
    }
    }
}
        }
    }


//==============================================================================
bool SoftwareRingModulatorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SoftwareRingModulatorAudioProcessor::createEditor()
{
    return new SoftwareRingModulatorAudioProcessorEditor (*this);
}

//==============================================================================
void SoftwareRingModulatorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SoftwareRingModulatorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SoftwareRingModulatorAudioProcessor();
}
