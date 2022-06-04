/*
Class: CIS-7
Authors: Ivan Sebastian Perez, Eric Coria, Marlon Jimenez
Program Desrciption: 
Choice 1: Eric (Trip Planner/ Representation)
Choice 2: Marlon (Cost Effective/ Shortest Path)
Choice 3: Ivan (Adjacencies)
Choice 4: Map/Matrix (DONE)
*/
#include <bits/stdc++.h>
using namespace std;

//A utility function to add an edge in
//an undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraphChoice2(vector<int> adj[], int V)
{
    for (int v = 1; v < V; ++v)
    {
        cout << "\n Most cost effective path " << v;
        for (auto x: adj[v])
           cout << " -> " << x;
        printf("\n");
    }
}
// Data structure to store Adjacency list nodes
struct Node {
    int val, cost;
    Node* next;
};
// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};
class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;
        // point new node to current head
        newNode->next = head;
        return newNode;
    }
    int N;  // number of nodes in the graph
public:
    // An array of pointers to Node to represent
    // adjacency list
     Node **head;
    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);
            // point head pointer to new node
            head[src] = newNode;
            // Uncomment below lines for undirected graph
            newNode = getAdjListNode(src, weight, head[dest]);
            // change head pointer to point to the new node
            head[dest] = newNode;
            
        }
    }
    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
};
// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << " Miles) ";
        ptr = ptr->next;
    }
    cout << endl;
}

/*
//Choice 4: Matrix
void matrixMap(){
// array of graph edges as per above diagram.
    Edge edges[] =
    {
        // (x, y, w) -> edge from x to y having weight w
        { 1, 2, 16 }, { 1, 3, 33 }, { 1, 4, 24 }, { 2, 3, 26 },
        { 3, 4, 30 }, { 4, 2, 18 }
    };
    // Number of vertices in the graph
    int N = 5;
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    Graph graph(edges, n, N);
    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of vertex i
        printList(graph.head[i], i);
    }
 }

*/

// Graph Implementation in C++ without using STL
int main()
{
    // array of graph edges as per above diagram.
    Edge edges[] =
    {
        // (x, y, w) -> edge from x to y having weight w
        { 1, 2, 16 }, { 1, 3, 33 }, { 1, 4, 24 }, { 2, 3, 26 },
        { 3, 4, 30 }, { 4, 2, 18 }
    };
    // Number of vertices in the graph
    int N = 5;
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    Graph graph(edges, n, N);
    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of vertex i
        printList(graph.head[i], i);
    }
    return 0;
}
