#include <iostream>
#include <vector>
#include <string>

class User {
    private:
        std::string userName;
        std::string email;
        std::vector<User*> friendList;

}