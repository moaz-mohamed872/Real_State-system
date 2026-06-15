
//
// Created by Compumarts on 16-Jun-26.
//

#ifndef REAL_STATE_SYSTEM_FILESYSTEM_H
#define REAL_STATE_SYSTEM_FILESYSTEM_H

#include "User.h"

void load_data(unordered_map<string, User> &user_data, unordered_map<int, Listing> &listing_data);

void save_data(unordered_map<string, User> &user_data, unordered_map<int, Listing> &listing_data);

#endif //REAL_STATE_SYSTEM_FILESYSTEM_H