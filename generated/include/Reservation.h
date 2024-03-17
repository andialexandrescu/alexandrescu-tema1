#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <vector>
#include <iostream>
#include "Apartment.h"

class Reservation {
private:
    std::vector<Apartment> apartments;
public:
    Reservation& operator+=(const Apartment &apt);
    void displayApartments() const;
};

#endif //OOP_RESERVATION_H
