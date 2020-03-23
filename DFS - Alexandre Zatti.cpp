#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define LOG(x) cout<<x<<endl;


using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<i64, i64> pi64;


class Graph{
    public:
        vector<vector<int>>adjList;
        vector<bool> visited;

        Graph(int vertices){
            adjList.resize(vertices);
            for(int i = 0; i < vertices; i++){
                visited.pb(false);
            }
        }
        void add(int origin, int dest){
            adjList[origin].push_back(dest);
            adjList[dest].push_back(origin);
        }
        void print(){
            for(auto i : adjList){
                for(auto j : i){
                    LOG(j);
                }
            }
        }

        void DFS(int node) {
            if (visited[node]) {
                return;
            }
            visited[node] = true;
            cout<<node<<" ";
            vector<int> aux = adjList[node];
            for (auto i : aux) {
                DFS(i);
            }
        }
};


int main(){
    ios::sync_with_stdio(false);

    Graph graph(9);

    graph.add(0,1);
    graph.add(0,2);
    graph.add(1,6);
    graph.add(1,5);
    graph.add(2,4);
    graph.add(2,3);
    graph.add(6,7);
    graph.add(7,8);
    graph.DFS(0);


    return 0;
}
