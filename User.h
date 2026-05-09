#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <list>
#include "Listings.h"
using namespace std;

class User {
    string userName;
    string name;
    int phoneNumber;
    int password;
    list<int> listingIds;

    list <int>::iterator find_id(int);

public:

    User();
    User(string user_name, string ame, int phone_number, int password,
    const list<int> &listing_ids);

    string getUserName();
    void setUserName(string );
    string getName();
    void setName(string);
    int getPhoneNumber();
    void setPhoneNumber(int);
    int getPassword();
    void setPassword(int password);
    list<int> getListingIds();
    void set_listing_ids(list<int>);

    static string log_in_newUser(unordered_map<string, User> &user_data);
    static string sign_in(unordered_map<string, User> &user_data);
    void user_edit_profile(unordered_map<string, User> &user_data);
    void add_newListing(unordered_map<int, Listing> &listing_data);
    void remove_Listing(unordered_map<int, Listing> &listing_data);
};