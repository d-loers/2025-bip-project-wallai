#include "ParallexFeedback360.hpp"

ParallexFeedback360::ParallexFeedback360(const uint8_t control_pin) :
    control_pin(control_pin) {
    if (wiringPiSetupPinType(WPIPinType::WPI_PIN_PHYS) == WIRINGPI_INVALID_PARAMETER_ERROR) {return;}
    pwmSetRange(2000);
    pwmSetClock(192); 
    pwmWrite(this->control_pin, 1280); // Set to 0 to prevent unexpected behavior on startup
    pinMode(this->control_pin, PWM_MS_OUTPUT); 
}

ParallexFeedback360::~ParallexFeedback360() {
    pwmWrite(this->control_pin, 0);
    pinMode(this->control_pin, PM_OFF);
}

bool ParallexFeedback360::MoveClockwise(int speed) {
    return false;
} 

bool ParallexFeedback360::MoveCounterClockwise(int speed) {
    return false;
}

void ParallexFeedback360::Stop(void) {
    pwmWrite(this->control_pin, 0); 
    return;
}