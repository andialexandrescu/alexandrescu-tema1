#ifndef OOP_APARTMENT_H // if not defined
#define OOP_APARTMENT_H

#include <string>

using namespace std;

class Apartment{
private:
    std::string location;
    std::string type;
    std::string short_description;
    int no_rooms;
    int price_per_night;
    //vector<string> arr_amenities;
    //vector<string> arr_sleeping_layout;
public:
    Apartment(std::string l = "-", std::string t = "-", std::string desc = "-", int k_rooms = 0, int p = 0);// constructor definit explicit
    ~Apartment();
    void printApartment();
    int getApartmentDetails();
};

#endif //OOP_APARTMENT_H end if not defined
