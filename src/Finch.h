/*
 * File:   Finch.h
 * Author: Administrator
 *
 * Created on May 23, 2011, 5:30 PM
 */

#ifndef FINCH_H
#define FINCH_H

class Finch {
public:
    Finch();
    virtual ~Finch();

    // Call the following function to make sure that the object
    // object is ready for use (i.e., a Finch was found on the
    // USB chain, and we connected to it successfully).
    bool isInitialized() {
        return this->initialized;
    }

    int connect();
    int disConnect();
    int setLED(int red, int green, int blue);
    int setMotors(int leftWheelSpeed, int rightWheelSpeed);
    int setMotors(int leftWheelSpeed, int rightWheelSpeed, int duration);
    int noteOn(int frequency);
    int noteOn(int frequency, int duration);
    int noteOff();
    double getTemperature();
    double* getAccelerations();
    int* getLightSensors();
    int* getObstacleSensors();
    int wasTapped();
    int wasShaken();
    int isObstacleLeftSide();
    int isObstacleRightSide();
    int getLeftLightSensor();
    int getRightLightSensor();
    double getXAcceleration();
    double getYAcceleration();
    double getZAcceleration();
    int isBeakUp();
    int isBeakDown();
    int isFinchLevel();
    int isFinchUpsideDown();
    int isRightWingDown();
    int isLeftWingDown();
    int counter();
    void keepAlive();
    int finchRead(unsigned char bufToWrite[], unsigned char bufRead[]);
    int finchWrite(unsigned char bufToWrite[]);
    static void* keepAliveEntryPoint(void * pThis) {
        Finch * pthX = static_cast<Finch*>(pThis);   // cast from void to Finch object
        pthX->keepAlive();           // now call the true entry-point-function
        return 0;          // the thread exit code
    }

private:
    volatile bool initialized;
    struct Impl;
    Impl* pimpl;

    // This class is not copy-safe at present.
private:
    Finch(const Finch&);
    Finch& operator=(const Finch&);
};

#endif  /* FINCH_H */

