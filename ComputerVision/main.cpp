//
//  main.cpp
//  ComputerVision
//
//  Created by Salvatore on 29/7/23.
//

#include <iostream>
#include <format>

#include "Utils/Utils.hpp"
#include "MedianFilter/MedianFilter.hpp"

using namespace std;

enum Noise
{   saltAndPepper = 0,
    shot,
    speckle,
    gauss
};

void applyNoiseAndFilter(Noise noise, Image img, int filter_size = 3){
    string pathNoise = "";
    
    switch (noise) {
        case saltAndPepper:
            pathNoise = "salt-and-pepper.jpg";
            applySaltAndPepperNoise(img);
            break;
        case shot:
            pathNoise = "shot.jpg";
            applyShotNoise(img);
            break;
        case speckle:
            pathNoise = "speckle.jpg";
            applySpeckleNoise(img);
            break;
        default:
            pathNoise = "gauss.jpg";
            applyGaussianNoiseToImage(img);
            break;
    }
    
    writeJPG(img, pathNoise);
    auto filtered = applyMedianFilterToImage(img, filter_size);
    writeJPG(filtered, "filtered-" + pathNoise);
}

int main(int argc, const char * argv[]) {
    auto img = readJPG("salt-pepper.jpg");
    
    applyNoiseAndFilter(gauss, *img);
    
    applyNoiseAndFilter(shot, *img);
    applyNoiseAndFilter(speckle, *img);
    applyNoiseAndFilter(saltAndPepper, *img);
    
    printf("Done\n");
    return 0;
    
    
}
