#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;

long long knapsack_duplicate(int W, vector<int> w, vector<int> v){
    long long ret = 0;
    int n = w.size();


    // デバッグ出力
    if(DEBUG){
        cout << "n : " << n << endl;
        for(int i = 0; i < n; i++) {
            cout << w[i] << " " << v[i] << endl;
        }
    }

    vector<vector<long long> > dp(n);
    for(int i = 0; i < n; i++) {
        dp[i].resize(W+1, 0);
    }

    // 一行目の初期化
    for(int i = 0; i <= W; i++) {
        if(w[0] <= i){
            dp[0][i] = dp[0][i - w[0]] + v[0];
        }else{
            dp[0][i] = 0;
        }
    }

    // dp
    for(int i = 1; i < n; i++) {
        for (int j = 0; j <= W; j++){
            if(j - w[i] < 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i][j - w[i]] + v[i], dp[i-1][j]);
            }
        }
    }

    // デバッグ出力
    if(DEBUG){
        for(int i = 0; i < n; i++) {
            for (int j = 0; j <= W; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    
    ret = dp[n-1][W];
    return ret;
}

int main(){
    int N;
    cin >> N;

    vector<int> shopA(3);
    cin >> shopA[0] >> shopA[1] >> shopA[2];

    vector<int> shopB(3);
    cin >> shopB[0] >> shopB[1] >> shopB[2];
    
    vector<int> w(3);
    vector<int> v(3);
    for(int i = 0; i < 3; i++) {
        w[i] = shopA[i];
        v[i] = shopB[i];
    }
    w.push_back(1);
    v.push_back(1);

    long long M = knapsack_duplicate(N, w, v);

    if(DEBUG){
        cout << "M : " << M << endl;
    }

    for(int i = 0; i < 3; i++) {
        w[i] = shopB[i];
        v[i] = shopA[i];
    }
    
    long long ans = knapsack_duplicate(M, w, v);

    cout << ans << endl;

    return 0;
}