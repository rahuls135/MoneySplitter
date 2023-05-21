#ifndef USER_H
#define USER_H
#include <iostream> // Include iostream for ostream
#include <string>
using namespace std;

class User {
    static int nextkey; // incremented each time a new user is created
    int key; // acts as the index for the adjacency matrix
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
