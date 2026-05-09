#include <unordered_map>
#include "User.h"
#include "Listings.h"

#include "menues.cpp"
#include "SystemFunctionalities.cpp"

using namespace std;

unordered_map<string, User> user_data;
unordered_map<int, Listing> listing_data;

int main()
{

    string curr_username = start_system(user_data);

    while (curr_username == "admin")
        admin_options();
    while (curr_username != "")
        user_options();

    return 0;
}