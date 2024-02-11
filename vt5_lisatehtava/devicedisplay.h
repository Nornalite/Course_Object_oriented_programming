#ifndef DEVICEDISPLAY_H
#define DEVICEDISPLAY_H

#include <iostream>
#include "devicebaseclass.h"

using namespace std;

class DeviceDisplay : public DeviceBaseClass
{
public:
    DeviceDisplay();

    void setDisplayResolution();
    short getDisplayResolution();
private:
    short displayResolution;
    short minDisplayResolution, maxDisplayResolution;
};

#endif // DEVICEDISPLAY_H
