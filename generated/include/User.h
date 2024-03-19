#ifndef OOP_USER_H
#define OOP_USER_H

#include <string>
#include <cstring>
#include <list>
#include "Reservation.h"

class User{
private:
    char *username; // academic example since otherwise the destructor would've been useless
    // usage: regardless of how many characters are from input, the username will only contain the first 10
    std::string password;
    std::string email;
    std::string first_name;
    std::string last_name;
    long long id_number;
    std::string id_residence;
    std::string phone_number;
    std::list<Reservation> list_of_reserv_per_user;
public:
    // overloaded constructors:
    User(); // init constructor
    User(const char *client, const std::string &pswd, const std::string &contact_email, const std::string &fname, const std::string &lname, long long id, const std::string &residence, const std::string &phone);
    User(const User &other_obj); // copy constructor
    ~User();// destructor

    // operators:
    User& operator=(const User &obj); // operator=
    User& operator+=(const Reservation &obj); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const User &obj); // operator<<
    friend std::istream& operator>>(std::istream& in, User &obj); // operator>>
    // operator overloading as friend/ non-member functions

    void loginMenu(User &user);
    void generateStrongPassword(User &user);
    bool validatingChosenPassword(std::string &pswd);
    bool validatingIDNumber(std::string &id_no);
};

#endif //OOP_USER_H