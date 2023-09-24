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

    void addFriend(User* friendUser) {
        if (friendList.size() < 100) {
            friendList.push_back(friendUser);
        } else {
            std::cout << "Error: Friend list is full. Cannot add more friends.\n";
        }
    }

    void removeFriend(const std::string& friendUserName) {
        for (auto it = friendList.begin(); it != friendList.end(); ++it) {
            if ((*it)->getUserName() == friendUserName) {
                friendList.erase(it);
                return;
            }
        }
        std::cout << "Error: Friend not found in the friend list.\n";
    }

    int numFriends() const {
        return friendList.size();
    }

    User* getFriendAt(int index) {
        if (index >= 0 && index < friendList.size()) {
            return friendList[index];
        } else {
            std::cout << "Error: Invalid index.\n";
            return nullptr;
        }
    }
};