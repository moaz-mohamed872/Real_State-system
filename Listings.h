//
// Created by Compumarts on 04-May-26.
//

#ifndef REAL_STATE_SYSTEM_LISTINGS_H
#define REAL_STATE_SYSTEM_LISTINGS_H


#include<string>


class Listing {
    int id;
    static int idCounter ;
    std::string userName;
    float price;
    std::string location;
    float size;
    int numOfBedrooms;
    bool Sold;

public:
    Listing();
    Listing(int id,  std::string user_name, float price,  std::string location, float size,
            int num_of_bedrooms, bool sold);

    int getId();
    std::string getUserName();
    float getPrice();
    std::string getLocation();
    float getSize();
    int getNumOfBedrooms();
    bool isSold();
    void setId(int id);
    void setUserName(const std::string user_name);
    void setPrice(float price);
    void setLocation(const std::string location);
    void setSize(float size);
    void setNumOfBedrooms(int num_of_bedrooms);
    void setIsSold(bool is_sold);
};


#endif //REAL_STATE_SYSTEM_LISTINGS_H
