#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct Stack {
    int data[MAX_SIZE + 1]; // 0 Stack kosong
    int TOP;
};

void createEmpty(Stack *s) {
    s->TOP = 0;
}

bool isEmpty(Stack *s) {
    return s->TOP == 0;
}

bool isFull(Stack *s) {
    return s->TOP == 10;
}

void push(Stack *s, int data) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    }

    s->TOP++;
    s->data[s->TOP] = data;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        cout << "Stack Kosong!" << endl;;
        return;
    }
    
    cout << "Nilai TOP adalah " << s->data[s->TOP] << endl;
    s->TOP--;
}

int main() {
    Stack* stack;
    createEmpty(stack);
    int temp;
    char answer = 'y';
    
    while (answer != 'n') {
        std::cout << "masukkan nilai tumpukan baru ? ";
        std::cin >> temp; // 3, 5, 7
        push(stack, temp); // push belum dibuat
        
        std::cout << "mau isi tumpukan baru ?[y/n] ";
        std::cin >> answer;
    }

    // Pop
    while (!isEmpty(stack)) {
        pop(stack);
    }
    return 0;
}