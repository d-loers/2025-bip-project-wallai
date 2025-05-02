#pragma once

#include "IServo.hpp"

#include <stdint.h>
// #include <WiringPi.h>

class ParallexFeedback360 : public IServo { 
public:
    ParallexFeedback360(const uint8_t control_pin);
    ~ParallexFeedback360();
    bool MoveClockwise(int speed) override;
    bool MoveCounterClockwise(int speed) override;
    void Stop(void) override;
    bool IsMoving(void) override;
private:
    int control_pin;
};
