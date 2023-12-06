#include<iostream>

using namespace std;

class CircularQueue {
  private:
    int front;        // Index of the front element in the queue
    int rear;         // Index of the rear element in the queue
    int arr[5];        // Array to store queue elements
    int itemCount;    // Count of items in the queue

  public:
    CircularQueue() {
      itemCount = 0;
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }

    // Check if the queue is empty
    bool isEmpty() {
      if (front == -1 && rear == -1)
        return true;
      else
        return false;
    }

    // Check if the queue is full
    bool isFull() {
      if ((rear + 1) % 5 == front)
        return true;
      else
        return false;
    }

    // Add an element to the rear of the queue (Enqueue)
    void enqueue(int val) {
      if (isFull()) {
        cout << "Queue full" << endl;
        return;
      } else if (isEmpty()) {
        rear = 0;
        front = 0;
        arr[rear] = val;

      } else {
        rear = (rear + 1) % 5;
        arr[rear] = val;

      }
      itemCount++;
    }

    // Remove and return the element from the front of the queue (Dequeue)
    int dequeue() {
      int x = 0;
      if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return x;
      } else if (rear == front) {
        x = arr[rear];
        rear = -1;
        front = -1;
        itemCount--;
        return x;
      } else {
        x = arr[front];
        arr[front] = 0;
        front = (front + 1) % 5;
        itemCount--;
        return x;
      }
    }

    // Return the number of elements in the queue
    int count() {
      return (itemCount);
    }

    // Display all values in the queue
    void display() {
      cout << "All values in the Queue are - " << endl;
      for (int i = 0; i < 5; i++) {
        cout << arr[i] << "  ";
      }
    }

};

int main() {
  CircularQueue q1;
  int value, option;

  // Menu-driven program using a do-while loop
  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;

    // Switch cases for various queue operations
    switch (option) {
    case 0:
      break;

    case 1:
      // Enqueue operation
      cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
      cin >> value;
      q1.enqueue(value);
      break;

    case 2:
      // Dequeue operation
      cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
      break;

    case 3:
      // isEmpty operation
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;

    case 4:
      // isFull operation
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;

    case 5:
      // Count operation
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;

    case 6:
      // Display operation
      cout << "Display Function Called - " << endl;
      q1.display();
      break;

    case 7:
      // Clear screen operation
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);  // Continue the loop until the user chooses to exit

  return 0;
}
