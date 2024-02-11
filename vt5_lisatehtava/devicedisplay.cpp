#include "devicedisplay.h"

DeviceDisplay::DeviceDisplay()
{
    deviceID = 0;
    minDisplayResolution = 1;
    maxDisplayResolution = 10;
    displayResolution = (minDisplayResolution + maxDisplayResolution) / 2;
    strncpy(deviceName, "Display", sizeof(deviceName) - 1);
}

void DeviceDisplay::setDisplayResolution()
{
    //  Asks user for input, sets the display's resolution to a value between 1 and 10
    cout << "Set Display Resolution (" << minDisplayResolution << " to " << maxDisplayResolution << "): ";
    short input;
    cin >> input;
    while (input < minDisplayResolution || input > maxDisplayResolution) {
        cout << input << "Invalid input, try again: ";
        cin >> input;
    };
    displayResolution = input;
}

short DeviceDisplay::getDisplayResolution()
{
    return displayResolution;
}
