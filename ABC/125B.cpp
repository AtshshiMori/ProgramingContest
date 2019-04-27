#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    int v[N],c[N],a[N];
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    for (int i = 0; i < N; i++){
        cin >> c[i];
    }
    for (int i = 0; i < N; i++){
        a[i] = v[i] - c[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if(a[i] > 0){
            ans += a[i];
        }
    }
    
    cout << ans << endl;

    return 0;
}