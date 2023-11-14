#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

// Definim o structura pentru a reprezenta muchi
struct Edge {
    int src, dest, weight;
};

// Clasa pentru reprezentarea unui graf neorientat ponderat
class Graph {
public:
    vector<Edge> edges;
    int V, E; // V = numarul de varfuri, E = numarul de muchii

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }
};

// Algoritmul Prim pentru arborele de cost minim
int primMST(Graph& graph) {
    int V = graph.V;
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    int totalWeight = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        for (int v = 0; v < V; v++)
        {
            totalWeight += 1;
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        mstSet[u] = true;

        for (Edge& edge : graph.edges)
        {
            if (edge.src == u && !mstSet[edge.dest] && edge.weight < key[edge.dest])
            {
                key[edge.dest] = edge.weight;
            }
        }

    }

    return totalWeight;
}

// Functie pentru compararea muchiilor in algoritmul Kruskal
bool compareEdges(Edge& a, Edge& b) {
    return a.weight < b.weight;
}

// Gasirea setului al carui reprezentant este v
int find(int parent[], int v) {
    if (parent[v] == -1)
        return v;
    return find(parent, parent[v]);
}

// Unirea a doua seturi
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Algoritmul Kruskal pentru arborele de cost minim
int kruskalMST(Graph& graph) {
    int V = graph.V;
    int E = graph.E;

    vector<Edge> result(V - 1);

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    int parent[V];
    memset(parent, -1, sizeof(parent));
    int totalWeight = 0;
    int e = 0, i = 0;
    while (i < E) {
        totalWeight += 1;

        Edge next_edge = graph.edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }
    return totalWeight;
}

void generateGraph(Graph& graph, int numNodes) {
    // Generarea unui graf complet (fiecare nod este conectat la fiecare alt nod)
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            int weight = rand() % 100 + 1; // Generam un cost random intre 1 si 100
            graph.addEdge(i, j, weight);
            graph.addEdge(j, i, weight); // Daca graful este neorientat, adaugam si muchia inversa
        }
    }
}

int main() {
    int numNodes = 50;

    Graph graph(numNodes, numNodes * (numNodes - 1) / 2); // Numarul maxim de muchii intr-un graf complet

    generateGraph(graph, numNodes);
    // Algoritmul Prim
    auto start = chrono::steady_clock::now();
    int primWeight = primMST(graph);
    auto end = chrono::steady_clock::now();
    auto primTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Algoritmul Kruskal
    start = chrono::steady_clock::now();
    int kruskalWeight = kruskalMST(graph);
    end = chrono::steady_clock::now();
    auto kruskalTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Afiseaza rezultatele
    cout << "Algoritmul Prim: " << primWeight << " (Timp: " << primTime << " microsecunde)\n";
    cout << "Algoritmul Kruskal: " << kruskalWeight << " (Timp: " << kruskalTime << " microsecunde)\n";

    return 0;
}
