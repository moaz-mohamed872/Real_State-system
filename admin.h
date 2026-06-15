//
// Created by Compumarts on 16-Jun-26.
//

#ifndef REAL_STATE_SYSTEM_ADMIN_H
#define REAL_STATE_SYSTEM_ADMIN_H
#include "User.h"

User get_user_data();

void add_user(unordered_map<string, User> & user_data);

void delete_user(unordered_map<string, User> & user_data);

void edit_user(unordered_map<string, User> & user_data);

Listing get_listing_data();

int get_list_id();

void add_listing(unordered_map<int, Listing> &listing_data);

void delete_listing(unordered_map<int, Listing> &listing_data);

void edit_listing(unordered_map<int, Listing> &listing_data);

int get_total_sales(char option, unordered_map<int, Listing> sold_listings);

int get_price_avg(unordered_map<int, Listing> &listing_data);

void reports(unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings);


#endif //REAL_STATE_SYSTEM_ADMIN_H