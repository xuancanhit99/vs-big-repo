////Find the shortest path between two nodes using the Floyd Warshall Algorithm in a undirected and weighted graph
#include <iostream>
#include <vector>
#include <list> 
#include <iomanip>
// Program to find the shortest  
// path between any two nodes using  
// Floyd Warshall Algorithm.  
using namespace std;

#define MAXN 100  
// Infinite value for array  
const int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

// Initializing the distance and  
// Next array  
void initialise(int V, vector<vector<int> >& graph) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];

            // No edge between node  
            // i and j  
            if (graph[i][j] == INF)
                Next[i][j] = -1;
            else
                Next[i][j] = j;
        }
    }
}

// Function construct the shotest  
// path between u and v  
vector<int> constructPath(int u, int v) {
    // If there's no path between  
    // node u and v, simply return  
    // an empty array  
    if (Next[u][v] == -1)
        return {};

    // Storing the path in a vector  
    vector<int> path = { u };
    while (u != v) {
        u = Next[u][v];
        path.push_back(u);
    }
    return path;
}

// Standard Floyd Warshall Algorithm  
// with little modification Now if we find  
// that dis[i][j] > dis[i][k] + dis[k][j]  
// then we modify next[i][j] = next[i][k]  
void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // We cannot travel through  
                // edge that doesn't exist  
                if (dis[i][k] == INF || dis[k][j] == INF)
                    continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

// Print the shortest path  
void printPath(vector<int>& path)
{
    int n = path.size();
    for (int i = 0; i < n - 1; i++)
        cout << path[i] << " -> ";
    cout << path[n - 1] << endl;
}

// Distance shortest
int printDistance(int src, int dest) {
    return dis[src][dest];
}

void newGraph(vector<vector<int>>& graph, int sizeV) {
    graph.resize(sizeV);
    for (int i = 0; i < sizeV; ++i)
        graph.at(i).resize(sizeV);
    for (int i = 0; i < sizeV; i++) {
        for (int j = 0; j < sizeV; j++) {
            if (i == j)
                graph.at(i).at(j) = 0;
            else if (i != j)
                graph.at(i).at(j) = INF;
        }
    }
}

void Insert(vector<vector<int>>& graph, int r, int c, int val) {
    graph.at(r).at(c) = val;
}

void Input(vector<vector<int>>& graph) {
    int r, c, val, connect;
    cout << "Enter number of connections you want: "; cin >> connect;
    for (int i = 0; i < connect; i++) {
        cout << "Enter vertex src, dest and weighted graph: "; cin >> r >> c >> val;
        Insert(graph, r, c, val);
        Insert(graph, c, r, val);
    }
}


int main() {
    vector<vector<int>> graph;
    vector<int> path;
    int sizeV, src, dest;
    cout << "Program find the shortest path between two nodes using the" << endl
         << "Floyd Warshall Algorithm in a undirected and weighted graph." << endl << endl;
    cout << "Enter number of vertices in the graph: "; cin >> sizeV;
    sizeV++;
    newGraph(graph, sizeV);
    while (1) {
        int choose;
        cout << "1. Connecting 2 vertices." << endl;
        cout << "2. Shortest path from src to dest." << endl;
        cout << "3. Exit." << endl;
        cout << "Please choose: "; cin >> choose;
        switch (choose) {
        case 1:
            graph.resize(sizeV);
            Input(graph);
            break;
        case 2:
            initialise(sizeV, graph);
            // Calling Floyd Warshall Algorithm,  
            // this will update the shortest  
            // distance as well as Next array  
            floydWarshall(sizeV);
            // Path from node src to dest  
            cout << "Enter src: "; cin >> src;
            cout << "Enter dest: "; cin >> dest;
            cout << "Shortest path from " << src << " to " << dest << ": ";
            path = constructPath(src, dest); printPath(path);
            cout << "Weight of the shortest path(distance) is: " << printDistance(src, dest) << endl << endl;
            break;
        case 3:
            return 1;
        default:
            cout << "You enter wrong! Please try again." << endl;
            break;
        }
    }
    return 0;
}


//void OutMatrix2D(int a[][MAXN], int sizeV) {
//    for (int i = 0; i < sizeV; i++) {
//        for (int j = 0; j < sizeV; j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//void OutVector(std::vector<std::vector<int>> arr)
//{
//    int rows = arr.size();
//    int columns = arr.at(0).size();
//    for (int i = 0; i < rows; ++i)
//    {
//        for (int j = 0; j < columns; ++j)
//        {
//            if (arr.at(i).at(j) == INF)
//                std::cout << std::setw(5) << "INF";
//            else
//                std::cout << std::setw(5) << arr.at(i).at(j);
//        }
//        std::cout << std::endl;
//    }
//}

// hien so canh
/*
    Insert(graph, 0, 1, 3);
    Insert(graph, 0, 3, 7);
    Insert(graph, 1, 0, 8);

    Insert(graph, 1, 2, 2);
    Insert(graph, 2, 0, 5);

    Insert(graph, 2, 3, 1);
    Insert(graph, 3, 0, 2);


    vector<vector<int> > graph
        = { { 0, 3, INF, 7 },
            { 8, 0, 2, INF },
            { 5, INF, 0, 1 },
            { 2, INF, INF, 0 } };*/