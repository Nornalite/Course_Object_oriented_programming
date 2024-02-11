#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad()
{
    deviceID = 0;
    minTouchPadSensitivity = 1;
    maxTouchPadSensitivity = 5;
    touchPadSensitivity = (minTouchPadSensitivity + maxTouchPadSensitivity) / 2;
    strncpy(deviceName, "Touch Pad", sizeof(deviceName) - 1);
}

void DeviceTouchPad::setTouchPadSensitivity()
{
    //  Asks user for input, sets the touchpad's sensitivity to a value between 1 and 5
    cout << "Set Touch Pad Sensitivity (" << minTouchPadSensitivity << " to " << maxTouchPadSensitivity << "): ";
    short input;
    cin >> input;
    while (input < minTouchPadSensitivity || input > maxTouchPadSensitivity) {
        cout << "Invalid input, try again." << endl;
        cin >> input;
    };
    touchPadSensitivity = input;
}

short DeviceTouchPad::getTouchPadSensitivity()
{
    return touchPadSensitivity;
}
