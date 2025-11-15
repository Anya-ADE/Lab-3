#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void createAdjacencyMatrix();
void createAdjacencyList();
void displayMenu();

int main() {

    int choice;
   
    do {
        displayMenu();
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        switch(choice) {
            case 1:
                createAdjacencyMatrix();
                break;
            case 2:
                createAdjacencyList();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    } while (choice != 3);
  
    return 0;

}    

void displayMenu() {
    cout << "=====================================" << endl;
    cout << "    Graph Representation Program" << endl;
    cout << "=====================================" << endl;
    cout << "1. Create Adjacency Matrix" << endl;
    cout << "2. Create Adjacency List" << endl;
    cout << "3. Exit" << endl;
    cout << "=====================================" << endl;
}

void createAdjacencyMatrix() {
    int v, e;
    char graphType;
    bool isDirected;
   
    cout << "\n=== Adjacency Matrix Creation ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Is the graph directed? (y/n): ";
    cin >> graphType;
   
    isDirected = (graphType == 'y' || graphType == 'Y');
   
    if (isDirected) {
        cout << "Creating a DIRECTED graph..." << endl;
    } else {
        cout << "Creating an UNDIRECTED graph..." << endl;
    }


    // Initialize adjacency matrix with 0 (0 means no edge)
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));


    // Variables to track statistics
    int totalWeight = 0;
    int minWeight = INT_MAX;
    int maxWeight = INT_MIN;
    int minU = -1, minV = -1;
    int maxU = -1, maxV = -1;
    int validEdges = 0;
    cout << "\nEnter edges (u v weight) where u and v are vertex indices:" << endl;
    if (isDirected) {
        cout << "(Edge direction: u -> v)" << endl;
    }
    cout << "(Note: Self-loops are allowed, e.g., 2 2 5)" << endl;
   
    for (int i = 0; i < e; i++) {
        int u, w, weight;
        cout << "Edge " << i+1 << ": ";
        cin >> u >> w >> weight;
       
        // Validate vertex indices
        if (u < 0 || u >= v || w < 0 || w >= v) {
            cout << "Invalid edge (" << u << " " << w << "). Vertices must be between 0 and " << v-1 << "." << endl;
            i--;  // Don't count this as a valid edge
            continue;
        }
       
        // Validate weight
        if (weight <= 0) {
            cout << "Invalid weight. Weight must be positive." << endl;
            i--;
            continue;
        }
       
        validEdges++;
       
        // Update statistics
        totalWeight += weight;
        if (weight < minWeight) {
            minWeight = weight;
            minU = u;
            minV = w;
        }
        if (weight > maxWeight) {
            maxWeight = weight;
            maxU = u;
            maxV = w;
        }
       
        // Handle self-loop
        if (u == w) {
            cout << "Self-loop detected at vertex " << u << " with weight " << weight << endl;
            adjMatrix[u][w] = weight;
        } else {
            // Add edge u -> w
            adjMatrix[u][w] = weight;
           
            // If undirected, also add edge w -> u
            if (!isDirected) {
                adjMatrix[w][u] = weight;
            }
        }
    }


    cout << "\n=== Adjacency Matrix (0 means no edge) ===" << endl;
   
    // Print column headers
    cout << "   ";
    for (int i = 0; i < v; i++) {
        cout << i << " ";
    }
    cout << endl;
   
    // Print matrix with row headers
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
   
    // Show interpretation
    if (isDirected) {
        cout << "\n(Row i, Column j represents edge from vertex i to vertex j)" << endl;
    } else {
        cout << "\n(Symmetric matrix for undirected graph)" << endl;
    }
   
    // Display statistics
    cout << "\n=== Graph Statistics ===" << endl;
    cout << "Total number of vertices: " << v << endl;
    cout << "Total number of valid edges: " << validEdges << endl;
   
    if (validEdges > 0) {
        cout << "Total weight of all edges: " << totalWeight << endl;
        cout << "Average edge weight: " << (double)totalWeight / validEdges << endl;
        cout << "Minimum weight edge: " << minWeight << " (from vertex " << minU << " to vertex " << minV << ")" << endl;
        cout << "Maximum weight edge: " << maxWeight << " (from vertex " << maxU << " to vertex " << maxV << ")" << endl;
    }
}

