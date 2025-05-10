#pragma once  
#include <stdexcept>  
#include <string>  

class insufficient_fuel_error : public std::logic_error  
{  
public:  
    insufficient_fuel_error(const std::string& message) : std::logic_error(message) {}

};
