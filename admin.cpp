#include "main.cpp"

User get_user_data()// reads the input of all user data except the username
{
    User user;
    // input : name => user.setname(name);
    return user;
}

string get_username()// reads the username
{
    // input username
    return "";
}

void add_user()
{
    string username = get_username();
    User new_user = get_user_data();
    new_user.setUserName(username);
    user_data[username] = new_user;
}

void delete_user()
{
    string username = get_username();
    user_data.erase(username);
}

void edit_user()
{
    string username = get_username();
    if (user_data.count(username)){
        User new_user = get_user_data();
        new_user.setUserName(username);
        user_data[username] = new_user;
    }
    else
    {
        // no user found
    }
}