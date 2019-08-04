#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;


int main(){
    string S;
    cin >> S;

    int N = S.length();
    int now = 0;
    vector<int> ans(N,0);

    while(now < N){
        int left = now;
        int right;
        int r_pos;

        while(S[now] == 'R'){
            now++;
        }
        r_pos = now - 1;
        ans[r_pos] = 1; // その場の1人
        ans[r_pos+1] = 1; // その場の1人
        
        int r_cnt = r_pos - left;
        ans[r_pos] += r_cnt / 2; // 左側をRの位置に足す
        ans[r_pos+1] += (r_cnt + 1) / 2; // 左側をLの位置に足す

        while(S[now] == 'L'){
            now++;
            if(now == N)break;
        }

        right = now - 1;
        int l_cnt = right - r_pos - 1;
        ans[r_pos] += (l_cnt+1) / 2;
        ans[r_pos+1] += l_cnt / 2;
        
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}