#include "ParallexFeedback360.hpp"

/// @brief Configures and enable the specified pin as PWM output to control the Parallex Feedback360.
/// @param control_pin Physical number of the GPIO pin.
ParallexFeedback360::ParallexFeedback360(const uint8_t control_pin) :
    control_pin(control_pin) {
    if (wiringPiSetupPinType(WPIPinType::WPI_PIN_PHYS) == WIRINGPI_INVALID_PARAMETER_ERROR) {return;}
    pwmSetRange(2000);
    pwmSetClock(192); 
    pwmWrite(this->control_pin, 0); // Set to 0 to prevent unexpected behavior on startup
    pinMode(this->control_pin, PWM_MS_OUTPUT); 
}

/// @brief Sets the dutycycle to 0, disables and release the GPIO pin.
ParallexFeedback360::~ParallexFeedback360() {
    pwmWrite(this->control_pin, 0);
    pinMode(this->control_pin, PM_OFF);
}

/// @brief Sets the clockwise speed of the servo motor.
/// @param speed A value from 0 to 200, 0 being the slowest and 200 being the fastest.
/// @return False if the input was outside of the allowed range otherwise, true.
bool ParallexFeedback360::MoveClockwise(uint8_t speed) {
    bool return_value = false;

    if (IsValueInRange(speed)) {
        pwmWrite(this->control_pin, (this->min_clockwise_speed_value + speed));
        return_value = true;
    }

    return return_value;
} 

/// @brief Sets the counterclockwise speed of the servo motor.
/// @param speed A value from 0 to 200, 0 being the slowest and 200 being the fastest.
/// @return False if the input was outside of the allowed range otherwise, true.
bool ParallexFeedback360::MoveCounterClockwise(uint8_t speed) {
    bool return_value = false;

    if (IsValueInRange(speed)) {
        pwmWrite(this->control_pin, (this->min_counterclockwise_speed_value + speed));
        return_value = true;
    }

    return return_value;
}

/// @brief Stops the servo motor from rotating. 
void ParallexFeedback360::Stop(void) {
    pwmWrite(this->control_pin, 0); 
    return;
}

/// @brief Checks wether the given value is within 0 and 200.
/// @param value The variable containing the value that needs to be checked.
/// @return True if the value is within the allowed range otherwise, false.
bool ParallexFeedback360::IsValueInRange(uint8_t value) {
    return (value >= this->min_value_threshold && value <= this->max_value_threshold);
}