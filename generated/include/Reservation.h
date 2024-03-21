#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <vector>
#include <iostream>
#include "Apartment.h"

class Reservation { // reservation also acts as a submenu for choosing an apartment
private:
    int card_number;
    std::string card_holder_name;
    int cvv;
    std::vector<Apartment> l_apts;
public:
    Reservation();
    Reservation(int card_number, const std::string &card_holder_name, int cvv);
    ~Reservation();
    Reservation& operator+=(const Apartment &apt); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const Reservation &r);// operator overloading as friend/ non-member functions
    friend std::istream& operator>>(std::istream& in, Reservation &r);
    void searchMenu(const Reservation &r);
    int convertDate(int year, int &date);
    void proceedTransaction(const Reservation &r, const Apartment &apt);
    void computeTransaction(const Apartment &apt, int start_date, int end_date);
};

#endif //OOP_RESERVATION_H
