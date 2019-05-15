#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF pow(10, 12)

struct Edge {
    int a;
    int b;
    ll c;
};

vector<ll> BellmanFord(int N, int M, vector<Edge> edges){
    vector<ll> dist(N,-INF);
    dist[0] = 0;


    for(int i = 0; i < N; i++) {
        bool changedFlag = false;

        for (int j = 0; j < M; j++){
            int a = edges[j].a;
            int b = edges[j].b;
            ll c = edges[j].c;

            if(dist[a] == -INF)continue;  //aがまだ到達していないノードなら無視

            if(dist[b] < dist[a] + c){
                dist[b] = dist[a] + c;
                if(i == N-1 && b == N-1)changedFlag = true;
            }
        }

        if(changedFlag == true){
            dist[N-1] = INF;
            return dist;
        }
    }
    
    return dist;
}

int main(){
    int N,M;
    cin >> N >> M;

    vector<Edge> edges(M);

    int a,b;
    ll c;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edges[i] = Edge{--a, --b, c};
    }

    vector<ll> dist = BellmanFord(N, M, edges);

    // for(int i = 0; i < N; i++) {
    //     cout << dist[i] << endl;
    // }

    if(dist[N-1] == INF){
        cout << "inf" << endl;
    }else{
        cout << dist[N-1] << endl;
    }


    return 0;
}