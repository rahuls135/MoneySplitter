#include "graph.h"
using namespace std;

// Constructor
Graph::Graph(const vector<User>& users) : users(users) {
    int size = users.size();
    adjacencyMatrix.resize(size, vector<double>(size, 0.0));
}

// Add an edge between two users with a weight
void Graph::addEdge(const User& source, const User& destination, double weight) {
    int sourceIndex = getUserIndex(source);
    int destinationIndex = getUserIndex(destination);

    if (sourceIndex != -1 && destinationIndex != -1) {
        adjacencyMatrix[sourceIndex][destinationIndex] = weight;

        // If destination owes source as well, get the cost difference and update AM
        if (adjacencyMatrix[destinationIndex][sourceIndex] > 0) {
            // Difference between what source owes dest and what dest owes source
            double costDiff = adjacencyMatrix[sourceIndex][destinationIndex] - adjacencyMatrix[destinationIndex][sourceIndex];

            if (costDiff > 0) { // source owes dest more so make that pointer the difference and zero the other
                adjacencyMatrix[sourceIndex][destinationIndex] = costDiff;
                adjacencyMatrix[destinationIndex][sourceIndex] = 0;
            } else if (costDiff < 0) { // dest owes source more so make that pointer the negative difference and zero the other
                adjacencyMatrix[destinationIndex][sourceIndex] = -costDiff;
                adjacencyMatrix[sourceIndex][destinationIndex] = 0;
            } else { // both owe each other the same amount, so zero both of them
                adjacencyMatrix[sourceIndex][destinationIndex] = 0;
                adjacencyMatrix[destinationIndex][sourceIndex] = 0;
            }
        }
    } else {
        cout << "One or both users do not exist in the graph." << endl;
    }
}

// Get the user index in the graph
int Graph::getUserIndex(const User& user) const {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getKey() == user.getKey()) {
            return i;
        }
    }
    return -1; // User not found
}

// Get the weight of an edge between two users
double Graph::getWeight(const User& source, const User& destination) const {
    int sourceIndex = getUserIndex(source);
    int destinationIndex = getUserIndex(destination);

    if (sourceIndex != -1 && destinationIndex != -1) {
        return adjacencyMatrix[sourceIndex][destinationIndex];
    } else {
        cout << "One or both users do not exist in the graph." << endl;
        return -1; // Any user not found
    }
}

// Print the adjacency matrix
void Graph::printAdjacencyMatrix() const {
    for (const auto& row : adjacencyMatrix) {
        for (const auto& weight : row) {
            cout << weight << " ";
        }
        cout << endl;
    }
}

// Prints balance between each user owed
void Graph::printBalances() const {
    for (int i = 0; i < users.size(); i++) {
        for (int j = 0; j < users.size(); j++) {
            double balance = adjacencyMatrix[i][j];
            // Don't print anything for users if no money is owed between them
            if (balance != 0) {
                cout << users[i] << " owes " << users[j] << " $" << balance << endl;
            }
        }
    }
}