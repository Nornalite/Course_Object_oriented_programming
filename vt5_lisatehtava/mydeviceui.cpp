#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI()
{
    pObjectDeviceMouse = new DeviceMouse;
    pObjectDeviceTouchPad = new DeviceTouchPad;
    pObjectDeviceDisplay = new DeviceDisplay;
}

MyDeviceUI::~MyDeviceUI()
{
    delete pObjectDeviceMouse;
    delete pObjectDeviceTouchPad;
    delete pObjectDeviceDisplay;
}

void MyDeviceUI::uiShowMenu()
{
    bool userFinished = false;
    do {
        cout << "DEVICE MENU" << endl
             << "===========" << endl
             << "1. Set Mouse Information" << endl
             << "2. Set Touch Pad Information" << endl
             << "3. Set Display Information" << endl
             << "4. Show Devices Information" << endl
             << "5. Finish" << endl << endl
             << "Choose: ";

        short input = 0;
        cin >> input;
        switch (input) {
        case 1:
            uiSetMouseInformation();
            break;
        case 2:
            uiSetTouchPadInformation();
            break;
        case 3:
            uiSetDisplayInformation();
            break;
        case 4:
            uiShowDeviceInformation();
            break;
        case 5:
            userFinished = true;
            break;
        default:
            userFinished = true;
            break;
        };
    }
    while (!userFinished);
}

void MyDeviceUI::uiSetMouseInformation()
{
    cout << "SET MOUSE INFORMATION" << endl
         << "=====================" << endl;
    pObjectDeviceMouse ->setDeviceID();
    pObjectDeviceMouse->setPrimaryButton();
    cout << endl;
}

void MyDeviceUI::uiSetTouchPadInformation()
{
    cout << "SET TOUCH PAD INFORMATION" << endl
         << "=========================" << endl;
    pObjectDeviceTouchPad ->setDeviceID();
    pObjectDeviceTouchPad->setTouchPadSensitivity();
    cout << endl;
}

void MyDeviceUI::uiSetDisplayInformation()
{
    // The "Set Device Display ID" and "Set Device Display Resolution" texts are located in the setter functions,
    // and include device-specific min and max values to let the user know what's a valid answer
    cout << "SET DISPLAY INFORMATION" << endl
         << "=======================" << endl;
    pObjectDeviceDisplay->setDeviceID();
    pObjectDeviceDisplay->setDisplayResolution();
    cout << endl;
}

void MyDeviceUI::uiShowDeviceInformation()
{
    cout << "SHOW DEVICE INFORMATION" << endl
         << "=======================" << endl
         << "Mouse ID: " << pObjectDeviceMouse->getDeviceID() << endl
         << "Mouse Primary Button: " << pObjectDeviceMouse->getPrimaryButton() << endl
         << "Touch Pad ID: " << pObjectDeviceTouchPad->getDeviceID() << endl
         << "Touch Pad Sensitivity: " << pObjectDeviceTouchPad->getTouchPadSensitivity() << endl
         << "Display ID: " << pObjectDeviceDisplay->getDeviceID() << endl
         << "Display Resolution: " << pObjectDeviceDisplay->getDisplayResolution() << endl << endl;
}
