#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int data) : val(data), next(NULL){}
};

class CLL{
    private:
        Node* head;
    public:
        CLL() : head(NULL) {}

        void insert(int data){
            Node* newData = new Node(data);

            if(head == NULL){
                head = newData;
                head->next = head;
                return;
            }

            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }

            temp->next = newData;
            newData->next = head;
        }

    void remove(int data){
        if(head == NULL){
            cout << "no elements to remove" << endl;
            return;
        }

        // case: head is target and is only term
        if(head->next == head){
            if(head->val == data){
                delete head;
                head = NULL;
            }
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while(curr->next != head){
            if(curr->val = data){
                prev = head;
                while(prev->next != curr){
                    prev = prev->next;
                }
                prev->next = curr->next;
                delete curr;
                return;
            }
            curr = curr->next;
        }
        cout << "value not found" << endl;

    }

    bool search(int data){
        if(head == NULL){
            return false;
        }

        Node* temp = head;

        do{
            if(temp->val == data){
                return true;
            }
            temp = temp->next;
        }while(temp != head);

        return false;
    }

    void printList(){
        if(head == NULL){
            cout << "list empty\n";
            return;
        }

        Node* temp = head;

        do{
            cout << temp->val << " ";
            temp = temp->next;
        }while(temp != head);
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

    cll.remove(50); 
    cll.printList();

    return 0;
}
