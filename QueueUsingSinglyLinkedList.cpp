#include<iostream>

using namespace std;

// Node class to represent elements in the queue
class Node {
public:
    int key;   // Key of the node
    int data;  // Data (value) of the node
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

// Queue class to implement queue operations
class Queue {
public:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

    // Constructor to initialize the queue
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    // Check if a node with a given key exists in the queue
    bool checkIfNodeExist(Node* n) {
        Node* temp = front;
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

    // Enqueue a node into the queue
    void enqueue(Node* n) {
        if (isEmpty()) {
            front = n;
            rear = n;
            cout << "Node ENQUEUED successfully" << endl;
        } else if (checkIfNodeExist(n)) {
            cout << "Node already exists with this Key value. Enter a different Key value" << endl;
        } else {
            rear->next = n;
            rear = n;
            cout << "Node ENQUEUED successfully" << endl;
        }
    }

    // Dequeue a node from the queue
    Node* dequeue() {
        Node* temp = NULL;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            temp = front;
            if (front == rear) {
                front = NULL;
                rear = NULL;
            } else {
                front = front->next;
            }
        }
        return temp;
    }

    // Count the number of nodes in the queue
    int count() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display all nodes in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "All values in the Queue are :" << endl;
            Node* temp = front;
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->data << ")" << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate the queue operations
int main() {
    Queue q; // Create a queue object
    int option, key, data;

    do {
        // Display menu for queue operations
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl << endl;
        cin >> option;

        // Create a new node for user input
        Node* new_node = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "ENQUEUE Function Called -" << endl;
            cout << "Enter KEY and VALUE of NODE to ENQUEUE in the Queue" << endl;
            cin >> key;
            cin >> data;
            new_node->key = key;
            new_node->data = data;
            q.enqueue(new_node);
            break;
        case 2:
            cout << "DEQUEUE Function Called - " << endl;
            new_node = q.dequeue();
            if (new_node != NULL) {
                cout << "Dequeued Value is: (" << new_node->key << "," << new_node->data << ")";
                delete new_node;
            }
            cout << endl;
            break;
        case 3:
            cout << "isEmpty Function Called - " << endl;
            if (q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is NOT Empty" << endl;
            break;
        case 4:
            cout << "Count Function Called - " << endl;
            cout << "No of nodes in the Queue: " << q.count() << endl;
            break;
        case 5:
            cout << "Display Function Called - " << endl;
            q.display();
            cout << endl;
            break;
        case 6:
            system("cls"); // Clear screen (Note: this may not work on all systems)
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
