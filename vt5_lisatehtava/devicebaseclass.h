#ifndef DEVICEBASECLASS_H
#define DEVICEBASECLASS_H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class DeviceBaseClass
{
public:
    DeviceBaseClass();
    void setDeviceID();
    short getDeviceID();
protected:
    short deviceID;
    short minDeviceID, maxDeviceID;
    char deviceName[20];
};

#endif // DEVICEBASECLASS_H
