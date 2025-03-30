#include <iostream>
#include <fstream>
using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Constructor initializes an empty list
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    // Destructor to free allocated memory
    ~DoublyLinkedList() {
        // same as SLL
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    // Function to add an element at the beginning of the list
    void addFirst(int data) {
        Node* newData = new Node(data);      // new data
        // if LL is empty
        if(head == NULL){
            head = newData;
            tail = head;
        }
        else{
            head->prev = newData;               // new <- old
            newData->next = head;               // new <-> old
            head = newData;                     // head -> new
        }
    }

    // Function to append an element at the end of the list
    void append(int data) {
        Node* newData = new Node(data);            // new data
        // if LL is empty
        if(head == NULL){
            head = newData;
            tail = head;
        }
        else{
            tail->next = newData;                 // old -> new
            newData->prev = tail;                 // old <-> new
            tail = newData;                       // tail -> new
        }
    }

    // Function to insert an element at a specific position (0-indexed)
    void insert(int data, int pos) {
        // If position is 0, use add first
        if(pos == 0){
            addFirst(data);
            return;
        }

        // error message for negative index
        else if(pos < 0){
            cout << "insert error: position can't be negative" << endl;
            return;
        }

        // iterate through the list, stopping if we hit the end of the DLL before reaching the desired position
        Node* temp = head;                      // temp to traverse
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL || temp->next == NULL){                   // NULL hit -> append at end
                append(data);
                return;
                
            }                           
            temp = temp->next;              // otherwise, traverse as normal            
        }

        // if we reached the position without errors, add the data as normal
        Node* newData = new Node(data);
        newData->prev = temp;
        newData->next = temp->next;
        if (temp->next != NULL) { 
            temp->next->prev = newData;
        }
        temp->next = newData;

        // if the new term is the last term, update tail
        if(newData->next == NULL){
            tail = newData;
        }
    }

    // Function to delete the node at a specific index (0-indexed)
    void deleteAtIndex(int index) {
        // if the index is Invalid or the list is empty
        if(index < 0 || head == NULL){
            cout << "Invalid index or empty list." << endl;
            return;
        }

        // iterate through the DLL
        Node* temp = head;
        for(int i = 0; i < index; i++){
            if(temp->next == NULL){
                cout << "Index out of bounds." << endl;
                return;
            }
            temp = temp->next;
        }

        // if we delete the first term, head must be updated
        if(temp == head){
            head = temp->next;
            if(head != NULL){
                head->prev = NULL;
            }
            else{
                tail == NULL;
            }
        }
        // if we delete the last term, tail must be updated
        else if(temp == tail){
            tail = temp->prev;
            tail->next = NULL;
        }
        // otherwise, remove as normal by linking the terms before and after temp together
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to search for an element in the list.
    // Returns a pointer to the node if found, otherwise returns nullptr.
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

    // Function to check whether the doubly linked list is circular using two pointers.
    // The list is considered circular if there is a cycle in the next pointers.
    bool isCircularTwoPointer() {
        // if the list is empty return false
        if(head == NULL){
            return false;
        }
        Node* slow = head;
        Node* fast = head;

        // make sure that we don't reach NULL
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // if the two pointers point ot the same node, then the LL is circular
            if(slow == fast){
                return true;
            }
        }
        // if we reach NULL, then the LL is not circular
        return false;
    }

    // Function to display the doubly linked list
    void display() {
        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current != NULL) {
            // Uncomment the line below to display the data
            // Here we assume the data have one element of type int and one element of pointer type

            cout << current->val << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
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
