#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

class User {
private:
    std::string userName;
    std::string email;
    std::vector<User*> friendList;

public:
    User(const std::string& name, const std::string& userEmail);

    void setUserName(const std::string& name);
    std::string getUserName() const;

    void setEmail(const std::string& userEmail);
    std::string getEmail() const;

    void addFriend(User* friendUser);
    void removeFriend(const std::string& friendUserName);
    int numFriends() const;
    User* getFriendAt(int index);
};

#endif
