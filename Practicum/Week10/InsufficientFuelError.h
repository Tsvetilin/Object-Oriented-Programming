#ifndef _INSUFFICIENTFUELERROR_H
#define _INSUFFICIENTFUELERROR_H

#include <stdexcept>

class insufficient_fuel_error : public std::logic_error {
public:
    insufficient_fuel_error(const char* message) : std::logic_error(message) {}
};
#endif // !_INSUFFICIENTFUELERROR_H