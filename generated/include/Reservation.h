#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <vector>
#include <iostream>
#include "Apartment.h"

class Reservation { // reservation also acts as a submenu for choosing an apartment
private:
    int apartment_id;
    int no_underage_guests;
    int card_number;
    std::string card_holder_name;
    int cvv;
    bool sent_payment;
    std::vector<Apartment> l_apts;
public:
    Reservation();
    Reservation(int apartment_id, int no_underage_guests, int card_number, const std::string &card_holder_name, int cvv, bool sent_payment);
    ~Reservation();
    Reservation& operator+=(const Apartment &apt); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const Reservation &r);// operator overloading as friend/ non-member functions
    void mainmenu(const Reservation &r);
};

#endif //OOP_RESERVATION_H
