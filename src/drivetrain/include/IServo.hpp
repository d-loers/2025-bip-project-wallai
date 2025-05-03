#pragma once

class IServo {
public:
    virtual ~IServo() = default;
    virtual bool MoveClockwise(int speed) = 0;
    virtual bool MoveCounterClockwise(int speed) = 0;
    virtual void Stop(void) = 0;
};