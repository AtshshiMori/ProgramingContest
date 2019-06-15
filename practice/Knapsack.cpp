#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;

/**
* @brief ナップザック問題を解く関数
* @param[in] W(最大容量) 重さの和はこれを超えてはならない
* @param[in] w(重さの配列) それぞれの要素の重さ
* @param[in] v(価値の配列) それぞれの要素の価値
* @return ret(価値の最大値) 価値の総和の最大値
* @details 重さw価値vの荷物がいくつかあり、容量Wのナップザックにどれを入れるか選ぶ。今回は同じ荷物は1度しか入れられない。この時の価値の最大値を求める問題。
*/

int knapsack(int W, vector<int> &w, vector<int> &v){
    int ret = 0;
    int n = w.size();

    // デバッグ出力
    if(DEBUG){
        for(int i = 0; i < n; i++) {
            cout << w[i] << " " << v[i] << endl;
        }
    }

    vector<vector<int> > dp(n);
    for(int i = 0; i < n; i++) {
        dp[i].resize(W+1, 0);
    }

    // 一行目の初期化
    for(int i = 0; i <= W; i++) {
        if(w[0] <= i){
            dp[0][i] = v[0];
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
                dp[i][j] = max(dp[i-1][j - w[i]] + v[i], dp[i-1][j]);
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


/**
* @brief ナップザック問題（重複可）を解く関数
* @param[in] W(最大容量) 重さの和はこれを超えてはならない
* @param[in] w(重さの配列) それぞれの要素の重さ
* @param[in] v(価値の配列) それぞれの要素の価値
* @return ret(価値の最大値) 価値の総和の最大値
* @details 重さw価値vの荷物がいくつかあり、容量Wのナップザックにどれを入れるか選ぶ。今回は同じ荷物をいくつでも入れられる。この時の価値の最大値を求める問題。
*/
int knapsack_duplicate(int W, vector<int> w, vector<int> v){
    int ret = 0;
    int n = w.size();


    // デバッグ出力
    if(DEBUG){
        cout << "n : " << n << endl;
        for(int i = 0; i < n; i++) {
            cout << w[i] << " " << v[i] << endl;
        }
    }

    vector<vector<int> > dp(n);
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
    int N,W;
    cin >> N >> W;

    vector<int> v(N), w(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }

    int ans = knapsack_duplicate(W, w, v);
    cout << ans << endl;

    return 0;
}