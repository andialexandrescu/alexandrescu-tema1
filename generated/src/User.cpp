#include <User.h>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

User::User() {
    this->username = new char[strlen("Undefined")+1];
    strcpy(this->username,"Undefined");
    password = "Undefined";
    email = "Undefined";
    first_name = "None";
    last_name = "None";
    id_number = 0;
    id_residence = "None";
    phone_number = "None";
}

User::User(const char *client, const std::string &pswd, const std::string &contact_email, const std::string &fname, const std::string &lname, long long id, const std::string &residence, const std::string &phone)
        : password(pswd), email(contact_email), first_name(fname), last_name(lname), id_number(id), id_residence(residence), phone_number(phone) {
    this->username = new char[strlen(client)+1]; // null-terminator
    strcpy(this->username, client); // if i were to declare the variable in the private section of the class User as const char *username, strcpy wouldn't work at all
} // hybrid declaration

User::User(const User &other_obj) {
    this->username = new char[strlen(other_obj.username)+1];
    strcpy(this->username,other_obj.username);
    password = other_obj.password;
    email = other_obj.email;
    first_name = other_obj.first_name;
    last_name = other_obj.last_name;
    id_number = other_obj.id_number;
    id_residence = other_obj.id_residence;
    phone_number = other_obj.phone_number;
}

User::~User() {
    if(this->username != nullptr) // good practice!!!
    {
        delete []this->username;
        this->username = nullptr;
    }
}

User& User::operator=(const User &other_obj) { // function which returns a reference!!!
    if(this != &other_obj) // ensures that the copy assignment operator= does not modify the same object (prevents object self-assignment)
    {
        // since some variables are dinamically allocated, memory leaks should be avoided; the destructor code sequence
        if(this->username != nullptr)
        {
            delete []this->username;
            this->username = nullptr;
        }
        // allocating new memory for these variables; the copy constructor code sequence
        this->username = new char[strlen(other_obj.username)+1];
        strcpy(this->username,other_obj.username);
        // copying data members from the source obj to the current obj
        this->password = other_obj.password;
        this->email = other_obj.email;
        this->first_name = other_obj.first_name;
        this->last_name = other_obj.last_name;
        this->id_number = other_obj.id_number;
        this->id_residence = other_obj.id_residence;
        this->phone_number = other_obj.phone_number;
    }
    return *this; // the returning reference part
}

/**User &User::operator+=(const User &other_obj) {
    this->list_of_reservations_per_user.push_back(other_obj);
    return *this;
}**/

std::ostream &operator<<(std::ostream &out, const User &obj) {
    out<<std::endl<<"Username: @"<<obj.username<<std::endl;
    out<<"Password: "<<obj.password<<std::endl;
    out<<"E-mail: "<<obj.email<<std::endl;
    out<<"First Name: "<<obj.first_name<<std::endl;
    out<<"Last Name: "<<obj.last_name<<std::endl;
    out<<"ID Number: "<<obj.id_number<<std::endl;
    out<<"ID Residence: "<<obj.id_residence<<std::endl;
    out<<"Phone Number: ";
    if(obj.phone_number[0]!='+')
    {
        out<<"+";
    }
    out<<obj.phone_number;
    return out;
}

/**std::ostream &operator<<(std::ostream &out, const Reservation &obj) {
    for(User user: Reservation.obj)
    {
        out<<user<<std::endl;
    }
    return out;
}**/

std::istream &operator>>(std::istream &in, User &obj) {
    char client[11];
    std::cout<<"Username must contain 10 characters at most, otherwise your choice will be truncated, only the first 10 characters being your new username."<<std::endl;
    std::cout<<"Username: ";
    in.get(client, 11);
    if(obj.username != nullptr)
    {
        delete []obj.username;
        obj.username = nullptr;
    }
    obj.username = new char[strlen(client)+1];
    strcpy(obj.username, client); // now the username contains maximum 10 characters
    in.clear(); // otherwise the generated password is too long (in case of not meeting the criteria)
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer before a new line from input

    std::cout<<std::endl<<"Password must be a combination of at least 2 digits and 1 symbol. It should contain between 8 to 15 characters at most."<<std::endl;
    std::cout<<"Password: ";
    std::string pswd;
    in>>pswd; in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (obj.validatingChosenPassword(pswd))
    {
        obj.password = pswd;
    } else
    {
        std::cout<<std::endl<<"Invalid password, the password does not meet the specified criteria."<<std::endl;
        std::cout<<"Your password will be generated shortly."<<std::endl;
        obj.generateStrongPassword(obj);
    }

    std::cout<<"E-mail: ";
    in>>obj.email;
    std::cout<<"First Name: ";
    in>>obj.first_name;
    std::cout<<"Last Name: ";
    in>>obj.last_name;

    std::cout<<"ID Number must be an integer."<<std::endl;
    std::cout<<"ID Number: ";
    std::string id_no;
    do{
        in >> id_no;
        if (!obj.validatingIDNumber(id_no))
        {
            std::cout<<"Invalid ID number. Re-type it."<<std::endl;
        } else if(obj.validatingIDNumber(id_no) && id_no[0]!='0' && id_no[0]!='-' && id_no.length()<=13)// romanian ids are 13 digits long
        {
            obj.id_number = std::stoll(id_no); // convert to long long integer
        }
    } while(!obj.validatingIDNumber(id_no));
    std::cout<<"ID Residence: ";
    in>>obj.id_residence;
    std::cout<<"Phone Number: ";
    in>>obj.phone_number;
    return in;
}

void User::loginMenu(User &user) {
    std::string user2, pswd2;
    std::cout<<"------- Log into your account -------"<<std::endl;
    std::cout<<"Enter you username: ";
    std::cin>>user2;
    if(user.username == user2)
    {
        std::cout<<"Enter your password: ";
        std::cin>>pswd2;
        if(user.password == pswd2)
        {
            std::cout<<std::endl<<"You are now logged in!";
        } else
        {
            std::cout<<std::endl<<"Incorrect password";
        }
    } else
    {
        std::cout<<std::endl<<"Incorrect username";
    }
}

bool User::validatingChosenPassword(std::string &pswd) {
    int s_counter = 0; // symbols
    int d_counter = 0; // digits
    for(char ch: pswd)
    {
        if(isdigit(ch))
        {
            d_counter++;
        } else if(!isalnum(ch))
        {
            s_counter++;
        }
    }
    return (s_counter>=1 && d_counter>=2);
}

void User::generateStrongPassword(User &user) {
    user.password = "";
    std::string pswd;
    std::string alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned long long l = alphanum.length();
    int max_length = 15;
    srand(time(0));// seed for generating numbers
    do{
        pswd = "";
        for(int i = 0; i < max_length; i++)
        {
            pswd += alphanum[rand()%l];
        }
    } while(!user.validatingChosenPassword(pswd));
    user.password = pswd;
    std::cout<<std::endl<<"Your new password has been generated. Make sure to remember it: "<<user.password<<std::endl;
}

bool User::validatingIDNumber(std::string &id_no) {
    return (!id_no.empty() && std::all_of(id_no.begin(), id_no.end(), ::isdigit));
}
