#include <iostream>
#include "graph.h"  // Assuming Graph and User classes are defined in separate header files
using namespace std;

int main() {
    // Create users
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User david("David");

    // Create graph
    vector<User> users = {alice, bob, charlie, david};
    Graph graph(users);

    // Add edges with weights
    graph.addEdge(alice, bob, 1.5);
    graph.addEdge(bob, alice, 2.0);
    graph.addEdge(bob, david, 3.5);
    graph.addEdge(charlie, david, 4.0);

    // Print balances
    graph.printBalances();

    return 0;
}
