#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int data) : val(data), next(NULL) {}
};

class CLL {
    private:
        Node* head;
    public:
        CLL() : head(NULL) {}

        void insert(int data) {
            Node* newData = new Node(data);

            if (head == NULL) {
                head = newData;
                head->next = head;
                return;
            }

            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newData;
            newData->next = head;
        }

        void remove(int data) {
            if (head == NULL) {
                cout << "No elements to remove" << endl;
                return;
            }

            Node* curr = head;
            Node* prev = NULL;

            // Case: Head is the target
            if (head->val == data) {
                if (head->next == head) { // Only one element in the list
                    delete head;
                    head = NULL;
                    return;
                }

                // Find the last node
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }

                head = head->next; // Move head forward
                last->next = head; // Update last node's next
                delete curr;
                return;
            }

            // Case: Non-head nodes
            while (curr->next != head) {
                if (curr->val == data) {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }

            // If last node is the target
            if (curr->val == data) {
                prev->next = head;
                delete curr;
                return;
            }

            cout << "Value not found" << endl;
        }

        bool search(int data) {
            if (head == NULL) {
                return false;
            }

            Node* temp = head;

            do {
                if (temp->val == data) {
                    return true;
                }
                temp = temp->next;
            } while (temp != head);

            return false;
        }

        void printList() {
            if (head == NULL) {
                cout << "List empty\n";
                return;
            }

            Node* temp = head;

            do {
                cout << temp->val << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
};

int main() {
    CLL cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.printList();

    cout << "Search 30: " << (cll.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 50: " << (cll.search(50) ? "Found" : "Not Found") << endl;

    cll.remove(10); // Removing head
    cll.printList();

    cll.remove(30); // Removing middle
    cll.printList();

    cll.remove(50); // Attempting to remove non-existent element
    cll.printList();

    return 0;
}
