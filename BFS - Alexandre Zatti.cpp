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
        queue<int> q;
        vector<int> level;

        Graph(int vertices){
            level.resize(vertices);
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

        void BFS(int node){
            q.push(node);
            visited[node] = true;
            level[node] = 0;

            cout<<node<<" ";
            while(!q.empty()){
                int s = q.front();
                q.pop();
                for(auto i = adjList[s].begin(); i != adjList[s].end(); i++){
                    if(!visited[*i]){
                        q.push(*i);
                        visited[*i] = true;
                        level[*i] = level[s]+1;
                        cout<<*i<<" ";
                    }
                }
            }
            auto uniqCnt = unique(level.begin(), level.end()) - level.begin();
            cout<<endl;
            cout<<"Profundidade do grafo = "<<uniqCnt-1<<endl;

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
    graph.BFS(0);


    return 0;
}
