#include "ParallexFeedback360.hpp"

ParallexFeedback360::ParallexFeedback360(const uint8_t control_pin) :
    control_pin(control_pin) {
    // if (wiringPiSetup() != -1) {
    //     pinMode(this->control_pin, PWM_OUTPUT);
    //     pwmSetClock(1920);
    //     pwmSetRange();
    // }
}

ParallexFeedback360::~ParallexFeedback360() {
    // pinMode(this->control_pin, PM_OFF);
}

bool ParallexFeedback360::MoveClockwise(int speed) {
    return false;
}


bool ParallexFeedback360::MoveCounterClockwise(int speed) {
    return false;
}

void ParallexFeedback360::Stop(void) {
    return;
}

bool ParallexFeedback360::IsMoving(void) {
    return false;
}