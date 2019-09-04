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
    list<bool> temCaminho();
};

Graph::Graph(int size){
    this->size = size;
    adj = new list<int>[size];
}

void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}

list<bool> Graph::temCaminho(){
    
    list<bool> r;

    

    for(size_t i = 0; i < size; i++){
        for(size_t j = i; j < size; j++){
            bool *visited = new bool[size];
            for(size_t i = 0; i < size; i++) visited[i] = false;
            
            cout << "executando de " << i << " para " << j << endl;
            DFSutil(i, visited);
            if(visited[j]) r.push_back(true); 
        }
    }

    return r;
}

void Graph::DFSutil(int v, bool visited[]){
    visited[v] = true;
    cout << "visitou vertice " << v << endl;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i]) DFSutil(*i, visited);
    }

}

int main(){
    bool read = true;

    while(read){
        int N, M;
        cin >> N >> M;

        if(N == 0 && M == 0) read = false;
        else{
            Graph g(M);
            int V, W, P;
            for (size_t i = 0; i < M; i++){
                cin >> V >> W >> P;
                V--; W--;

                if(P == 1){
                    g.addEdge(V, W);
                    cout << "vai de " << V << " para " << W << endl;
                }
                else{
                    g.addEdge(V, W);
                    g.addEdge(W, V);
                    cout << "vai de " << V << " para " << W << " e vice versa" << endl;
                }
                
            }
            list<bool> r = g.temCaminho();

            //r ? cout << "1" : cout << "0";
            //cout << endl;
        
        }
    }


    return 0;
}