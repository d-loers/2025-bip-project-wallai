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
    
    bool MoveClockwise(uint8_t speed) override;
    bool MoveCounterClockwise(uint8_t speed) override;
    void Stop(void) override;
private:
    const int control_pin;
    const int min_value_threshold = 0;
    const int max_value_threshold = 200;
    const int min_clockwise_speed_value = 128;
    const int min_counterclockwise_speed_value = 152;

    bool IsValueInRange(uint8_t value);
};
