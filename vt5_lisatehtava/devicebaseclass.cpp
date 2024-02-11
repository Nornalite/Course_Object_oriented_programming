#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass()
{
    minDeviceID = 0;
    maxDeviceID = 9999;
}

void DeviceBaseClass::setDeviceID()
{
    //  Asks user for input, sets the touchpad's sensitivity to a value between 1 and 5
    cout << "Set " << deviceName << " ID (" << minDeviceID << " to " << maxDeviceID << "): ";
    short input = 0;
    cin >> input;
    while (input < minDeviceID || input > maxDeviceID) {
        if (!cin) {
            cin.clear();
        }
        cout << "Invalid input, try again." << endl;
        cin >> input;
    };
    deviceID = input;
}

short DeviceBaseClass::getDeviceID()
{
    return deviceID;
}
