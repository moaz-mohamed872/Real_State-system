#ifndef REAL_STATE_SYSTEM_USERFUNCTIONALITIES_H
#define REAL_STATE_SYSTEM_USERFUNCTIONALITIES_H

#include"User.h"

class UserFunctionalities
{
public:
    static string log_in_newUser(unordered_map<string, User> &user_data);
    static string sign_in(unordered_map<string, User> &user_data);
    static void search_listing(unordered_map<int, Listing> &listing_data);
private:
    static int get_listing(unordered_map<int, Listing> listing_data);
};


#endif //REAL_STATE_SYSTEM_USERFUNCTIONALITIES_H