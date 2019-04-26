#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;

    int v[N],w[N];
    for(int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }

    int dp[N][W+1];

    //１行目の初期化
    for (int i = 0; i <= W; i++)
    {
        if(w[0] <= i){
            dp[0][i] = dp[0][i-w[0]] + v[0];
        }else{
            dp[0][i] = 0;
        }
        //cout << dp[0][i] << " ";
    }
    //cout << endl;
    
    //DP
    for(int i = 1; i < N; i++) {
        for (int j = 0; j <= W; j++){
            if(j-w[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i][j-w[i]] + v[i]);

            }else{
                dp[i][j] = dp[i-1][j];
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
   cout << dp[N-1][W] << endl;


    return 0;
}