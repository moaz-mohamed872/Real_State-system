#include "Listings.h"

Listing::Listing() {
    id = 0;
    idCounter++;
    userName = "";
    price = 0.0;
    location = "";
    size = 0.0;
    numOfBedrooms = 0;
    Sold = false;

}
Listing::Listing(int id,  std::string user_name, float price, std::string location, float size,
    int num_of_bedrooms, bool sold)
        : id(id),
          userName(user_name),
          price(price),
          location(location),
          size(size),
          numOfBedrooms(num_of_bedrooms),
          Sold(sold) {
    idCounter++;
}

int Listing :: getId() {
    return id;
}

std :: string Listing :: getUserName()  {
    return userName;
}

float Listing :: getPrice()  {
    return price;
}

std::string Listing:: getLocation()  {
    return location;
}

float Listing:: getSize() {
    return size;
}

int Listing:: getNumOfBedrooms()  {
    return numOfBedrooms;
}

bool Listing::isSold()  {
    return Sold;
}

void Listing:: setId(int id) {
    this->id = id;
}

void Listing:: setUserName(const std::string user_name) {
    userName = user_name;
}

void Listing:: setPrice(float price) {
    this->price = price;
}

void Listing:: setLocation(const std::string location) {
    this->location = location;
}

void Listing::setSize(float size) {
    this->size = size;
}

void Listing:: setNumOfBedrooms(int num_of_bedrooms) {
    numOfBedrooms = num_of_bedrooms;
}

void Listing:: setIsSold(bool is_sold) {
    Sold = is_sold;
}
int Listing:: getIdCounter() {
    return idCounter;
}
```