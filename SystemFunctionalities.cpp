#include "menues.cpp"
#include "User.h"

string start_system(unordered_map<string, User> & user_data)
{
    string input = start_menue();

    if (input == "1")
        return User::log_in_newUser(user_data);

    if (input == "2")
        return User::sign_in(user_data);

    return "";
}

void user_options(string &curr_username, unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings)
{
    string input = user_menue();
    User user = user_data[curr_username];

    if (input == "1")
    {
        user.add_newListing(listing_data);
    }
    else if (input == "2")
    {
        user.remove_Listing(listing_data, sold_listings);
    }
    else if (input == "3")
    {
        //user.search_listing();
    }
    else if (input == "4")
    {
        user.user_edit_profile(user_data);
    }
    else
        curr_username = "";
}

void admin_options(string &curr_username, unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings)
{

}

