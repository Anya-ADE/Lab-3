#include <iostream>
#include <vector>
using namespace std;

void createAdjacencyMatrix();
void createAdjacencyList();

int main() {
    int choice;
    cout << "Choose graph representation:\n";
    cout << "1. Adjacency Matrix\n";
    cout << "2. Adjacency List\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        createAdjacencyMatrix();
    } else if (choice == 2) {
        createAdjacencyList();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

void createAdjacencyMatrix() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

    cout << "Enter edges (u v weight) where u and v are vertex indices:\n";
    cout << "(Note: Self-loops are allowed, e.g., 2 2 5)\n";
   
    for (int i = 0; i < e; i++) {
        int u, w, weight;
        cin >> u >> w >> weight;
       
        // Validate vertex indices
        if (u < 0 || u >= v || w < 0 || w >= v) {
            cout << "Invalid edge (" << u << " " << w << "). Vertices must be between 0 and " << v-1 << ".\n";
            i--;  // Don't count this as a valid edge
            continue;
        }
       
        // Validate weight
        if (weight <= 0) {
            cout << "Invalid weight. Weight must be positive.\n";
            i--;
            continue;
        }
       
        // Handle self-loop
        if (u == w) {
            cout << "Self-loop detected at vertex " << u << " with weight " << weight << "\n";
            adjMatrix[u][w] = weight;
        } else {
            // Regular edge (undirected)
            adjMatrix[u][w] = weight;
            adjMatrix[w][u] = weight;
        }
    }

    cout << "\nAdjacency Matrix (0 means no edge):\n";
    cout << "   ";
    for (int i = 0; i < v; i++) {
        cout << i << " ";
    }
    cout << "\n";
   
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
   
}
