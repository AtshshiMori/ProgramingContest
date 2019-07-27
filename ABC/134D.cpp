#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

int main(){
    int N,M=0;
    cin >> N;

    
    int A[N+1],ans[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for(int i = N; i >= 1; i--) {
        int count = N / i;

        if(count <= 1){
            ans[i] = A[i];
            if(ans[i] == 1)M++;
            continue;
        }

        int sum=0;
        while(count > 1){
            int look = i*count;
            sum += ans[look];
            count--;
        }

        int now = sum%2;
        ans[i] = (A[i] ^ now);

        if(ans[i] == 1)M++;
    }

    cout << M << endl;
    for(int i = 1; i <= N; i++) {
        if(DEBUG)cout << ans[i] << endl;
        if(ans[i] == 1)cout << i << " ";
    }

    return 0;
}