#include<iostream>

using namespace std;

// Node class to represent elements in the stack
class Node {
public:
    int key;   // Key of the node
    int data;  // Data of the node
    Node* next; // Pointer to the next node

    // Constructors to initialize the node
    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

// Stack class to implement stack operations
class Stack {
public:
    Node* top; // Pointer to the top of the stack

    // Constructor to initialize the stack
    Stack() {
        top = NULL;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Check if a node with a given key exists in the stack
    bool checkIfNodeExist(Node* n) {
        Node* temp = top;
        bool exist = false;
        while (temp != NULL) {
            if (temp->key == n->key) {
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }

    // Push a node onto the stack
    void push(Node* n) {
        if (top == NULL) {
            top = n;
            cout << "Node PUSHED successfully" << endl;
        } else if (checkIfNodeExist(n)) {
            cout << "Node already exists with this Key value. Enter a different Key value" << endl;
        } else {
            Node* temp = top;
            top = n;
            n->next = temp;
            cout << "Node PUSHED successfully" << endl;
        }
    }

    // Pop a node from the stack
    Node* pop() {
        Node* temp = NULL;
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        } else {
            temp = top;
            top = top->next;
        }
        return temp;
    }

    // Peek at the top node of the stack without removing it
    Node* peek() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return NULL;
        } else {
            return top;
        }
    }

    // Count the number of nodes in the stack
    int count() {
        int count = 0;
        Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display all nodes in the stack
    void display() {
        cout << "All values in the Stack are :" << endl;
        Node* temp = top;
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data << ")" << " -> " << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to demonstrate the stack operations
int main() {
    Stack s1; // Create a stack object
    int option, key, data;

    do {
        // Display menu for stack operations
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. peek()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;
        cin >> option;

        // Create a new node for user input
        Node* new_node = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enter KEY and VALUE of NODE to push in the stack" << endl;
            cin >> key;
            cin >> data;
            new_node->key = key;
            new_node->data = data;
            s1.push(new_node);
            break;
        case 2:
            cout << "Pop Function Called - Popped Value: " << endl;
            new_node = s1.pop();
            if (new_node != NULL) {
                cout << "TOP of Stack is: (" << new_node->key << "," << new_node->data << ")";
                delete new_node;
            }
            cout << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (s1.isEmpty()) {
                cout << "Stack is Empty" << endl;
            } else {
                cout << "PEEK Function Called : " << endl;
                new_node = s1.peek();
                if (new_node != NULL) {
                    cout << "TOP of Stack is: (" << new_node->key << "," << new_node->data << ")" << endl;
                }
            }
            break;
        case 5:
            cout << "Count Function Called: " << endl;
            cout << "No of nodes in the Stack: " << s1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            s1.display();
            cout << endl;
            break;
        case 7:
            system("cls"); // Clear screen (Note: this may not work on all systems)
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
