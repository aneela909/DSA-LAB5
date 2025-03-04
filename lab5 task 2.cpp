#include <iostream>
using namespace std;

struct Node {
    int rainfall;
    int day;
    Node* next;
    Node* prev;
};


void insertAtEnd(Node*& head, Node*& tail, int rainfall, int day) {
    Node* newNode = new Node();
    newNode->rainfall = rainfall;
    newNode->day = day;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        newNode->prev = nullptr;
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void analyzeRainfall(Node* head) {
    if (head == nullptr) {
        cout << "No data available.\n";
        return;
    }

    int total = 0, count = 0, highest = head->rainfall, lowest = head->rainfall, highDay = 1, lowDay = 1;
    Node* temp = head;

    while (temp != nullptr) {
        total += temp->rainfall;
        if (temp->rainfall > highest) {
            highest = temp->rainfall;
            highDay = temp->day;
        }
        if (temp->rainfall < lowest) {
            lowest = temp->rainfall;
            lowDay = temp->day;
        }
        temp = temp->next;
        count++;
    }

    cout << "Total Rainfall: " << total << " mm\n";
    cout << "Average Weekly Rainfall: " << (total / count) << " mm\n";
    cout << "Highest Rainfall: " << highest << " mm on Day " << highDay << "\n";
    cout << "Lowest Rainfall: " << lowest << " mm on Day " << lowDay << "\n";
}


void getRainfallAfter5th(Node* head) {
    Node* temp = head;
    for (int i = 0; i < 5; i++) {
        if (temp == nullptr) {
            cout << "Not enough days in the record.\n";
            return;
        }
        temp = temp->next;
    }

    if (temp != nullptr)
        cout << "Rainfall after 5th day: " << temp->rainfall << " mm\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int rainfall;

    for (int i = 1; i <= 7; i++) {
        do {
            cout << "Enter rainfall for day " << i << ": ";
            cin >> rainfall;
            if (rainfall < 0)
                cout << "Invalid input! Rainfall cannot be negative.\n";
        } while (rainfall < 0);

        insertAtEnd(head, tail, rainfall, i);
    }

    analyzeRainfall(head);
    getRainfallAfter5th(head);

}
