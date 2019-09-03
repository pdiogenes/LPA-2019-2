#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    DFSutil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int s, int d);
    bool temCaminho(int s, int d);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

Graph::temCaminho(int s, int d){
    
}

int main(){
    int N, M;
    cin >> N >> M;

    bool read = true;

    while(read){
        if(N == 0 && M == 0) read = false;
        else{
            Graph g(M);
            int V, W, P;
            for (size_t i = 0; i < M; i++){
                cin >> V >> W >> P;
                V--; W--;

                if(P == 1){
                    g.addEdge(V, W);
                }
                else{
                    g.addEdge(V, W);
                    g.addEdge(W, V);
                }
            }
            
        }
    }


    return 0;
}