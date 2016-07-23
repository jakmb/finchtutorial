/*
* File:   SampleMain.cpp
* Author: Brandon Price
*
* Example function that cycles the light on a Finch
*/


#include <iostream>
#include "Finch.h"

using namespace std;

int main(int /*argc*/, char* /*argv*/[]) {

    Finch myFinch;
    unsigned int rgb[] = {255,0,0};

    for (int count = 0; count < 100; count++) {
        for (int dec = 0; dec < 3; dec += 1) {
            for(int i = 0; i < 255; i += 1) {
                rgb[dec] -= 1;
                rgb[(dec + 1) % 3] += 1;
                myFinch.setLED(rgb[0], rgb[1], rgb[2]);    
            }
        }
    }
    return 0;
}
