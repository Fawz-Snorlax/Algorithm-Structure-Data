#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Graph {
    int vertices;
    bool directed = false;
    int Matrix[TABLE_SIZE][TABLE_SIZE];
};

void createEmpty(Graph* graph, int vertices) {
    if (vertices > TABLE_SIZE) {
        cout << "Error: Number of vertices exceeds table size." << endl;
        return;
    }

    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->Matrix[i][j] = 0;
        }
    }
}

void insertGraph(Graph* graph, int src, int dest, int weight, bool directed = false) {
    graph->directed = directed;
    graph->Matrix[src][dest] = weight;
    if (!graph->directed) {
        graph->Matrix[dest][src] = weight;
    }
}

void displayAdjMatrix(Graph* graph) {
    if (graph->vertices > TABLE_SIZE) return;
    
    cout << "Adjacency Matrix:" << endl;
    
    int vertices = graph->vertices;
    cout << "  ";
    for (int i = 0; i < vertices; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << " ";
        for (int j = 0; j < vertices; j++) {
            cout << graph->Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayAdjList(Graph* graph) {
    if (graph->vertices > TABLE_SIZE) return;

    cout << "Adjacency List:" << endl;

    for (int i = 0; i < graph->vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->Matrix[i][j] != 0) {
                cout << j;
                if (graph->Matrix[i][j] != 1) { 
                    cout << " (" << graph->Matrix[i][j] << ")";
                }
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void displayEdgeList(Graph* graph) {
    if (!graph || graph->vertices > TABLE_SIZE) return;

    cout << "Edge List:" << endl;

    // jika undirected, pastikan untuk hanya mencetak satu arah (i -> j) untuk setiap edge
    if (!graph->directed) {
        for (int i = 0; i < graph->vertices; i++) {
            for (int j = i + 1; j < graph->vertices; j++) {
                if (graph->Matrix[i][j] != 0) {
                    cout << i << " -> " << j;
                    if (graph->Matrix[i][j] != 1) { 
                        cout << " (" << graph->Matrix[i][j] << ")";
                    }
                    cout << endl;
                }
            }
        }
    } else { // jika directed, cetak semua arah
        for (int i = 0; i < graph->vertices; i++) {
            for (int j = 0; j < graph->vertices; j++) {
                if (graph->Matrix[i][j] != 0) {
                    cout << i << " -> " << j;
                    if (graph->Matrix[i][j] != 1) { 
                        cout << " (" << graph->Matrix[i][j] << ")";
                    }
                    cout << endl;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    Graph graphUDUW, graphUDW, graphDUW, graphDW;
    createEmpty(&graphUDUW, 4);
    createEmpty(&graphUDW, 4);
    createEmpty(&graphDUW, 4);
    createEmpty(&graphDW, 4);
    // insertGraph(graph, source, destination, weight, directed)

    // UD/UW graph
    cout << "- GRAFIK UNDIRECTED/UNWEIGHTED" << endl;
    insertGraph(&graphUDUW, 0, 1, 1);
    insertGraph(&graphUDUW, 0, 2, 1);
    insertGraph(&graphUDUW, 1, 2, 1);
    insertGraph(&graphUDUW, 1, 3, 1);
    insertGraph(&graphUDUW, 2, 3, 1);

    displayAdjMatrix(&graphUDUW);
    displayAdjList(&graphUDUW);
    displayEdgeList(&graphUDUW);

    // UD/W graph
    cout << "- GRAFIK UNDIRECTED/WEIGHTED" << endl;
    insertGraph(&graphUDW, 0, 1, 2);
    insertGraph(&graphUDW, 0, 2, 4);
    insertGraph(&graphUDW, 1, 2, 3);
    insertGraph(&graphUDW, 1, 3, 2);
    insertGraph(&graphUDW, 2, 3, 5);

    displayAdjMatrix(&graphUDW);
    displayAdjList(&graphUDW);
    displayEdgeList(&graphUDW);

    // D/UW graph
    cout << "- GRAFIK DIRECTED/UNWEIGHTED" << endl;
    insertGraph(&graphDUW, 0, 1, 1, true);
    insertGraph(&graphDUW, 0, 2, 1, true);
    insertGraph(&graphDUW, 1, 2, 1, true);
    insertGraph(&graphDUW, 1, 3, 1, true);
    insertGraph(&graphDUW, 2, 3, 1, true);

    displayAdjMatrix(&graphDUW);
    displayAdjList(&graphDUW);
    displayEdgeList(&graphDUW);

    // D/W graph
    cout << "- GRAFIK DIRECTED/WEIGHTED" << endl;
    insertGraph(&graphDW, 0, 1, 2, true);
    insertGraph(&graphDW, 0, 2, 4, true);
    insertGraph(&graphDW, 1, 2, 3, true);
    insertGraph(&graphDW, 1, 3, 2, true);
    insertGraph(&graphDW, 2, 3, 5, true);

    displayAdjMatrix(&graphDW);
    displayAdjList(&graphDW);
    displayEdgeList(&graphDW);

    return 0;
}