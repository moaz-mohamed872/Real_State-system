#include "admin.h"

User get_user_data()
{
    string name,password;
    int phone_number;
    list<int> listing_ids;
    User user;
    cout << "Enter your name" << endl;
    cin >> name;
    user.setName(name);
    

    cout << "Enter your phoneNumber" << endl;
    cin >> phone_number;
    user.setPhoneNumber(phone_number);
   
    cout << "Enter your password" << endl;
    cin >> password;
    user.setPassword(password);

    cout << "Enter the number of listingIds" << endl;
    int number, id;
    cin >> number;
    for (int i = 0; i < number; i++) {
        cin >> id;
        listing_ids.push_back(id);
    }

    user.set_listing_ids(listing_ids);


    return user;
}

string get_username()
{
    string user_name;

    cout << "Enter your username" << endl;
    cin >> user_name;

    return user_name;
}

void add_user(unordered_map<string, User> & user_data)
{
    string username = get_username();
    User new_user = get_user_data();
    new_user.setUserName(username);
    user_data[username] = new_user;
}

void delete_user(unordered_map<string, User> & user_data)
{
    string username = get_username();
   
  
    if (user_data.count(username)) {
        user_data.erase(username);
    }
    else
    {
        cout << "No user found";
    }

}

void edit_user(unordered_map<string, User> & user_data)
{
    string username = get_username();
    if (user_data.count(username)){
        User new_user = get_user_data();
        new_user.setUserName(username);
        user_data[username] = new_user;
    }
    else
    {
        cout << "No user found";
    }
}

Listing get_listing_data() {
    int id , numOfBedrooms;
    float price, size;
    string location;
    bool is_sold;
    Listing l;

    
    cout << "Enter listing id" << endl;
    cin >> id;
    l.setId(id);

    cout << "Enter listing price " << endl;
    cin >> price;
    l.setPrice( price);

    cout << "Enter listing location " << endl;
    cin >> location;
    l.setLocation(location);

    cout << "Enter listing size " << endl;
    cin >> size;
    l.setSize(size);

    cout << "Enter listing numOfBedrooms";
    cin >> numOfBedrooms;
    l.setNumOfBedrooms(numOfBedrooms);

    cout << "Enter listing size " << endl;
    cin >> size;
    l.setSize(size);


    cout << "Are the listing is solid ?" << endl;
    cin >> is_sold;
    l.setIsSold(is_sold);

    return l;
}

int get_list_id() {
    
    int list_id;

    cout << "Enter listing id" << endl;
    cin >> list_id;

    return list_id;
}

void add_listing(unordered_map<int, Listing> &listing_data) {
    int listid = get_list_id();
    Listing new_list = get_listing_data();
    new_list.setId(listid);
    listing_data[listid] = new_list;
}

void delete_listing(unordered_map<int, Listing> &listing_data) {
    int listid = get_list_id();
    listing_data.erase(listid);
}

void edit_listing(unordered_map<int, Listing> &listing_data) {
    int listid = get_list_id();
    if (listing_data.count(listid)) {
        Listing new_list = get_listing_data();
        new_list.setId(listid);
        listing_data[listid] = new_list;
    }
    else
    {
        cout << "No list found";
    }
}

//======================================================
// REPORTS

int get_total_sales(char option, unordered_map<int, Listing> sold_listings)
{
    int sum = 0;
    for (auto l : sold_listings)
        sum += (option == 'p')? l.second.getPrice() : 1;

    return sum;
}

int get_price_avg(unordered_map<int, Listing> &listing_data)
{
    int sum = 0;
    for (auto l : listing_data)
    {
        Listing lst = l.second;
        sum += lst.getPrice();
    }

    if (listing_data.size() == 0)
        return 0;

    return sum/listing_data.size();
}

void reports(unordered_map<string, User> & user_data,
    unordered_map<int, Listing> &listing_data,
    unordered_map<int, Listing> &sold_listings)
{
    cout << "there is " << user_data.size() << "users\n";

    cout << "there is " << listing_data.size() << "listings\n";

    cout << "the average of listings' prices is " << get_price_avg(listing_data) << "\n";

    cout << "we sold " << get_total_sales('c', sold_listings) << "listings\n";

    int tmp = get_total_sales('p', sold_listings);
    cout << "with value of " << tmp << "$\n";

    cout << "we made total of " << tmp*0.15 << "$\n";
}