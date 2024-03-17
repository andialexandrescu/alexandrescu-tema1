#include <Reservation.h>
#include <Apartment.h>
#include <iostream>
#include <vector>

Reservation &Reservation::operator+=(const Apartment &apt) {
    apartments.push_back(apt);
    return *this;
}

void Reservation::displayApartments() const {
    for (const auto& apt : apartments) {
        std::cout << apt << std::endl;
    }
}
