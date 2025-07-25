#include <iostream>
#include <stack>
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

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // ✅ Check if the linked list is a palindrome using stack
    bool isPalindrome() {
        stack<int> s;
        Node* temp = head;

        // Push all elements to stack
        while (temp) {
            s.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (temp) {
            int top = s.top();
            s.pop();

            if (temp->data != top)
                return false;

            temp = temp->next;
        }

        return true;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(1);

    list.display();

    if (list.isPalindrome()) {
        cout << "The list is a palindrome.\n";
    } else {
        cout << "The list is not a palindrome.\n";
    }

    return 0;
}