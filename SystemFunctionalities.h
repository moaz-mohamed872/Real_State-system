//
// Created by Compumarts on 16-Jun-26.
//

#ifndef REAL_STATE_SYSTEM_SYSTEMFUNCTIONALITIES_H
#define REAL_STATE_SYSTEM_SYSTEMFUNCTIONALITIES_H

#include "menues.h"
#include "admin.h"

string start_system(unordered_map<string, User> & user_data);

void user_options(string &curr_username, unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings);

void admin_options(string &curr_username, unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings);

#endif //REAL_STATE_SYSTEM_SYSTEMFUNCTIONALITIES_H