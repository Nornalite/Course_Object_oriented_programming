#ifndef MYDEVICEUI_H
#define MYDEVICEUI_H

#include "devicedisplay.h"
#include "devicemouse.h"
#include "devicetouchpad.h"

class MyDeviceUI
{
public:
    MyDeviceUI();
    ~MyDeviceUI();

    void uiShowMenu();
    void uiSetMouseInformation();
    void uiSetTouchPadInformation();
    void uiSetDisplayInformation();
    void uiShowDeviceInformation();
private:
    DeviceMouse *pObjectDeviceMouse;
    DeviceTouchPad *pObjectDeviceTouchPad;
    DeviceDisplay *pObjectDeviceDisplay;
};

#endif // MYDEVICEUI_H
