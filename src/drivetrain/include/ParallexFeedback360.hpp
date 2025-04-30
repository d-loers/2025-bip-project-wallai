#pragma once

#include "IServo.hpp"

#include <stdint.h>

class ParallexFeedback360 : public IServo { 
public:
    ParallexFeedback360(const uint8_t feedback_pin, const uint8_t control_pin);
    ~ParallexFeedback360();
    bool MoveClockwise(int speed);
    bool MoveClockwise(int angle);
    bool MoveCounterClockwise(int speed);
    bool MoveCounterClockwise(int angle);
    void Stop(void);
    bool GetAngle(void);
    bool SetAngle(int angle);
    bool IsMoving(void);
    bool IsAtPosition(int angle);
private:
    int feedback_pin;
    int control_pin;
};
