#include <bits/stdc++.h>
using namespace std;


struct Edge{
    int to;
    long long w;
};

int main(){
    int N;
    cin >> N;

    int u[N], v[N];
    long long w[N];

    for(int i = 0; i < N-1; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }

    vector<vector<Edge>> graph(N);
    for(int i = 0; i < N-1; i++) {
        graph[u[i]].push_back(Edge{v[i],w[i]});
        graph[v[i]].push_back(Edge{u[i],w[i]});
    }

    queue<int>q;
    int color[N];
    for(int i = 0; i < N; i++) {
        color[i] = -1;
    }
    color[0] = 0;
    q.push(0);
    
    do{
        int i = q.front();
        q.pop();
        for(int j = 0; j < graph[i].size(); j++){
            int to = graph[i][j].to;
            int w = graph[i][j].w;

            if(color[to] > -1)continue;

            if(w % 2 == 0){
                color[to] = color[i];
                q.push(to);
            }else{
                color[to] = 1 - color[i];
                q.push(to);
            }
        }
    }while(!q.empty());

    for(int i = 0; i < N; i++) {
        cout << color[i] << endl;
    }



    return 0;
}