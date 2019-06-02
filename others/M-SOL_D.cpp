#include <bits/stdc++.h>
using namespace std;

struct Ver_cnt{
    int cnt;
    int num;

    bool operator<(const Ver_cnt &another) const
    {
        return cnt < another.cnt;
    };
};

int main(){
    int N;
    cin >> N;
    
    int a[N-1],b[N-1];
    vector<int> c(N);
    vector<vector<int> > edge(N);
    
    for(int i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;

        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }

    for(int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    vector<int> leafs;
    deque<int> stack;
    vector<int> visited(N,0);
    for(int i = 0; i < N; i++) {
        if(edge[i].size() == 1){
            leafs.push_back(i);
            stack.push_back(i);
            visited[i] = 1;
        }
    }

    vector<int> values(N, -1);
    int j=0;
    for(int i; i<leafs.size(); i++){
        values[leafs[i]] = c[j];
        j++;
    }

    
    while(!stack.empty()){
        int node = stack.front();
        stack.pop_front();

        for(int i=0; i < edge[node].size(); i++){
            int n = edge[node][i];
            
            if(visited[n] == 1)continue;


            values[n] = c[j];
            j++;
            visited[n] = 1;
            stack.push_back(n);
        }
    }

    int ans = 0;
    for(int i = 0; i < N-1; i++) {
        if(values[a[i]] > values[b[i]]){
            ans += values[b[i]];
        }else{
            ans += values[a[i]];
        }
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++) {
        cout << values[i] << endl;
    }
    return 0;
}
