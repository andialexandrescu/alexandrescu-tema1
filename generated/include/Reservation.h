#ifndef OOP_RESERVATION_H
#define OOP_RESERVATION_H

class Reservation{
private:
    std::string host_username;
    std::string tenant_username;
    int tenant_card_number;
    int tenant_card_holder_name;
    int tenant_card_cvv;
    bool sent_payment;
    int host_card_number;
    int host_card_holder_name;
    bool received_payment;

};

#endif //OOP_RESERVATION_H
