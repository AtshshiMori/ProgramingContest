#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int L[M], R[M];
    int minL=0,maxR=N-1;
    for(int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;

        minL = max(minL, L[i]);
        maxR = min(maxR, R[i]);
    }

    if(minL <= maxR){
        cout << maxR - minL + 1 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}