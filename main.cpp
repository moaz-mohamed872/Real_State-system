#include <unordered_map>
#include "User.h"
#include "Listings.h"

#include "menues.cpp"
#include "SystemFunctionalities.cpp"
#include "fileSystem.cpp"

using namespace std;

unordered_map<string, User> user_data;
unordered_map<int, Listing> listing_data, sold_listings;

int main()
{
    load_data(user_data, listing_data);

    string curr_username = start_system(user_data);

    while (curr_username == "admin")
        admin_options(curr_username, user_data, listing_data, sold_listings);
    while (curr_username != "")
        user_options(curr_username, user_data, listing_data, sold_listings);

    return 0;
}