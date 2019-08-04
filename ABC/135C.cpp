n#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

int main(){
    int N;
    cin >> N;
    long long A[N+1],B[N];

    for(int i = 0; i < N+1; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    long long ans;
    for(int i = 0; i < N; i++) {
        if(A[i] <= B[i]){
            //　全員倒す
            ans += A[i];
            B[i] -= A[i];
            A[i] = 0;

            if(A[i+1] <= B[i]){
                //　全員倒す
                ans += A[i+1];
                B[i] -= A[i+1];
                A[i+1] = 0;
            }else{
                ans += B[i];
                A[i+1] -= B[i];
                B[i] = 0;
            }
        }else{
            ans += B[i];
            A[i] -= B[i];
            B[i] = 0;
        }

        if(DEBUG){
            for(int i = 0; i < N+1; i++) {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    }

    cout << ans << endl;

    return 0;
}