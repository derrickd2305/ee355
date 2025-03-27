#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Helper function: Print a linear doubly linked list.
void printLinearList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data << " <-> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

// Helper function: Print a list that may be cyclic.
// It prints up to 'limit' nodes to avoid infinite loops.
void printListWithLimit(Node* head, int limit = 10) {
    Node* cur = head;
    int count = 0;
    while (cur && count < limit) {
        cout << cur->data << " <-> ";
        cur = cur->next;
        count++;
    }
    if (cur) cout << "..." << endl;
    else cout << "NULL" << endl;
}

// Function to detect a cycle using the two-pointer (Floyd's) method.
bool isCircularTwoPointer(Node* head) {
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

int main() {
    
    Node* L1 = new Node{1, NULL, NULL};
    Node* L2 = new Node{2, NULL, NULL};
    Node* L3 = new Node{3, NULL, NULL};
    Node* L4 = new Node{4, NULL, NULL};
    Node* L5 = new Node{5, NULL, NULL};

    L1->next = L2;  L2->prev = L1;
    L2->next = L3;  L3->prev = L2;
    L3->next = L4;  L4->prev = L3;
    L4->next = L5;  L5->prev = L4;

    cout << "Linear Doubly Linked List:" << endl;
    printLinearList(L1);
    cout << "Cycle detected: " << (isCircularTwoPointer(L1) ? "Yes" : "No") << "\n\n";

    
    Node* C1 = new Node{10, NULL, NULL};
    Node* C2 = new Node{20, NULL, NULL};
    Node* C3 = new Node{30, NULL, NULL};
    Node* C4 = new Node{40, NULL, NULL};
    Node* C5 = new Node{50, NULL, NULL};

    C1->next = C2;  C2->prev = C1;
    C2->next = C3;  C3->prev = C2;
    C3->next = C4;  C4->prev = C3;
    C4->next = C5;  C5->prev = C4;

    
    C5->next = C3;

    cout << "Doubly Linked List with a small cycle (limited output):" << endl;
    printListWithLimit(C1, 10);
    cout << "Cycle detected: " << (isCircularTwoPointer(C1) ? "Yes" : "No") << "\n\n";

    
    delete L1; delete L2; delete L3; delete L4; delete L5;
    
    C5->next = NULL;
    delete C1; delete C2; delete C3; delete C4; delete C5;

    return 0;
}
