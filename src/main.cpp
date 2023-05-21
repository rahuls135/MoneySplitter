#include <iostream>
#include "graph.h"  // Assuming Graph and User classes are defined in separate header files

int main() {
    // Create users
    User user1("Alice");
    User user2("Bob");
    User user3("Charlie");
    User user4("David");

    // Create graph
    std::vector<User> users = {user1, user2, user3, user4};
    Graph graph(users);

    // Add edges with weights
    graph.addEdge(user1, user2, 1.5);
    graph.addEdge(user2, user1, 2.0);
    graph.addEdge(user2, user4, 3.5);
    graph.addEdge(user3, user4, 4.0);

    // Print balances
    graph.printBalances();

    return 0;
}
