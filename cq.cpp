#include <bits/stdc++.h>
using namespace std;

class Circular_q {
public:
    int arr[30], n;
    int front = -1, rear = -1;

    Circular_q() {
        cout << "Enter the size of Queue: ";
        cin >> n;
    }

    void disp() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % n;
        }
        cout << endl;
    }

    void enque() {
        cout << "Enter the number to be enqueued: ";
        int a; cin >> a;
        if (front == -1 && rear == -1) {
            arr[0] = a;
            front = rear = 0;
        }
        else if ((rear + 1) % n == front) {
            cout << "Overflow\n";
        }
        else {
            rear = (rear + 1) % n;
            arr[rear] = a;
        }
    }

    void deque() {
        if (front == -1) {
            cout << "Underflow\n";
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % n;
        }
    }
};

int main() {
    Circular_q n;
    int ch = 0;
    while (ch != 4) {
        cout << "\n1. Display Queue\n2. Enqueue\n3. Dequeue\n4. Exit\nSelect operation: ";
        cin >> ch;
        switch (ch) {
            case 1: n.disp(); break;
            case 2: n.enque(); break;
            case 3: n.deque(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Select Correct Option\n"; break;
        }
    }
    return 0;
}

