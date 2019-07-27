#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

/*
    maxsからvの値の挿入すべき場所を探す
        返り値：pos番目の値の直前

 */
binary_search(vector<int> *maxs, int v){
    int pos = -1;
    // maxsは昇順


    return pos;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> maxs;

    maxs.push_back(-1);
    for(int i = 0; i < N; i++) {
        if(DEBUG){
            cout << "input: " << A[i] << ":::::::::" << endl;
        }

        int maxv = -2;
        int j_cache = -1;

        // binary_search(*maxs, A[i], *pos);
        for(int j = 0; j < maxs.size(); j++){
            if(maxs[j] < A[i]){
                if(maxv < maxs[j]){
                    maxv = maxs[j];
                    j_cache = j;
                }
            }
        }

        if(DEBUG){
            cout << "j_cache: " << j_cache << endl;

        }
        if(j_cache > -1){
            maxs[j_cache] = A[i];
            continue;
        }

        // A[i]が全てのmaxs以下の場合、新しいmaxsを作る
        maxs.push_back(A[i]);
    }

    if(DEBUG){
        for(int j = 0; j < maxs.size(); j++){
            cout << maxs[j] << endl;
        }
    }

    cout << maxs.size() << endl;


    return 0;
}