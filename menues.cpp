#include <iostream>

using namespace std;

string start_menue()
{
    cout << "\t\t====== Welcome to Real-State portal ======\n\n";

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

    return input;
}

string admin_menue()
{
    cout << "\t------- manage listings -------\n"
        << "1) Add listing\n"
        << "2) Edit listings\n"
        << "3) Remove listing\n";

    cout << "\t------- manage users -------\n"
        << "4) Add user\n"
        << "5) Edit users\n"
        << "6) Remove user\n";

    cout << "\t------- manage system -------\n"
        << "7) System reports\n"
        << "8) Exit\n"
        << "\n choose an option :";

    string input;
    cin >> input;

    while (input != "1" and input != "2" and input != "3" and input != "4"
        and input != "5" and input != "6" and input != "7" and input != "8")
    {
        cout << "invalid input ... try again\n";
        cin >> input;
    }

    return input;
}

string user_menue()
{
    cout << "1) Add listing\n"
       << "2) Remove listing\n"
       << "3) Search for a listing\n"
       << "4) Edit profile\n"
       << "5) Exit\n"
       << "\n choose an option :";

    string input;
    cin >> input;

    while (input != "1" and input != "2" and input != "3"
        and input != "4" and input != "5")
    {
        cout << "invalid input ... try again\n";
        cin >> input;
    }

    return input;
}