#pragma once

class IServo {
public:
    virtual ~IServo() = default;
    virtual bool MoveClockwise(int speed);
    virtual bool MoveCounterClockwise(int speed);
    virtual void Stop(void);
    virtual bool IsMoving(void);
};