#include "user.h"

using namespace std;

int User::nextkey = 0;

// Constructor
User::User(const string& username) : key(nextkey++), username(username) {}

// Getter for key
int User::getKey() const {
    return key;
}

// Getter for username
string User::getUsername() const {
    return username;
}

// Override << for printing User objects
std::ostream& operator<<(std::ostream& out, const User& user) {
    out << user.getUsername();
    return out;
}