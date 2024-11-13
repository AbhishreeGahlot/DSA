#include <iostream>
using namespace std;

class Deque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Constructor to initialize the deque
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Function to insert an element at the front
    void insertFront(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Deque is full\n";
            return;
        }

        if (front == -1) { // First element to insert
            front = rear = 0;
        } else if (front == 0) { // Wrap around to end
            front = size - 1;
        } else { // Normal case
            front--;
        }

        arr[front] = value;
    }

    // Function to insert an element at the rear
    void insertRear(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Deque is full\n";
            return;
        }

        if (front == -1) { // First element to insert
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) { // Wrap around to start
            rear = 0;
        } else { // Normal case
            rear++;
        }

        arr[rear] = value;
    }

    // Function to delete an element from the front
    int deleteFront() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return -1;
        }

        int result = arr[front];
        arr[front] = -1; // Optional: clear the dequeued position

        if (front == rear) { // Only one element left
            front = rear = -1;
        } else if (front == size - 1) { // Wrap around
            front = 0;
        } else { // Normal case
            front++;
        }

        return result;
    }

    // Function to delete an element from the rear
    int deleteRear() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return -1;
        }

        int result = arr[rear];
        arr[rear] = -1; // Optional: clear the dequeued position

        if (front == rear) { // Only one element left
            front = rear = -1;
        } else if (rear == 0) { // Wrap around
            rear = size - 1;
        } else { // Normal case
            rear--;
        }

        return result;
    }

    // Function to get the front element
    int getFront() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element
    int getRear() {
        if (rear == -1) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[rear];
    }

    // Destructor to clean up the dynamically allocated memory
    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5); // Create a deque of size 5

    dq.insertRear(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertFront(40);
    dq.insertRear(50);

    cout << "Deque after insertions:\n";
    cout << "Front element: " << dq.getFront() << "\n";
    cout << "Rear element: " << dq.getRear() << "\n";

    dq.deleteFront();
    cout << "After deleting from front, front element: " << dq.getFront() << "\n";

    dq.deleteRear();
    cout << "After deleting from rear, rear element: " << dq.getRear() << "\n";

    return 0;
}




output :
 Deque after insertions:
Front element: 40
Rear element: 50
After deleting from front, front element: 20
After deleting from rear, rear element: 30

