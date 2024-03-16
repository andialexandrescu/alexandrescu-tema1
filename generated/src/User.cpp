#include <User.h>
#include <string>
#include <iostream>
#include <cstring>

User::User() {
    this->username = new char[strlen("Undefined")+1];
    strcpy(this->username,"Undefined");
    this->password = new char[strlen("Undefined")+1];
    strcpy(this->password,"Undefined");
    this->email = new char[strlen("Undefined")+1];
    strcpy(this->email,"Undefined");
    first_name = "None";
    last_name = "None";
    id_number = NULL;
    id_residence = "None";
    phone_number = "None";
}

/*User::User(const char *client, const char *pswd) {
    this->username = new char[strlen(client)+1];
    strcpy(this->username, client);
    this->password = new char[strlen(pswd)+1];
    strcpy(this->password, pswd);
}*/

/*User::User(const char *client, const char *pswd, const char *contact_email) {
    this->username = new char[strlen(client)+1];// null-terminator
    strcpy(this->username, client);
    this->password = new char[strlen(pswd)+1];
    strcpy(this->password, pswd);
    this->email = new char[strlen(contact_email)+1];
    strcpy(this->email, contact_email);
}*/

// you are prompted to addAccountDetails() only if you finished the createAccount() step, for this reason the uninitialized constructor will act in case the user wants to skip the first step of the registration process (this is why it doesnt contain all of the variables in the User class)
User::User(const char *client, const char *pswd, const char *contact_email, const std::string &fname, const std::string &lname, int id, const std::string &residence, const std::string &phone)
        : first_name(fname), last_name(lname), id_number(id), id_residence(residence), phone_number(phone) {
    this->username = new char[strlen(client)+1];// null-terminator
    strcpy(this->username, client);
    this->password = new char[strlen(pswd)+1];
    strcpy(this->password, pswd);
    this->email = new char[strlen(contact_email)+1];
    strcpy(this->email, contact_email);
} // hybrid declaration; unusual

/*User::User(const User &other_obj) {
    this->username = new char[strlen(other_obj.username)+1];
    strcpy(this->username,other_obj.username);
    this->password = new char[strlen(other_obj.password)+1];
    strcpy(this->password,other_obj.password);
    this->email = new char[strlen(other_obj.email)+1];
    strcpy(this->email,other_obj.email);
}*/

User::~User() {
    if(this->username != nullptr)// good practice!!!
    {
        delete []this->username;
        this->username = nullptr;
    }
    if(this->password != nullptr)
    {
        delete []this->password;
        this->password = nullptr;
    }
    if(this->email != nullptr)
    {
        delete []this->email;
        this->email = nullptr;
    }
}

User& User::operator=(const User &other_obj) { // function which returns a reference!!!
    if(this != &other_obj)// ensures that the copy assignment operator= does not modify the same object (prevents object self-assignment)
    {
        // since some variables are dinamically allocated, memory leaks should be avoided; the destructor code sequence
        if(this->username != nullptr)
        {
            delete []this->username;
            this->username = nullptr;
        }
        if(this->password != nullptr)
        {
            delete []this->password;
            this->password = nullptr;
        }
        if(this->email != nullptr)
        {
            delete []this->email;
            this->email = nullptr;
        }
        // allocating new memory for these variables; the copy constructor code sequence
        this->username = new char[strlen(other_obj.username)+1];
        strcpy(this->username,other_obj.username);
        this->password = new char[strlen(other_obj.password)+1];
        strcpy(this->password,other_obj.password);
        this->email = new char[strlen(other_obj.email)+1];
        strcpy(this->email,other_obj.email);
        // copying data members from the source obj to the current obj
        this->first_name = other_obj.first_name;
        this->last_name = other_obj.last_name;
        this->id_number = other_obj.id_number;
        this->id_residence = other_obj.id_residence;
        this->phone_number = other_obj.phone_number;
    }
    return *this;// the returning reference part
}

std::ostream &operator<<(std::ostream &out, const User &obj);
std::ostream &operator<<(std::ostream &out, const User &obj) {
    out<<"Username: "<<obj.username<<std::endl;
    out<<"Password: "<<obj.password<<std::endl;
    out<<"E-mail: "<<obj.email<<std::endl;
    out<<"First Name: "<<obj.first_name<<std::endl;
    out<<"Last Name: "<<obj.last_name<<std::endl;
    out<<"ID Number: "<<obj.id_number<<std::endl;
    out<<"ID Residence: "<<obj.id_residence<<std::endl;
    out<<"Phone Number: "<<obj.phone_number<<std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, User &obj);
std::istream &operator>>(std::istream &in, User &obj) {
    char client[16], pswd[11], contact_email[31]; // gmail accounts have the limit of 30 characters an user can insert

    std::cout<<"Username: ";
    //in>>client; in.get();
    in.getline(client, 16);
    if(obj.username != nullptr)
    {
        delete []obj.username;
        obj.username = nullptr;
    }
    obj.username = new char[strlen(client)+1];
    strcpy(obj.username, client); // now the username contains maximum 15 characters
    std::cout<<"Password: ";
    //in>>pswd; in.get();
    in.getline(pswd, 11);
    if(obj.password != nullptr)
    {
        delete []obj.password;
        obj.password = nullptr;
    }
    obj.password = new char[strlen(pswd)+1];
    strcpy(obj.password, pswd);
    std::cout<<"E-mail: ";
    //in>>contact_email; in.get();
    in.getline(contact_email, 31);
    if(obj.email != nullptr)
    {
        delete []obj.email;
        obj.email = nullptr;
    }
    obj.email = new char[strlen(contact_email)+1];
    strcpy(obj.email, contact_email);

    std::cout<<"First Name: ";
    in>>obj.first_name;
    std::cout<<"Last Name: ";
    in>>obj.last_name;
    std::cout<<"ID Number: ";
    in>>obj.id_number;
    std::cout<<"ID Residence: ";
    in>>obj.id_residence;
    std::cout<<"Phone Number: ";
    in>>obj.phone_number;
    return in;
}

// do i really have to do all of these setters and getters?
/*void User::setUsername(char *username) {
    if(this->username != nullptr)
    {
        delete []this->username;
        this->username = nullptr;
    }
    this->username = new char[strlen(username)+1];
    strcpy(this->username, username);
}

void User::setPassword(char *password) {
    if(this->password != nullptr)
    {
        delete []this->password;
        this->password = nullptr;
    }
    this->password = new char[strlen(password)+1];
    strcpy(this->password, password);
}

const char *User::getUsername() const {
    return username;
}*/

void User::loginMenu(User &user) {
    std::string user2, pswd2;
    std::cout<<"------- Log into your account -------"<<std::endl;
    std::cout<<"Enter you username: ";
    std::cin>>user2;
    if(user.username == user2)
    {
        std::cout<<"Enter your password: "<<std::endl;
        std::cin>>pswd2;
        if(user.password == pswd2)
        {
            std::cout<<"You are now logged in!"<<std::endl;
        } else
        {
            std::cout<<"Incorrect password"<<std::endl;
        }
    } else
    {
        std::cout<<"Incorrect username"<<std::endl;
    }
}