#pragma once

#include <stdint.h>

class IServo {
public:
    virtual ~IServo() = default;
    virtual bool MoveClockwise(uint8_t speed) = 0;
    virtual bool MoveCounterClockwise(uint8_t speed) = 0;
    virtual void Stop(void) = 0;
};