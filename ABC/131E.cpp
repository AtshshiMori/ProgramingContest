#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r){
    if(r == 0)return 1;
    return comb(n, r-1) * (n-r+1) / r;
}

void output( vector<int> u, vector<int> v){
    cout << u.size() << endl;
    for(int i =0; i < u.size(); i++){
        cout << u[i] << " " << v[i] << endl;
    }
}

int main(){
    int N, K;

    cin >> N >> K;
    
    int maxK = comb(N-1, 2);
    int limit = maxK - K;
    int count = 0;

    if(limit < 0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> u,v;
    for(int i=2; i <= N; i++){
        u.push_back(1);
        v.push_back(i);
    }
    // K : maxK;
   
    for(int i = 2; i < N; i++){
        for(int j = i+1; j<=N; j++){
            if(count >= limit){
                output(u, v);
                return 0;
            }
            u.push_back(i);
            v.push_back(j);
            count++;
        }
    }

    output(u, v);
    return 0;
}