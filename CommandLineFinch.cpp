/*******************************************************
 * Command line Finch
 * Author: Tom Lauwers, BirdBrain Technologies
 * tlauwers@finchrobot.com
 *
 * Simple program to access every Finch class function and ensure
 * that they're working correctly. (Note that little/no error-handling
 * of input is performed.)
********************************************************/
#include "Finch.h"
#include <iostream>

using namespace std;

void printMenu() {
    std::cout << "Finch Test Menu: \n"
              << "A - print accelerometer values\n"
              << "o - print orientation state\n"
              << "L - print light sensor values\n"
              << "I - print IR sensor values\n"
              << "T - print temperature\n"
              << "S - print if Finch has been shaken\n"
              << "t - print if Finch has been tapped\n"
              << "B - turn on buzzer\n"
              << "b - turn off buzzer\n"
              << "M - turn on Motors\n"
              << "X - motor stop\n"
              << "O - set beak LED\n"
              << "m - print menu\n"
              << "Q - quit program\n";
}

int main(int /*argc*/, char* /*argv*/[]) {
    Finch myFinch;
    if (!myFinch.isInitialized()) {
        return -1;
    }

    double* accel = 0;
    int* lightSense = 0;
    int* obstacles = 0;
    char option = 0;
    double temperature;
    int leftSpeed, rightSpeed;
    int rLED, gLED, bLED;
    int frequency;
    int shaken, tapped;

    printMenu();

    while(option != 'Q') {
        cout << "Enter desired command: ";
        cin >> option;
        if (cin.fail()) {
            // End of input
            break;
        }
        cin.ignore(10000, '\n');
        switch(option) {
            case 'A':
                accel = myFinch.getAccelerations();
                cout << "X: " << accel[0]
                     << ", Y: " << accel[1]
                     << ", Z: " << accel[2] << '\n';
                delete [] accel;
                accel = 0;
                break;
            case 'o':
                cout << "Level: " << myFinch.isFinchLevel() << '\n'
                     << "Beak Up: " << myFinch.isBeakUp() << '\n'
                     << "Beak Down: " << myFinch.isBeakDown() << '\n'
                     << "Upside Down: " << myFinch.isFinchUpsideDown() << '\n'
                     << "Left Wheel Down: " << myFinch.isLeftWingDown() << '\n'
                     << "Right Wheel Down: " << myFinch.isRightWingDown() << '\n';
                break;
            case 'L':
                lightSense = myFinch.getLightSensors();
                cout << "Left: " << lightSense[0]
                     << ", Right: " << lightSense[1] << '\n';
                delete [] lightSense;
                lightSense = 0;
                break;
            case 'I':
                obstacles = myFinch.getObstacleSensors();
                cout << "Left: " << obstacles[0]
                     << ", Right: " << obstacles[1] << '\n';
                delete [] obstacles;
                obstacles = 0;
                break;
            case 'T':
                temperature = myFinch.getTemperature();
                cout << temperature << " Celcius\n";
                break;
            case 'S':
                shaken = myFinch.wasShaken();
                cout << "Shaken state: " << shaken << '\n';
                break;
            case 't':
                tapped = myFinch.wasTapped();
                cout << "Tapped state: " << tapped << '\n';
                break;
            case 'B':
                cout << "Enter frequency in Hz: ";
                cin >> frequency;
                cin.ignore(10000, '\n');
                myFinch.noteOn(frequency);
                break;
            case 'b':
                myFinch.noteOff();
                break;
            case 'M':
                cout << "Enter left wheel speed (-255 to 255): ";
                cin >> leftSpeed;
                cout << "Enter right wheel speed (-255 to 255): ";
                cin >> rightSpeed;
                cin.ignore(10000, '\n');
                myFinch.setMotors(leftSpeed, rightSpeed);
                break;
            case 'X':
                myFinch.setMotors(0, 0);
                break;
            case 'O':
                cout << "Enter red color value (0-255): ";
                cin >> rLED;
                cout << "Enter green color value (0-255): ";
                cin >> gLED;
                cout << "Enter blue color value (0-255): ";
                cin >> bLED;
                cin.ignore(10000, '\n');
                myFinch.setLED(rLED, gLED, bLED);
                break;
            case 'c':
                cout << myFinch.counter() << '\n';
                break;
            case 'm':
                printMenu();
                break;
            default:
                break;
        }
    }
    return 0;
}
