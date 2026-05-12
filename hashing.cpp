// ilustrasi
// [
//     0: first(newNode) -> node1, newNode[node1, node2, node3],
//     1: first, list[],
//     2: first, list[],
//     3: first, list[],
//     4: first, list[],
//     5: first, list[],
//     6: first, list[],
//     7: first, list[],
//     8: first, list[],
//     9: first, list[]
// ]

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    int data;
    Node* next;
};

struct Hash {
    Node* first;
};

int getHashIndex(int key) {
    return key % TABLE_SIZE;
}

void createEmptyHash(Hash hashTable[]){
    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].first = nullptr;
    }
}

Node* allocation (int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void deallocation (Node* node) {
    delete node;
}

void insertNode (Hash &hash, int data) {
    Node* newNode = allocation(data);
    if (hash.first == nullptr) {
        hash.first = newNode;
    } else {
        Node* temp = hash.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// deleteFirst
// [f0, 1, 2, 3]
// [f1, 2, 3]

void deleteFirst (Hash &hash) {
    if (hash.first != nullptr) {
        Node* delNode = hash.first;
        hash.first = hash.first->next;
        deallocation(delNode);
    }
}

void deleteLast (Hash &hash) {
    if (hash.first != nullptr) {
        if (hash.first->next == nullptr) {
            deleteFirst(hash);
        } else {
            Node* temp = hash.first;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            deallocation(temp);
        }
    }
}

void insertValue (Hash hashTable[], int data) {
    int index = getHashIndex(data);
    insertNode(hashTable[index], data);
}

void deleteValue (Hash hashTable[], int data) {
    int index = getHashIndex(data);
    Node* temp = hashTable[index].first;

    if (temp->data == data) {
        deleteFirst(hashTable[index]);
    } else {
        while (temp->next != nullptr){
            if (temp->next->data == data) {
                Node* delNode = temp->next;
                temp->next = temp->next->next;
                deallocation(delNode);
                break;
            }
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Data tidak ditemukan!" << endl;
        }
    }
}

void printHash (Hash hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i].first;
        cout << i << ": ";

        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}

int countData(Hash hashTable[]) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].first != nullptr) {
            count++;
        }
    }
    return count;
}

// Soal 1 membuat fungsi logika pencarian
// jika ketemu return "found at index: {}"
// selainnya return "not found"
void searchValue (Hash hashTable[], int data) {
    int index = getHashIndex(data);
    Node* temp = hashTable[index].first;

    while (temp != nullptr) {
        if (temp->data == data) {
            cout << "found at index: " << index << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "not found!" << endl;
}

// Soal 2 linier probing
// dimana N ≤ M/2, input data baru harus berada di range 0 - 99
// N adalah jumlah data dan M adalah bilangan pembagi
// lakukan cek insert untuk memastikan data tidak lebih dari N
// untuk logika insert: newData mod M untuk menghasilkan index
// jika index yang dihasilkan sudah terisi maka
// data digeser ke index selanjutnya
void insertLinearProbing (Hash hashTable[], int data) {
    int N = countData(hashTable);
    if (N >= TABLE_SIZE / 2) {
        cout << "Data sudah mencapai batas maksimal!" << endl;
        return;
    }

    int index = getHashIndex(data);
    int step = 0;

    while (hashTable[index].first != nullptr) {
        step++;
        index = (getHashIndex(data) + step) % TABLE_SIZE;
    }
    insertNode(hashTable[index], data);
}

// Soal 3 Quadratic Probing
// dimana N ≤ M/2, input data baru harus berada di range 0 - 99
// N adalah jumlah data dan M adalah bilangan pembagi
// lakukan cek insert untuk memastikan data tidak lebih dari N
// untuk logika insert: index didapat dari (newData % mod M + step*step) % M
// jika index yang dihasilkan sudah terisi maka step += 1
void insertQuadraticProbing (Hash hashTable[], int data) {
    int N = countData(hashTable);
    if (N >= TABLE_SIZE / 2) {
        cout << "Data sudah mencapai batas maksimal!" << endl;
        return;
    }
    
    int index = getHashIndex(data);
    int step = 0;

    while (hashTable[index].first != nullptr) {
        step++;
        index = (getHashIndex(data) + step * step) % TABLE_SIZE;
    }
    insertNode(hashTable[index], data);
}

int main () {
    Hash hashTable[TABLE_SIZE];

    createEmptyHash(hashTable);
    //   N ≤ M/2 (khusus linier probing dan quadratic probing)
    //   N adalah jumlah data
    //   M adalah bilangan pembagi (10)
    //   0: 10
    //   1: 11, 31
    //   2: 
    //   3: 
    //   4: 20
    //   5: 5, 15
    //   6: 25
    //   7: 
    //   8: 
    //   9: 

    //   kondisi ketika data belum mencapai batas maksimal
    insertValue(hashTable, 5);
    insertValue(hashTable, 10);
    insertValue(hashTable, 11);
    insertValue(hashTable, 31);
    insertValue(hashTable, 15);
    insertLinearProbing(hashTable, 25);
    insertQuadraticProbing(hashTable, 20);
    
    printHash(hashTable);
    
    //   kondisi ketika data sudah mencapai batas maksimal
    insertValue(hashTable, 14);
    insertLinearProbing(hashTable, 30);
    insertQuadraticProbing(hashTable, 12);
    
    printHash(hashTable);

    return 0;
}
