#include "User.h"
#include <unordered_map>

list <int>::iterator User::find_id(int id)
{
    for (auto it = this->listingIds.begin(); it != this->listingIds.end(); it++)
        if (id == *it)
            return it;
    return this->listingIds.end();
}

User::User() {
    userName ="";
    name = "";
    phoneNumber = 0;
    password = "";
    listingIds = {0};
}

User::User( std::string user_name,  std::string name, int phone_number, string password,
    const std::list<int> &listing_ids)
    : userName(user_name),
      name(name),
      phoneNumber(phone_number),
      password(password),
      listingIds(listing_ids) {
}

std::string User::getUserName()  {
    return userName;
}

void User::setUserName(std::string user_name) {
    userName = user_name;
}

std::string User::getName()  {
    return name;
}

void User::setName(std::string name) {
    this->name = name;
}

int User::getPhoneNumber()  {
    return phoneNumber;
}

void User::setPhoneNumber(int phone_number) {
    phoneNumber = phone_number;
}

string User::getPassword()  {
    return password;
}

void User::setPassword(string password) {
    this->password = password;
}

list<int> User::getListingIds() {
    return listingIds;
}

void User::set_listing_ids(std::list<int> listing_ids) {
    listingIds = listing_ids;
}

string User::log_in_newUser(unordered_map<string, User> &user_data) {
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
           string name =  User::sign_in(user_data);
            return name;
        }

        return User::log_in_newUser(user_data);
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

string User::sign_in(unordered_map <string, User> &user_data) {
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
    return User::sign_in(user_data) ;
}

void User:: user_edit_profile(unordered_map<string, User> &user_data) {
 while (true) {
     cout <<"Edit profile : " << endl ;
     cout <<"1) edit name"<<endl ;
     cout <<"2) edit phone number"<<endl ;
     cout <<"3) edit password"<<endl ;
     cout <<"4) Back " <<endl ;

     string user_name ;
     cin >> user_name ;
     if (user_data.count(user_name)) {
         cout << "The user already exists!" << endl ;
         cout << "Choice edit : ";
             string input;
             cin >> input ;
             if (input == "1") {
                 string name ;
                 cin >> name ;
                user_data[user_name].setUserName(name);

             }
             else if (input == "2") {
                int phone_number;
                 cin >> phone_number ;
                 user_data[user_name].setPhoneNumber(phone_number);

             }
             else if (input == "3") {
                 string password;
                 cin >> password ;
                 user_data[user_name].setPassword(password);

             }
             else {
                 break;
             }

     }
     else {
        cout <<"Invalid Usernamr !!" << endl ;
         user_edit_profile(user_data);
     }

 }
}

void User::add_newListing(unordered_map<int, Listing> &listing_data) {

        string user_name ;
        cout << "Enter user name: ";
        cin >> user_name ;
        cout <<"\n";

        float price;
        cout << "Enter price: ";
        cin >> price ;
        cout <<"\n";

        string location;
        cout << "Enter location: ";
        cin >> location ;
        cout <<"\n";

        float size ;
        cout << "Enter size: ";
        cin >> size ;


        int num_of_bedrooms;
        cout << "Enter number of bedrooms: ";
        cin >> num_of_bedrooms ;


        bool sold ;
        cout << "Enter type sold : ";
        cin >> sold ;

        Listing new_listing(user_name, price, location,size, num_of_bedrooms, sold);

        listing_data[new_listing.getId()] = new_listing;

}

void User::remove_Listing(unordered_map<int, Listing> &listing_data) {

    for (auto it : listingIds) {
        cout << it << endl;
        cout <<"\t Price : "<< listing_data[it].getPrice()<<" ||  Location : " << listing_data[it].getLocation()<<" || Size : " <<listing_data[it].getSize() <<endl ;
    }
    cout <<"---------------------------------------------------";

    while (true) {
        cout <<"Remove listing id: ";
        int id_listing;
        cin >> id_listing;
        list <int>::iterator it = this->find_id(id_listing);
        if (it != this->listingIds.end()) {
            listing_data.erase(id_listing);
            listingIds.erase(it);
            cout << "Listing removed successfully\n";
            cout <<"Do you Remove again ? Y : N " ;
            string input;
            cin >> input ;
            if (input == "n" or input == "N") {
                break;
            }
        }
        else {
            cout <<"Listing not found\n";
        }

    }

}


