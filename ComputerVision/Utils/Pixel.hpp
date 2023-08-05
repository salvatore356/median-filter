//
//  Pixel.hpp
//  ComputeVision
//
//  Created by Salvatore on 25/7/23.
//

#ifndef Pixel_hpp
#define Pixel_hpp

#include <stdio.h>

struct Pixel {
    float r, g, b;
    
    Pixel(){
        this->r = 0.0;
        this->g = 0.0;
        this->b = 0.0;
    }
    
    Pixel(float r, float g, float b){
        this->r = r;
        this->g = g;
        this->b = b;
    }
    
    Pixel operator*(float mult){
        return Pixel{
            this->r * mult,
            this->g * mult,
            this->b * mult
        };
    }
    
    Pixel operator+(Pixel pix){
        return Pixel{
            this->r + pix.r,
            this->g + pix.g,
            this->b + pix.b
        };
    }
    
    Pixel operator+(float pix){
        return Pixel{
            this->r + pix,
            this->g + pix,
            this->b + pix
        };
    }
    
    void clamp() {
        this->r = std::max(0.0f, std::min(1.0f, this->r));
        this->g = std::max(0.0f, std::min(1.0f, this->g));
        this->b = std::max(0.0f, std::min(1.0f, this->b));
    }
};

#endif /* Pixel_hpp */
