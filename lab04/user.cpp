#include <iostream>
#include <vector>
#include <string>

class User {
    private:
        std::string userName;
        std::string email;
        std::vector<User*> friendList;

    public:
        User(const std::string& name, const std::string& userEmail)
            : userName(name), email(userEmail) {}

        void setUserName(const std::string& name) {
            userName = name;
    }

        std::string getUserName() const {
            return userName;
    }

        void setEmail(const std::string& userEmail) {
            email = userEmail;
    }

        std::string getEmail() const {
            return email;
    }
}