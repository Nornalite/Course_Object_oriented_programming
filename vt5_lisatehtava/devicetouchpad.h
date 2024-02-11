#ifndef DEVICETOUCHPAD_H
#define DEVICETOUCHPAD_H

#include <iostream>
#include "devicebaseclass.h"

using namespace std;

class DeviceTouchPad : public DeviceBaseClass
{
public:
    DeviceTouchPad();
    void setTouchPadSensitivity();
    short getTouchPadSensitivity();
private:
    short touchPadSensitivity;
    short minTouchPadSensitivity, maxTouchPadSensitivity;
};

#endif // DEVICETOUCHPAD_H
