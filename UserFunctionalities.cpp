#include "UserFunctionalities.h"

string UserFunctionalities::log_in_newUser(unordered_map<string, User> &user_data) {
    User user ;
    string user_name ;
    cout << "Enter user name: ";
    cin >> user_name;

    if (user_data.count(user_name)) {
        cout << "The user already exists!" << endl ;
        cout <<"1) sing in " <<endl ;
        cout <<"2) Try again " << endl;
        string input;
        cin >> input ;

        if (input == "1") {
           string name =  UserFunctionalities::sign_in(user_data);
            return name;
        }

        return UserFunctionalities::log_in_newUser(user_data);
    }

    string name;
    cout << "Enter name: ";
    cin >> name;
    cout <<"\n";
    string password;
    cout << "Enter Password: ";
    cin >> password;
    cout <<"\n";
    int phone_number;
    cout << "Enter phone number: ";
    cin >> phone_number;
    cout <<"\n";
    list<int> listingIds = {};
    user_data[user_name] = User(user_name, name, phone_number, password, listingIds);
    cout << "\n" <<"<< Add new User successful >>" ;
    return user_name;

}

string UserFunctionalities::sign_in(unordered_map <string, User> &user_data) {
    string user_name ;
    cout << "Enter user name: ";
    cin >> user_name;

    string password;
    cout << "Enter Password: ";
    cin >> password;

    if (user_name == "admin" and password == "1234")
    {
        cout << "welcome admin\n";
        return "admin";
    }

    if (user_data.count(user_name) and user_data[user_name].getPassword() == password and user_name != "admin") {
        cout <<"<< Sing in successful >>" ;
        return user_name;
    }

    cout <<"<< Sing in failed >>" ;
    return UserFunctionalities::sign_in(user_data) ;
}

void UserFunctionalities::search_listing(unordered_map<int, Listing> &listing_data)
{
    int id = get_listing(listing_data);
    cout << "Do you want to buy? ('y': Yes, 'n': No)";
    string answer;
    cin >> answer;

    while (!(answer == "y" || answer == "n"))
    {
        cout << "invalid answer, try again\n";
        cin >> answer;
    }

    if (answer == "y")
        listing_data[id].setIsSold(true);
}

int UserFunctionalities::get_listing(unordered_map<int, Listing> listing_data)
{
    string field;
    bool found = false;
    unordered_map<char, string> fields;
    fields['s'] = "Size";
    fields['b'] = "Bedroom number";
    fields['p'] = "Price";
    fields['l'] = "Location";
    fields['i'] = "Id";
    fields['u'] = "Sold by";

    cout << "What do you want to search by? ('s' : size, 'b' : bedroom number, 'p' : price , 'l' : location";
    cin >> field;

    while (true)
    {
        if (field == "s" || field == "b" || field == "p" || field == "l")
            break;
        cout << "wrong input, please try  again\n";
    }

    int minn;
    string location;

    if (field == "l")
    {
        cin >> location;
        cout << "enter the location you want: ";
    }
    else
    {
        cout << "enter the minimum " << fields[field[0]] << "you want: ";
        cin >> minn;
    }

    cout << fields['i'] << "\t| "
        << fields['s'] << "\t| "
        << fields['l'] << "\t| "
        << fields['b'] << "\t| "
        << fields['u'] << "\n";

    for (auto listing : listing_data)
    {
        if (!listing.second.isSold() && (
            (field == "s" && listing.second.getSize() > minn) ||
            (field == "b" && listing.second.getNumOfBedrooms() > minn) ||
            (field == "p" && listing.second.getPrice() > minn)  ||
            (field == "l" && listing.second.getLocation() == location)
            ))
        {
            cout << listing.second.getId() << " \t| "
                << listing.second.getSize() << "\t| "
                << listing.second.getLocation() << "\t| "
                << listing.second.getNumOfBedrooms() << "\t| "
                << listing.second.getUserName() << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "sorry there are no listings that match your search\n";
    else
    {
        cout << "enter the id of the listing you want:";
        string id;
        cin >> id;
        try
        {
            int search_id = stoi(id);
            if (listing_data.count(search_id))
                return search_id;
            cout << "invalid id, try again\n";
        }
        catch (...)
        {
            cout << "invalid id, try again\n";
        }
    }

}