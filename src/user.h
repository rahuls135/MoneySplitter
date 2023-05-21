#ifndef USER_H
#define USER_H
#include <iostream> // Include iostream for ostream
#include <string>
using namespace std;

class User {
    static int nextkey;
    int key;
    string username;

public:
    // Constructor
    User(const string& username);

    // Getter methods
    int getKey() const;
    string getUsername() const;
    // Override << for printing User objects
    friend std::ostream& operator<<(std::ostream& out, const User& user);
};

#endif  // USER_H
