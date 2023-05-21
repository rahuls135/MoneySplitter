#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include "user.h"
using namespace std;

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

    void printBalances() const;
};

#endif  // GRAPH_H
