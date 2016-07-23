#include <iostream>
#include "Finch.h"

using namespace std;

int main(){
    Finch myFinch;
    if(!myFinch.isInitialized()){
        return -1;
    }//if
    unsigned int rgb[] = {255, 0, 0};
    myFinch.setLED(rgb[0], rgb[1], rgb[2]);
    myFinch.setMotors(100, 100, 3000);
    myFinch.setMotors(0,0);
    return 0;
}//main()

