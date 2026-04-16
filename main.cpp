#include <iostream>
#include <fstream>
#include <cmath>

#define PIE 3.14159265358979323846 

const int sampleRate = 44100;


class SineOscillator{
    float frequency;
    float amplitude;
    float angle  = 0.0f;
    float offset = 0.0;

    public:
    SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp) {
        offset = 2 * PIE * frequency / sampleRate;

    }

    float process() {
        // Asin(2pif/sr)
        auto sample = amplitude * sin(angle);
        angle += offset;

        return sample;
    }




};



int main(){
    std::ofstream audioFile;
    audioFile.open("waveform");

    float FREQUENCY = 440;
    float AMPLITUDE = 0.5;
    int   DURATION  = 2;

    SineOscillator SineOscillator(FREQUENCY,AMPLITUDE);

    for(int i =0; i< sampleRate * DURATION; i++){
        audioFile << SineOscillator.process() << std::endl;

    }


    audioFile.close();
    return 0;
}