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
    return 0;
}//main()

