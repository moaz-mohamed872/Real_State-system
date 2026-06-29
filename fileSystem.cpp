#include "fileSystem.h"
#include <fstream>
#include <sstream>

using namespace std;

void load_data(unordered_map<string, User> &user_data, unordered_map<int, Listing> &listing_data)
{
    ifstream usersFile("data/users.txt");
    string line;
    while (getline(usersFile, line))
    {
        stringstream ss(line);
        string username;
        string name;
        string phone;
        string password;
        string ids;
        getline(ss, username, '|');
        getline(ss, name, '|');
        getline(ss, phone, '|');
        getline(ss, password, '|');
        getline(ss, ids);
        list<int> listingIds;
        stringstream idStream(ids);
        string id;
        while (getline(idStream, id, ','))
        {
            if (!id.empty())
                listingIds.push_back(stoi(id));
        }
        User user(
                username,
                name,
                stoi(phone),
                password,
                listingIds
        );
        user_data[username] = user;
    }
    usersFile.close();
    //------------------------\\//
    ifstream listingFile("data/listings.txt");

    int mx = 0;

    while (getline(listingFile, line))
    {
        stringstream ss(line);
        string id;
        string username;
        string price;
        string location;
        string size;
        string bedrooms;
        string sold;
        getline(ss, id, '|');
        getline(ss, username, '|');
        getline(ss, price, '|');
        getline(ss, location, '|');
        getline(ss, size, '|');
        getline(ss, bedrooms, '|');
        getline(ss, sold);
        Listing l;
        int listingId = stoi(id);
        l.setId(listingId);
        l.setUserName(username);
        l.setPrice(stof(price));
        l.setLocation(location);
        l.setSize(stof(size));
        l.setNumOfBedrooms(stoi(bedrooms));
        l.setIsSold(stoi(sold));
        listing_data[listingId] = l;
        mx = max(mx, listingId);
    }
    listingFile.close();
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
    //------------------------------------------------------------\\//
    ofstream listingFile("data/listings.txt");
    for (auto p : listing_data)
    {
        Listing l = p.second;
        listingFile
                << l.getId() << '|'
                << l.getUserName() << '|'
                << l.getPrice() << '|'
                << l.getLocation() << '|'
                << l.getSize() << '|'
                << l.getNumOfBedrooms() << '|'
                << l.isSold()
                << '\n';
    }
    listingFile.close();
}