#pragma once

#include "IServo.hpp"

#include <stdint.h>
#include <wiringPi.h>

#define WIRINGPI_INVALID_PARAMETER_ERROR -1
#define WIRINGPI_SUCCESS 0

class ParallexFeedback360 : public IServo { 
public:
    ParallexFeedback360(const uint8_t control_pin);
    ~ParallexFeedback360();
    
    bool MoveClockwise(int speed) override;
    bool MoveCounterClockwise(int speed) override;
    void Stop(void) override;
private:
    const int control_pin;
};
