#include "ButtonTimer.h"

ButtonTimer::ButtonTimer(unsigned long timeOut)
{
    this->timeOut = timeOut;
}

void ButtonTimer::startButtonTimer(unsigned long duration)
{
    this->nextButtonTimeout = millis() + duration;
}

bool ButtonTimer::buttonTimerHasExpired()
{
    return (millis() > this->nextButtonTimeout) ? true : false;
}

bool ButtonTimer::isSwitchOn(int btn)
{
    int btnState = digitalRead(btn);
    if (btnState != oldBtnState)
    {
        oldBtnState = btnState;
        startButtonTimer(this->timeOut);
    }
    return ((buttonTimerHasExpired()) && (btnState)) ? true : false;
}