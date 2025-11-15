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
