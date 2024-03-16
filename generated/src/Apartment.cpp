#include <Apartment.h>
#include <string>
#include <iostream>

//variant1: initialization list - better performance
Apartment::Apartment(std::string l, std::string t, std::string desc, int k_rooms, int p): location(l), type(t), short_description(desc), no_rooms(k_rooms), price_per_night(p) {}
//variant2: using pointers
/*Apartment::Apartment(std::string location, std::string type, std::string short_description, int no_rooms, int price_per_night)
{
    this->location = location;
    this->type = type;
    this->short_description = short_description;
    this->no_rooms = no_rooms;
    this->price_per_night = price_per_night;
}*/

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

