#include "fileSystem.h"
#include <fstream>
#include <sstream>

using namespace std;

void load_data(unordered_map<string, User> &user_data, unordered_map<int, Listing> &listing_data)
{
}

void save_data(unordered_map<string, User> &user_data, unordered_map<int, Listing> &listing_data) {
    ofstream usersFile("data/users.txt");
    for (auto p : user_data)
    {
        User user = p.second;
        usersFile
                << user.getUserName() << '|'
                << user.getName() << '|'
                << user.getPhoneNumber() << '|'
                << user.getPassword() << '|';
        list<int> ids = user.getListingIds();
        auto it = ids.begin();
        while (it != ids.end())
        {
            usersFile << *it;
            ++it;
            if (it != ids.end())
                usersFile << ',';
        }
        usersFile << '\n';
    }
    usersFile.close();
}