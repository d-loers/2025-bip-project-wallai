#pragma once

class IServo {
public:
    virtual ~IServo() = default;
    virtual bool MoveClockwise(int speed);
    virtual bool MoveClockwise(int angle);
    virtual bool MoveCounterClockwise(int speed);
    virtual bool MoveCounterClockwise(int angle);
    virtual void Stop(void);
    virtual bool GetAngle(void);
    virtual bool SetAngle(int angle);
    virtual bool IsMoving(void);
    virtual bool IsAtPosition(int angle);
};