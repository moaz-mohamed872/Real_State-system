#include <iostream>
#include "User.h"

using namespace std;

void greet_user()
{
    cout << "====== Welcome to Real-State portal ======\n\n";
}

string start_menue(unordered_map<string, User> & user_data)
{
    cout << "1) Create account\n"
        << "2) Sign in\n"
        << "3) Exit\n"
        << "\n choose an option :";

    string input;
    cin >> input;

    while (input != "1" && input != "2" && input != "3")
    {
        cout << "invalid input ... try again\n";
        cin >> input;
    }

    if (input == "1")
        return User::log_in_newUser(user_data);

    if (input == "2")
        return User::sign_in(user_data);

    return "";
}