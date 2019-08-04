#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;


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
        auto itr = upper_bound(maxs.begin(), maxs.end(), A[i]);

        // 新規追加
        if(itr == maxs.begin()){
            maxs.insert(maxs.begin(), A[i]); // 先頭に追加する

        // 適切な場所を更新
        }else{
            *(--itr) = A[i];
        }
        if(DEBUG){
            cout << "j_cache: " << j_cache << endl;

        }
    }

    if(DEBUG){
        for(int j = 0; j < maxs.size(); j++){
            cout << maxs[j] << endl;
        }
    }

    cout << maxs.size() << endl;


    return 0;
}