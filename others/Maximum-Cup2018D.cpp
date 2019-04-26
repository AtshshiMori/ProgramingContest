#include <bits/stdc++.h>
using namespace std;

#define INF 99999

int main(){
    int N,M,L,X;
    cin >> N >> M >> L >> X;

    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int dp[N][M];
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            dp[i][j] = INF;
        }
    }
    

    //１行目の初期化
    for (int i = 0; i < M; i++){
        if(a[0] % M == i){
            dp[0][i] = a[0] / M + 1;
        }else{
            dp[0][i] = INF;
        }
    }
    
    //DP
    for(int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++){
            int pos = (j + a[i]) % M;
            if(dp[i-1][j] != INF){
                int value = dp[i-1][j] + ((j + a[i]) / M);
                dp[i][pos] = value;
            }
            dp[i][pos] = min(dp[i-1][pos], dp[i][pos]);
        }
    }

    // for(int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++){
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
        
    // }

    if(dp[N-1][L] <= X){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}