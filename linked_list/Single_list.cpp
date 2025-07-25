#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at given position (1-based index)
    void deleteAtPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        int count = 1;

        while (curr != nullptr && count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) {
            cout << "Position out of bounds.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // Display list
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Display in reverse
    void displayReverseHelper(Node* node) {
        if (node == nullptr) return;
        displayReverseHelper(node->next);
        cout << node->data << " <- ";
    }

    void displayReverse() {
        cout << "Reverse: ";
        displayReverseHelper(head);
        cout << "NULL\n";
    }

    // Check if list is circular
    bool isCircular() {
        if (head == nullptr) return false;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);
    list.insertAtBeginning(1);

    list.display();              // List: 1 -> 5 -> 10 -> 20 -> 30 -> NULL

    list.deleteAtEnd();          // Delete last
    list.display();              // List: 1 -> 5 -> 10 -> 20 -> NULL

    list.deleteAtPosition(3);    // Delete position 3 (10)
    list.display();              // List: 1 -> 5 -> 20 -> NULL

    list.displayReverse();       // Reverse: 20 <- 5 <- 1 <- NULL

    cout << "Is circular? " << (list.isCircular() ? "Yes" : "No") << endl;

    return 0;
}