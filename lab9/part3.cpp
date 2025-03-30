#include <iostream>
#include <fstream>
using namespace std;

// Define the structure for a node in the circular linked list
struct Node {
    int val;
    Node* next;

    // constructor
    Node(int data){
        val = data;
        next = NULL;
    }
};

class CircularQueue {
private:
   Node* tail;
   int count;

public:
    // Constructor initializes an empty queue
    CircularQueue(){
        tail = NULL;
        count = 0;
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        if(tail == NULL){
            return;
        }
        Node* temp1 = tail->next;
        while(temp1 != tail){
            Node* temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
        delete tail;
        tail = NULL;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        if(count == 0){
            return true;
        }
        return false;
    }

    // Function to check if the queue is full
    bool isFull() {
        if(count >= 8){
            return true;
        }
        return false;
    }

    // Function to add an element to the end of the queue (enqueue)
    void enqueue(int data) {
        // if full 
        if(isFull()){
            cout << "Queue is full. Cannot enqueue " << data << "." << endl;
            return;
        }
        
        // if not full
        Node* newData = new Node(data);

        // if new term is first term
        if(tail == NULL){
            tail = newData;
            tail->next = tail;
        }
        else{
            newData->next = tail->next;
            tail->next = newData;
            tail = newData;
        }

        count++;
        
        // Output the information about the enqueued element
        cout << "Enqueued: " << data << " (size: " << count << ")" << endl;
    }

    // Function to remove an element from the front of the queue (dequeue)
    void dequeue() {
        // If the queue is empty
        if(isEmpty()){
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        
        // if not empty
        Node* temp = tail->next;
        // if the element is the only element
        if(tail == tail->next){
            tail = NULL;
        }
        else{            
            tail->next = temp->next;
        }
        count--;

        // Output the information about the dequeued element
        cout << "Dequeued: " << temp->val << " (size: " << count << ")" << endl;
        delete temp;
    }

    // Function to get the front element of the queue (peek)
    int peek() {
        // If the queue is empty
        if(isEmpty()){
            cout << "Queue is empty." << endl;
            return -1;
        }

        // if queue is not empty
        return tail->next->val;
    }

    // Function to display the queue elements
    void display() {
        // If the queue is empty
        if(isEmpty()){
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = tail->next;
        cout << "Circular Queue: ";
        while(temp != tail){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << tail->val << " -> (back to head)" << endl;
    }
};

int main() {
    // Open the input file "input_part3.txt"
    ifstream infile("input_part3.txt");
    if (!infile) {
        cerr << "Error opening input_part3.txt" << "\n";
        return 1;
    }
    
    // Redirect standard input to read from the file
    cin.rdbuf(infile.rdbuf());

    int T;
    cin >> T;
    string command;
    CircularQueue cq;
    
    // Process T commands from input_part3.txt
    for (int i = 0; i < T; i++){
        cin >> command;
        if (command == "enqueue") {
            int x;
            cin >> x;
            cq.enqueue(x);
        } else if (command == "dequeue") {
            cq.dequeue();
        } else if (command == "peek") {
            int front = cq.peek();
            if(front != -1)
                cout << "Front element: " << front << "\n";
        } else if (command == "display") {
            cq.display();
        } else {
            cout << "Unknown command: " << command << "\n";
        }
    }
    
    return 0;
}
