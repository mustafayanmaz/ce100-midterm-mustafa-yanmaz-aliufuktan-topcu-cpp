#include "../header/vehicle.h"
#include <stdexcept>

using namespace Coruh::Vehicle;

double Vehicle::add(double a, double b) {
    return a + b;
}

double Vehicle::subtract(double a, double b) {
    return a - b;
}

double Vehicle::multiply(double a, double b) {
    return a * b;
}

double Vehicle::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}