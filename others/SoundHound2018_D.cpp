#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000000000

typedef pair<ll, int> pi;
typedef vector<vector<int>> vv;

/********************************
  dijkstra
   - dist:  グラフの枝（隣接行列）
   - s:     出発点
   - n:     頂点数
********************************/
vector<ll> dijkstra(vector<vector<pi>> dist, int s, int n) {
    vector<ll> cost(n, INF); //sから各枝への最小コスト
    for (int i = 0; i < n; i++) {
        cost[i] = INF;
    }
    
    for (int i = 0; i < dist[s].size(); i++){
        cost[dist[s][i].first] = dist[s][i].second;
    }
    cost[s] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq; //ヒープ　各ノードの型は <cost, vartex_num>
    //全ての頂点をヒープに入れる
    for(int i = 0; i < n; i++) {
        if(i == s)continue;
        pq.push(make_pair(cost[i], i));
    }

    while (!pq.empty()) {
        pi min_v = pq.top(); //コスト最小のノード
        pq.pop();

        int w = min_v.second;
        if (cost[w] < min_v.first) continue; //更新済みのノードのため無視

        for (int i = 0; i < dist[w].size(); i++) {
            int k = dist[w][i].first; //見ているノードの番号
            
            if(cost[w] + dist[w][i].second < cost[k]){
                cost[k] = cost[w] + dist[w][i].second;
                pq.push(make_pair(cost[k], k));  //元々あるノードは無視してとりあえずヒープに入れておく
            }
        }
    }
    return cost;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;

    int u[m], v[m], a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> a[i] >> b[i];
        u[i]--;
        v[i]--;
    }
    
    //隣接リスト
    vector<vector<pi>> dist_a(n); // <node_num, cost>
    vector<vector<pi>> dist_b(n);

    for(int i = 0; i < m; i++) {
        dist_a[u[i]].push_back({v[i], a[i]});
        dist_b[u[i]].push_back({v[i], b[i]});
        dist_a[v[i]].push_back({u[i], a[i]});
        dist_b[v[i]].push_back({u[i], b[i]});
    }

    vector<ll> cost_a = dijkstra(dist_a, s, n);
    vector<ll> cost_b = dijkstra(dist_b, t, n);

    vector<ll> cost_sum(n);
    for(int i = 0; i < n; i++) {
        cost_sum[i] = cost_a[i] + cost_b[i];
    }

    ll M = 1000000000000000;
    ll min_array[n];
    min_array[n-1] = cost_sum[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(min_array[i+1] > cost_sum[i]){
            min_array[i] = cost_sum[i];
        }else{
            min_array[i] = min_array[i+1];
        }
    }

    for(int i=0; i<n;i++){
        cout << M - min_array[i] << endl;
    }

    return 0;
}