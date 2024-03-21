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
    int no_guests;
    int price_per_individual;
    std::vector<int> reservation_status; // a vector of tuples to track the days on which a certain apartment is already booked
public:
    Apartment();
    Apartment(std::string apartment_id, std::string location, std::string type, std::string description, int no_rooms, int no_guests, int price_per_individual);// constructor definit explicit
    ~Apartment();
    friend std::ostream& operator<<(std::ostream& out, const Apartment &obj);
    friend std::istream& operator>>(std::istream& in, Apartment &obj);
    std::string getApartmentID() const;
    int getNOGuests() const;
    int getPrice_perIndividual() const;
    // these two functions are working together (can be considered as one functionality)
    std::string CaesarCipherEncryption(std::string &host_user, int offset);
    void generateApartmentID(Apartment &obj); // one day i might to have to rewrite this, so that the list of parameters contains User &host_user as well
    // these three functions also work together (another functionality)
    bool searchCriteriaLocation(const Apartment &obj, std::string city, std::string country) const;
    bool searchCriteriaRooms(const Apartment &obj, int rooms, int guests, int &choice) const;
    bool searchCriteriaPrice(const Apartment &obj, int p) const;

    void bookApartment(int day_in_the_year);
    bool isBooked(int start_date, int end_date);
};

#endif //OOP_APARTMENT_H end if not defined
