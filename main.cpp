#include "AirBnB.h"
#include "Accommodation.h"
#include "Location.h"

#include<stdexcept>

int main() {
    Location loc1(10, 20);
    Location loc2(30, 40);
    Location loc3(15, 25);

    Accommodation a1(1, "Cozy Apartment", Type::Apartment, loc1, 80.0, true, 0);
    Accommodation a2(2, "Luxury Villa", Type::Villa, loc2, 150.0, true, 0);
    Accommodation a3(3, "Downtown Hotel", Type::Hotel, loc3, 120.0, true, 0);

    AirBnB platform;
    platform.addAccommodation(a1);
    platform.addAccommodation(a2);
    platform.addAccommodation(a3);

    try {
        platform.reserveById(2, 3);
        platform.reserveById(1, 2);
    }
    catch (const std::exception& e) {
        std::cout << "Reservation error: " << e.what() << std::endl;
    }

    std::cout << "Total revenue: " << platform.getTotalPriceForAllReservations() << " BGN" << std::endl;

    Accommodation nearest = platform.findNearestAccommodation(12, 22);
    std::cout << "Nearest accommodation: " << nearest.getName() << std::endl;

    try {
        platform.cancelReservationById(2);
    }
    catch (const std::exception& e) {
        std::cout << "Cancellation error: " << e.what() << std::endl;
    }

    try {
        platform.removeAccommodationById(3);
    }
    catch (const std::exception& e) {
        std::cout << "Remove error: " << e.what() << std::endl;
    }

	std::cout << "Final total revenue: " << platform.getTotalPriceForAllReservations() << " BGN" << std::endl;

    return 0;
}