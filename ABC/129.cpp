#include <bits/stdc++.h>
using namespace std;

int search_length_h(int w, vector<int> sharps){
    int size = sharps.size();
    int left = 0;
    int right = size-1;

    // int count = 0;
    while(right - left > 1){
        // count++;
        int itr = (right + left)/2;
        if(sharps[itr] < w){
            left = itr;
        }else{
            right = itr;
        }

        // if(count > 100)return -1;
    }

    return sharps[right] - sharps[left] - 1;
}

int search_length_w(int h, vector<int> sharps){
    int size = sharps.size();
    int left = 0;
    int right = size-1;

    // int count = 0;
    while(right - left > 1){
        // count++;
        int itr = (right + left)/2;
        if(sharps[itr] < h){
            left = itr;
        }else{
            right = itr;
        }

        // if(count > 100)return -1;
    }

    return sharps[right] - sharps[left] - 1;
}

int main(){
    int H,W;
    cin >> H >> W;

    string s[H];
    vector<vector<int> > sharp_h(H+2);
    vector<vector<int> > sharp_w(W+2);
    for(int i = 0; i < H; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < H; i++) {
        sharp_h[i+1].push_back(0);
        for(int j = 0; j < W; j++) {
            if(s[i][j] == '#')
                sharp_h[i+1].push_back(j+1);
        }
        sharp_h[i+1].push_back(W+1);
    }

    for(int i = 0; i < W; i++) {
        sharp_w[i+1].push_back(0);
        for(int j = 0; j < H; j++) {
            if(s[j][i] == '#')
                sharp_w[i+1].push_back(j+1);
        }
        sharp_w[i+1].push_back(H+1);
    }

    int ans = 0;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(s[i-1][j-1] == '#')continue;

            int cnt = 0;
            cnt += search_length_h(j, sharp_h[i]);
            cnt += search_length_w(i, sharp_w[j]);
            cnt--;


            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}