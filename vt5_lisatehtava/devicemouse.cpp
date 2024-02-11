#include "devicemouse.h"

DeviceMouse::DeviceMouse()
{
    deviceID = 0;
    minPrimaryButton = 1;
    maxPrimaryButton = 2;
    primaryButton = (minPrimaryButton + maxPrimaryButton) / 2;
    strncpy(deviceName, "Mouse", sizeof(deviceName) - 1);
}

void DeviceMouse::setPrimaryButton()
{
    //  Asks user for input, sets the mouse's primary button to 1 or 2
    cout << "Set Primary Button (" << minPrimaryButton << " to " << maxPrimaryButton << "): ";
    short input;
    cin >> input;
    while (input < minPrimaryButton || input > maxPrimaryButton) {
        cout << "Invalid input, try again." << endl;
        cin >> input;
    };
    primaryButton = input;
}

short DeviceMouse::getPrimaryButton()
{
    return primaryButton;
}
