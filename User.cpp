#include "User.h"

User::User() {
    userName ="";
    name = "";
    phoneNumber = 0;
    password = 0;
    listingIds = {0};
}
User::User( std::string user_name,  std::string name, int phone_number, int password,
    const std::list<int> &listing_ids)
    : userName(user_name),
      name(name),
      phoneNumber(phone_number),
      password(password),
      listingIds(listing_ids) {
}
std::string User::getUserName()  {
    return userName;
}

void User::setUserName(std::string user_name) {
    userName = user_name;
}

std::string User::getName()  {
    return name;
}

void User::setName(std::string name) {
    this->name = name;
}

int User::getPhoneNumber()  {
    return phoneNumber;
}

void User::setPhoneNumber(int phone_number) {
    phoneNumber = phone_number;
}

int User::getPassword()  {
    return password;
}

void User::setPassword(int password) {
    this->password = password;
}

std::list<int> User::getListingIds() {
    return listingIds;
}

void User::set_listing_ids(std::list<int> listing_ids) {
    listingIds = listing_ids;
}