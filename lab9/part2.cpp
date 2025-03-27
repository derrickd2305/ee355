#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {

};

class DoublyLinkedList {
private:
    // 
public:
    // Constructor initializes an empty list
    DoublyLinkedList()

    // Destructor to free allocated memory
    ~DoublyLinkedList() {
    }

    // Function to add an element at the beginning of the list
    void addFirst(int data) {
    }

    // Function to append an element at the end of the list
    void append(int data) {
    }

    // Function to insert an element at a specific position (0-indexed)
    void insert(int data, int pos) {
        // If we reached the end, append at the end
    }

    // Function to delete the node at a specific index (0-indexed)
    void deleteAtIndex(int index) {
        // if the index is Invalid or the list is empty
        // cout << "Invalid index or empty list." << endl;


        // If the index is out of bounds
        // cout << "Index out of bounds." << endl;

    }

    // Function to search for an element in the list.
    // Returns a pointer to the node if found, otherwise returns nullptr.
    Node* search(int data) {
    }

    // Function to check whether the doubly linked list is circular using two pointers.
    // The list is considered circular if there is a cycle in the next pointers.
    bool isCircularTwoPointer() {
       
    }

    // Function to display the doubly linked list
    void display() {
        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current != nullptr) {
            // Uncomment the line below to display the data
            // Here we assume the data have one element of type int and one element of pointer type

            // cout << current->data << " <-> ";
        }
        // cout << "NULL" << endl;
    }
};

int main() {
    // Open input.txt file for reading
    std::ifstream infile("input_part2.txt");
    if (!infile) {
        std::cerr << "Error opening input.txt" << "\n";
        return 1;
    }
    
    // Redirect cin to read from input.txt
    cin.rdbuf(infile.rdbuf());

    int T;
    cin >> T;
    string command;
    DoublyLinkedList dll;
    
    // Process T commands from the input file
    for (int i = 0; i < T; i++){
        cin >> command;
        if (command == "addFirst") {
            int x;
            cin >> x;
            dll.addFirst(x);
        } else if (command == "append") {
            int x;
            cin >> x;
            dll.append(x);
        } else if (command == "insert") {
            int x, pos;
            cin >> x >> pos;
            dll.insert(x, pos);
        } else if (command == "deleteAtIndex") {
            int idx;
            cin >> idx;
            dll.deleteAtIndex(idx);
        } else if (command == "search") {
            int x;
            cin >> x;
            Node* found = dll.search(x);
            cout << (found ? "Found" : "Not Found") << "\n";
        } else if (command == "display") {
            dll.display();
        } else if (command == "isCircular") {
            cout << "Is the list circular (two-pointer check)? " 
                 << (dll.isCircularTwoPointer() ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
