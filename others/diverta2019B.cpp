#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,R,G,B;

    cin >> R >> G >> B >> N;
 
    int ans = 0;

    for(int i = 0; i <= N/R; i++) {
        if(N - R*i < 0)break;
        for (int j = 0; j <= N/G; j++){
            if(N - R*i - G*j < 0)break;
            if((N - R*i - G*j) % B == 0)ans++;
        }
    }

    cout << ans << endl;

    return 0;
}