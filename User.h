#pragma once
#include <string>
#include <iostream>
#include <list>


class User {
    std::string userName;
    std::string name;
    int phoneNumber;
    int password;
    std::list<int> listingIds;

public:

    User();
    User( std::string user_name,  std::string ame, int phone_number, int password,
    const std::list<int> &listing_ids);

    std::string getUserName();
    void setUserName(std::string );
    std::string getName();
    void setName(std::string);
    int getPhoneNumber();
    void setPhoneNumber(int);
    int getPassword();
    void setPassword(int password);
    std::list<int> getListingIds();
    void set_listing_ids(std::list<int>);
};