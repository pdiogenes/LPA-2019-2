#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    int DFSutil(int v, bool visited[], int count);

public:
    Graph(int V);
    void DFS();
    void addEdge(int s, int d);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}


int Graph::DFSutil(int v, bool visited[], int count){
    visited[v] = true;
    count++;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]) count = DFSutil(*i, visited, count);
    }

    return count;
}

void Graph::DFS(){
    bool *visited = new bool[V];
    for (size_t i = 0; i < V; i++){
        visited[i] = false;
    }

    int count, n = 0;

    for (size_t i = 0; i < V; i++){
        if(visited[i] == false) count = DFSutil(i, visited, 0);
        if(count > n) n = count;
    }

    cout << n << endl;
}

int numCases, N, M;

int main(){
    cin >> numCases;
    while(numCases--){
        cin >> N >> M;
        Graph graph(N);
        int A, B;
        for (size_t i = 0; i < M; i++){
            cin >> A >> B;
            A--; B--;
            graph.addEdge(A, B);
            graph.addEdge(B, A);
        }

        graph.DFS();
        
    }
    

    return 0;
}