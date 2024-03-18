#ifndef OOP_APARTMENT_H // if not defined
#define OOP_APARTMENT_H

#include <string>
#include <vector>

class Apartment{
private:
    std::string apartment_id;
    std::string location;
    std::string type;
    std::string short_description;
    int no_rooms;
    int price_per_night;
public:
    Apartment();
    Apartment(std::string apt_id, std::string l, std::string t, std::string desc, int k_rooms = 0, int p = 0);// constructor definit explicit
    friend std::ostream& operator<<(std::ostream& out, const Apartment &obj);
    friend std::istream& operator>>(std::istream& in, Apartment &obj);
    // these two functions are working together
    std::string CaesarCipherEncryption(std::string &host_user, int offset);
    void generateApartmentID(Apartment &obj); // one day i might to have to rewrite this, so that the list of parameters contains User &host_user as well
    bool searchCriteria(const Apartment &obj, std::string aux_city, std::string aux_country, int no_rooms, int p) const;
};

#endif //OOP_APARTMENT_H end if not defined
