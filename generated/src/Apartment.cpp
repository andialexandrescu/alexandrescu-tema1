#include <Apartment.h>
#include <string>
#include <iostream>

Apartment::Apartment(std::string l, std::string t, std::string desc, int k_rooms, int p): location(l), type(t), short_description(desc), no_rooms(k_rooms), price_per_night(p) {}

void Apartment::printApartment() {
    std::cout<<"Location: "<<location<<endl;
    std::cout<<"Type of apartment: "<<type<<endl;
    std::cout<<"Description: "<<short_description<<endl;
    std::cout<<"Number of rooms: "<<no_rooms<<endl;
    std::cout<<"Price/ night: "<<price_per_night<<endl;
}

Apartment::~Apartment() {

}

int Apartment::getApartmentDetails() { // getter
    return location, type, short_description, no_rooms, price_per_night;
}

