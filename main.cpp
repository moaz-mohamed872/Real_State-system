#include <unordered_map>
#include "User.h"
#include "Listings.h"
#include "SystemFunctionalities.h"
#include "fileSystem.h"

using namespace std;

unordered_map<string, User> user_data;
unordered_map<int, Listing> listing_data, sold_listings;

int main()
{
    load_data(user_data, listing_data);
    for (auto p : listing_data)
    {
        if (p.second.isSold())
            sold_listings[p.first] = p.second;
    }

    string curr_username = start_system(user_data);

    while (curr_username == "admin")
        admin_options(curr_username, user_data, listing_data, sold_listings);
    while (curr_username != "")
        user_options(curr_username, user_data, listing_data, sold_listings);

    return 0;
}