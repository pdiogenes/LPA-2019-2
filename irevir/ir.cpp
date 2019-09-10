#include<iostream>
#include<list>

using namespace std;

class Graph{
    int size;
    list<int> *adj;
    void DFSutil(int v, bool visited[]);
public:
    Graph(int size);
    void addEdge(int s, int d);
    bool temCaminho(int s, int d);
};

Graph::Graph(int size){
    this->size = size;
    adj = new list<int>[size];
}

void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}

void Graph::DFSutil(int v, bool visited[]){
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i]) DFSutil(*i, visited);
    }
}

bool Graph::temCaminho(int s, int d){
    bool *visited = new bool[size];
    for(size_t i = 0; i < size; i++){
        visited[i] = false;
    }

    DFSutil(s, visited);
    return visited[d] ? true : false;
}

int main(){
    bool read = true;
    int N, M;

    while(read){
        cin >> N >> M;

        if(N == 0 && M == 0) read = false;
        else{
            Graph g(N);
            int V, W, P;
            for (size_t i = 0; i < M; i++){
                cin >> V >> W >> P;
                V--; W--;

                if(P == 1){
                    //cout << "vai de " << V << " para " << W << endl;
                    g.addEdge(V, W);
                }
                else{
                    //cout << "vai de " << V << " para " << W << " e vice versa" << endl;
                    g.addEdge(V, W);
                    g.addEdge(W, V);
                }
                
            }

            for(size_t i = 0; i < N; i++){
                for(size_t j = 0; j < N; j++){
                    if(!g.temCaminho(i, j)){
                        cout << "0" << endl;
                        i = N; j = N;
                        break;
                    }
                    else if(i == N-1 && j == N-1 && g.temCaminho(i, j)){
                        cout << "1" << endl;
                    }
                }
            }
        
        }
    }


    return 0;
}