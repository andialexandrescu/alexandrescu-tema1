#include <Reservation.h>
#include <Apartment.h>
#include <iostream>
#include <vector>

Reservation::Reservation() {
    apartment_id = 0;
    no_underage_guests = -1;
    card_number = 0;
    card_holder_name = "None";
    cvv = 0;
    sent_payment = false;
    l_apts.clear();
}

Reservation::Reservation(int apartment_id, int no_underage_guests, int card_number, const std::string &card_holder_name, int cvv, bool sent_payment) {
    this->apartment_id = apartment_id;
    this->no_underage_guests = no_underage_guests;
    this->card_number = card_number;
    this->card_holder_name = card_holder_name;
    this->cvv = cvv;
    this->sent_payment = sent_payment;
}

Reservation::~Reservation() {
    if(!this->l_apts.empty())
    {
        this->l_apts.clear();
    }
}

Reservation &Reservation::operator+=(const Apartment &apt) {
    l_apts.push_back(apt);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Reservation &r) {
    for(const Apartment &apt: r.l_apts)
    {
        out<<apt<<std::endl;
    }
    return out;
}

void Reservation::mainmenu(const Reservation &r) {
    std::cout<<"You are now in the searching main menu section. You will be able to search for apartments based on location, number of rooms and price."<<std::endl;
    std::cout<<"Please enter the search destination formatted as <City, Country>, the search engine will filter results containing at least one of these parameters.";
    std::cout<<"Search destinations: "<<std::endl;
    std::string aux_city, aux_country;
    std::cout<<"City: ";
    std::cin>>aux_city;
    std::cout<<"Country: ";
    std::cin>>aux_country;
    std::cout<<"Search chosen number of rooms: "<<std::endl;
    int no_rooms;
    std::cin>>no_rooms;
    std::cout<<"Search maximum price range: "<<std::endl;
    int p;
    std::cin>>p;
    for(const Apartment& apt : r.l_apts)
    {
        if(apt.searchCriteria(apt, aux_city, aux_country, no_rooms, p))
        {
            std::cout<<apt;
        }
    }
}



