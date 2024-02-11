#ifndef DEVICEMOUSE_H
#define DEVICEMOUSE_H

#include <iostream>
#include "devicebaseclass.h"

using namespace std;

class DeviceMouse : public DeviceBaseClass
{
public:
    DeviceMouse();
    void setPrimaryButton();
    short getPrimaryButton();
private:
    short primaryButton;
    short minPrimaryButton, maxPrimaryButton;
};

#endif // DEVICEMOUSE_H
