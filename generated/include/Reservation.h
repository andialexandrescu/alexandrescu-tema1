#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

#include <string>
#include "Card.h"
#include "User.h"

class Reservation{
private:
    /* std::string host_username;
    std::string tenant_username;
    std::string username;
    in order to get around having so many variables that need to be connected together in case of a money transfer, the solution is to have both the host and tenant be declared as variables of type User, since they share common attributes*/
    User host_user;
    User tenant_user;
    /* the same goes for all of the card details: one missing detail is that when a processing payment function will be implemented, the host's card cvv should not be needed
    int tenant_card_number;
    std::string tenant_card_holder_name;
    int tenant_card_cvv;
    int host_card_number;
    int host_card_holder_name; */
    Card tenant_card_details;
    Card host_card_details;
    bool sent_payment;
    // i consider that the card details of any type of user should be connected to their account, therefore i have the posibility to implement a function which allows a tenant to pay with their default card or another card
public:
    // constructor
    Reservation(const User &host_user, const User &tenant_user);
    // destructor


    // what needs to be implemented
    // processPayment
    // verifyPaymentStatus
    // beginTransferProcess
    // chooseCard (the default one or another one)
};

#endif //OOP_RESERVATION_H
