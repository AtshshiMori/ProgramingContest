#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

int main(){
    int N;
    cin >> N;

    int A[N];
    int max = 0, max2 = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];

        if(max < A[i]){
            max2 = max;
            max = A[i];
        }else if(max2 < A[i]){
            max2 = A[i];
        }
    }

    if(DEBUG){
        cout << max << endl;
        cout << max2 << endl;
    }

    for(int i = 0; i < N; i++) {
        if(A[i] == max){
            cout << max2 << endl;
        }else{
            cout << max << endl;
        }
    }

    return 0;
}