void createAdjacencyList() {
    int v, e;
    char graphType;
    bool isDirected;
   
    cout << "\n=== Adjacency List Creation ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Is the graph directed? (y/n): ";
    cin >> graphType;
   
    isDirected = (graphType == 'y' || graphType == 'Y');
   
    if (isDirected) {
        cout << "Creating a DIRECTED graph..." << endl;
    } else {
        cout << "Creating an UNDIRECTED graph..." << endl;
    }

    // Node structure for adjacency list
    struct Node {
        int vertex;
        int weight;
        Node* next;
       
        // Constructor for easier node creation
        Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };


    vector<Node*> adjList(v, nullptr);


    // Variables to track statistics
    int totalWeight = 0;
    int minWeight = INT_MAX;
    int maxWeight = INT_MIN;
    int minU = -1, minV = -1;
    int maxU = -1, maxV = -1;
    int validEdges = 0;


    cout << "\nEnter edges (u v weight) where u and v are vertex indices:" << endl;
    if (isDirected) {
        cout << "(Edge direction: u -> v)" << endl;
    }
    cout << "(Note: Self-loops are allowed, e.g., 2 2 5)" << endl;
   
    for (int i = 0; i < e; i++) {
        int u, w, weight;
        cout << "Edge " << i+1 << ": ";
        cin >> u >> w >> weight;
       
        // Validate vertex indices
        if (u < 0 || u >= v || w < 0 || w >= v) {
            cout << "Invalid edge (" << u << " " << w << "). Vertices must be between 0 and " << v-1 << "." << endl;
            i--;
            continue;
        }

// Validate weight
        if (weight <= 0) {
            cout << "Invalid weight. Weight must be positive." << endl;
            i--;
            continue;
        }
       
        validEdges++;
       
        // Update statistics
        totalWeight += weight;
        if (weight < minWeight) {
            minWeight = weight;
            minU = u;
            minV = w;
        }
        if (weight > maxWeight) {
            maxWeight = weight;
            maxU = u;
            maxV = w;
        }
       
        // Handle self-loop
        if (u == w) {
            cout << "Self-loop detected at vertex " << u << " with weight " << weight << endl;
            Node* newNode = new Node(u, weight);
            newNode->next = adjList[u];
            adjList[u] = newNode;
        } else {
            // Add edge u -> w
            Node* newNode = new Node(w, weight);
            newNode->next = adjList[u];
            adjList[u] = newNode;


            // If undirected, also add edge w -> u
            if (!isDirected) {
                newNode = new Node(u, weight);
                newNode->next = adjList[w];
adjList[w] = newNode;
            }
        }
    }


    cout << "\n=== Adjacency List ===" << endl;
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": ";
        Node* temp = adjList[i];
        while (temp) {
            cout << "-> (" << temp->vertex << ", w:" << temp->weight << ") ";
            temp = temp->next;
        }
        cout << "-> nullptr" << endl;
    }
   
    // Show interpretation
    if (isDirected) {
        cout << "\n(Vertex i's list shows all vertices reachable FROM vertex i)" << endl;
    } else {
        cout << "\n(Vertex i's list shows all adjacent vertices)" << endl;
    }
   
    // Display statistics
    cout << "\n=== Graph Statistics ===" << endl;
    cout << "Total number of vertices: " << v << endl;
    cout << "Total number of valid edges: " << validEdges << endl;
   
    if (validEdges > 0) {
        cout << "Total weight of all edges: " << totalWeight << endl;
        cout << "Average edge weight: " << (double)totalWeight / validEdges << endl;
        cout << "Minimum weight edge: " << minWeight << " (from vertex " << minU << " to vertex " << minV << ")" << endl;
        cout << "Maximum weight edge: " << maxWeight << " (from vertex " << maxU << " to vertex " << maxV << ")" << endl;
    }
   
// Clean up dynamically allocated memory
    cout << "\nCleaning up memory..." << endl;
    int nodesDeleted = 0;
    for (int i = 0; i < v; i++) {
        Node* current = adjList[i];
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
            nodesDeleted++;
        }
        adjList[i] = nullptr;
    }
    cout << "Memory cleaned up successfully. Deleted " << nodesDeleted << " nodes." << endl;
}
