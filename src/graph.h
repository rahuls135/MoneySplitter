#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include "user.h"
using namespace std;

/**
 * Keys in the AM are the indices for users vector
 * adjacencyMatrix[source][destination] is the amount of money that source owes users
 * adjacencyMatrix[source][destination] and adjacencyMatrix[destination][source] both cannot be > 0
 */
class Graph {
    vector<User> users;
    vector<vector<double>> adjacencyMatrix;

public:
    // Constructor
    Graph(const std::vector<User>& users);

    // Add an edge between two users with a weight
    void addEdge(const User& user1, const User& user2, double weight);

    // Get the user index in the graph
    int getUserIndex(const User& user) const;

    // Get the weight of an edge between two users
    double getWeight(const User& user1, const User& user2) const;

    // Print the adjacency matrix
    void printAdjacencyMatrix() const;

    // Print the balances between users
    void printBalances() const;
};

#endif  // GRAPH_H
