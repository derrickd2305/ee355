#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    
};

// LinkedList class encapsulates the head pointer and various operations
class LinkedList {
private:
    Node* head;
public:
    // Constructor initializes an empty list
    

    // Destructor to free allocated memory
    

    // Function to add an element at the beginning of the list
    void addFirst(int data) {
        
    }

    // Function to append an element at the end of the list
    void append(int data) {
        
    }

    // Function to insert an element at a specific position (0-indexed)
    void insert(int data, int pos) {
        
    }

    // Function to delete the first occurrence of a node with the given value
    void deleteNode(int data) {
        
    }

    // Function to search for an element in the list.
    // Returns a pointer to the node if found, otherwise returns nullptr.
    Node* search(int data) {
       
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            // Uncomment the line below to display the data
            // Here we assume the data have one element of type int and one element of pointer type
            // cout << current->data << " -> ";
            // current = current->next;
        }
        cout << "NULL" << endl;
    }

        // Function to remove and return the first element of the list
    int pop() {
        if (head == nullptr) {
            throw runtime_error("List is empty. Cannot pop.");
        }
        // 
    }
};

int main(){

    // Open the input file "input.txt"
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Error opening input.txt" << "\n";
        return 1;
    }

    // Redirect cin to use the file stream, but keep cout as standard output.
    cin.rdbuf(infile.rdbuf());

    int T;
    cin >> T;
    string command;
    LinkedList list;
    
    // Process T commands from input
    for (int i = 0; i < T; i++){
        cin >> command;
        if (command == "addFirst") {
            int x;
            cin >> x;
            list.addFirst(x);
        } else if (command == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (command == "insert") {
            int x, pos;
            cin >> x >> pos;
            list.insert(x, pos);
        } else if (command == "delete") {
            int x;
            cin >> x;
            list.deleteNode(x);
        } else if (command == "pop") {
            try {
                int popped = list.pop();
                cout << "Popped: " << popped << "\n";
            } catch (const runtime_error &e) {
                cout << e.what() << "\n";
            }
        } else if (command == "search") {
            int x;
            cin >> x;
            Node* found = list.search(x);
            cout << (found ? "Found" : "Not Found") << "\n";
        } else if (command == "display") {
            list.display();
        }
    }
    return 0;
