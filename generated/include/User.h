#ifndef OOP_USER_H
#define OOP_USER_H

#include <string>
#include <cstring>
#include "Card.h"

class User{
private:
    // a good practice for creating users would be limiting the maximum length of an username and password, therefore these variables will be allocated dynamically as type char, compared to the rest which are of type string
    char *username;
    char *password;
    char *email;
    std::string first_name;
    std::string last_name;
    int id_number;
    std::string id_residence;
    std::string phone_number;
    int user_choice;
    Card default_card_details;
public:
    // overloaded constructors:
    User();
    //User(const char *client, const char *pswd);
    //User(const char *client, const char *pswd, const char *contact_email);
    User(const char *client, const char *pswd, const char *contact_email, const std::string& fname, const std::string& lname, int id, const std::string& residence, const std::string& phone);
    //User(const User &other_obj); // copy constructor
    ~User();// destructor

    // operators:
    User& operator=(const User &obj); // operator=
    friend std::ostream& operator<<(std::ostream& out, const User &obj); // operator<<
    friend std::istream& operator>>(std::istream& in, User &obj); // operator>>

    // setters
    //void setUsername(char *username);
    //void setPassword(char *password);
    //void setEmail(char *email);
    //void setFirstName(std::string first_name);
    //void setLastName(std::string last_name);
    //void setIDNUmber(int id_number);
    //void setIDResidence(std::string id_residence);
    //void setPhoneNumber(std::string phone_number);

    // getters
    //const char *getUsername() const;
    //const char *getPassword() const;
    //const char *getEmail() const;
    //std::string getFirstName() const;
    //std::string getLastName() const;
    //int getIDNumber() const;
    //std::string getIDResidence() const;
    //std::string getPhoneNumber() const;

    // functions implemented
    //void createAccountProcess(); // choice between tenant and host
    //void changeAccountDetails();
    //void checkSpellingErrors();
    void loginMenu(User &user2);
};

#endif //OOP_USER_H
