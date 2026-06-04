#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct Queue {
    int data[MAX_SIZE + 1];
    int head;
    int tail;
};

void createEmpty(Queue* &q) {
    q = new Queue();
    q->head = 0;
    q->tail = 0;
}

bool isEmpty(Queue *q) {
    return q->head == 0 && q->tail == 0;
}

int countElement(Queue *q) {
    if (isEmpty(q)) return 0;
    if (q->head <= q->tail) return q->tail - q->head + 1;
    return MAX_SIZE - q->head + q->tail + 1;
}

bool isFull(Queue *q) {
    return countElement(q) == MAX_SIZE;
}

void add (Queue *q, int data) {
    if (isFull(q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(q)) {
        q->head = q->tail = 1;
    } else {
        q->tail++;
        if (q->tail == MAX_SIZE + 1) q->tail = 1;
    }
    q->data[q->tail] = data;
}

void pop (Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << q->data[q->head];
    if (q->head == q->tail){
        q->head = q->tail = 0;
    } else {
        q->head++;
        if (q->head == MAX_SIZE + 1) q->head = 1;
    }
}

int main () {
    Queue* queue;
    createEmpty(queue);

    add(queue, 1);
    add(queue, 2);
    add(queue, 3);
    add(queue, 4);
    add(queue, 5);
    add(queue, 6);
    add(queue, 7);
    add(queue, 8);
    add(queue, 9);
    add(queue, 10);
    add(queue, 11); // Queue penuh!

    while (!isEmpty(queue)){
        cout << "Menghapus: "; pop(queue); cout << endl;
    }
    pop (queue);
    return 0;
}