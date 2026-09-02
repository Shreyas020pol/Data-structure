#include <iostream>
#include <string>
using namespace std;

#define MAX 100


class ArrayQueue {
    string queue[MAX];
    int front, rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string request) {
        if (rear == MAX - 1) {
            cout << "Array Queue is full!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = request;

        cout << "Request added: " << request << endl;
    }


    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Array Queue is empty!" << endl;
            return;
        }

        cout << "Request processed: " << queue[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    
    void display() {
        if (front == -1) {
            cout << "Array Queue is empty!" << endl;
            return;
        }
        cout << "Array Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " | ";
        }
        cout << endl;
    }
};


struct Node {
    string request;
    Node* next;
};

class LinkedQueue {
    Node *front, *rear;

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }

    
    void enqueue(string request) {
        Node* newNode = new Node;
        newNode->request = request;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Request added: " << request << endl;
    }


    void dequeue() {
        if (front == NULL) {
            cout << "Linked Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Request processed: " << temp->request << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Linked Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Linked Queue: ";
        while (temp!= NULL) {
            cout << temp->request << " | ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    ArrayQueue arrayQueue;
    LinkedQueue linkedQueue;
    int choice;
    string request;

    do {
        cout << "\n========= TICKET RESERVATION SYSTEM ==========" << endl;
        cout << "1. Add request to Array Queue" << endl;
        cout << "2. Process request from Array Queue" << endl;
        cout << "3. Display Array Queue" << endl;
        cout << "4. Add request to Linked List Queue" << endl;
        cout << "5. Process request from Linked List Queue" << endl;
        cout << "6. Display Linked List Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter ticket reservation request: ";
                getline(cin, request);
                arrayQueue.enqueue(request);
                break;
            case 2:
                arrayQueue.dequeue();
                break;
            case 3:
                arrayQueue.display();
                break;
            case 4:
                cout << "Enter ticket reservation request: ";
                getline(cin, request);
                linkedQueue.enqueue(request);
                break;
            case 5:
                linkedQueue.dequeue();
                break;
            case 6:
                linkedQueue.display();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice!= 7);

    return 0;
}
