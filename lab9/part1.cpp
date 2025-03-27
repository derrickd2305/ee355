#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int val;
    Node* next;

    // constructor to set initial values, with the pointer default to NULL
    Node(int data){
        val = data;
        next = NULL;
    }
};

// LinkedList class encapsulates the head pointer and various operations
class LinkedList {
private:
    Node* head;
public:
    // Constructor initializes an empty list
    LinkedList(){
        head = NULL;
    }

    // Destructor to free allocated memory
    ~LinkedList(){
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to add an element at the beginning of the list
    void addFirst(int data) {
        Node* first = new Node(data);       // new element
        first->next = head;                 // the second term is the former first term
        head = first;                       // new element is new head
    }

    // Function to append an element at the end of the list
    void append(int data) {
        // if the LL is empty
        if(head == NULL){
            addFirst(data);
            return;
        }

        // if the term we are adding is not the first term, we have to iterate through the whole LL
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        Node* last = new Node(data);        // new element
        temp->next = last;                  // temp is previous last term in LL, so next term is our new term
    }

    // Function to insert an element at a specific position (0-indexed)
    void insert(int data, int pos) {
        // if the data is the first term, use addFirst
        if(pos == 0){
            addFirst(data);
            return;
        }
        // error message for negative index
        else if(pos < 0){
            cout << "insert error: position can't be negative" << endl;
            return;
        }

        // pointer to iterate through
        Node* temp = head;
        
         // iterate through LL
        for(int i = 0; i < pos-1; i++){
            if(temp != NULL){
                temp = temp->next;
            }
            else{
                cout << "Position out of bounds. Inserting at the end." << endl;
                break;
            }
        }

        // position is out of bounds
        if(temp == NULL){
            //if new data is first term, use add first
            if(head == NULL){
                addFirst(data);
            }
            // otherwise, use append
            else{
                append(data);
            }
        }
        // position is within bounds
        else{
            // create and insert new data
            Node* newData = new Node(data);
            newData->next = temp->next; 
            temp->next = newData;
        }
    }

    // Function to delete the first occurrence of a node with the given value
    void deleteNode(int data) {
        // case 1: empty LL
        if(head == NULL){
            cout << "List is empty." << endl;
            return;
        }

        // case 2: target is first element, so head must be updated
        if(head->val == data){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // case3: otherwise we must iterate through 
        Node* target = head->next;
        Node* temp = head;
        // iterate until target points to the target value, and temp is the element before it
        while(target != NULL && target->val != data){
            target = target->next;
            temp = temp->next;
        }
        // case 3a: the term is not found
        if(target == NULL){
            cout << "Value " << data << " not found in the list." << endl;
            return; 
        }
        // case 3b: target is found
        temp->next = target->next;
        delete target;
    }

    // Function to search for an element in the list.
    // Returns a pointer to the node if found, otherwise returns NULL.
    Node* search(int data) {
        Node* temp = head;
        // check every value until we reach end of list
        while(temp != NULL){
            if(temp->val == data){
                return temp;
            }
            temp = temp->next;
       }
       // if we reach end of list without finding target, return NULL
       return NULL;
    }
    

    // Function to display the linked list
    void display() {
        Node* current = head;
        cout << "Linked List: ";
        while (current != NULL) {
            // Uncomment the line below to display the data
            // Here we assume the data have one element of type int and one element of pointer type
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

        // Function to remove and return the first element of the list
    int pop() {
        if (head == NULL) {
            throw runtime_error("List is empty. Cannot pop.");
        }
        Node* temp = head;
        head = head->next;
        cout << temp->val;
        delete temp;
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
}
