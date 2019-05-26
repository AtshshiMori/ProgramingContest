#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int k[M];
    int s[M][N];
    int p[M];
    for(int i = 0; i < M; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> p[i];
    }

     int maxv = pow(2,N);
     int ans = 0;

    //  for(int i = 0; i < M; i++) {
         
    //     for (int j = 0; j < k[i]; j++){
    //         cout << s[i][j] << " ";
    //     }
    //     cout << p[i];
    //     cout << endl;
    //  }
     
    for(int i = 0; i < maxv; i++) {
        int v = i;
        int itr = 0;
        vector<int> onoff(N, 0);

        int bit = v % 2;
        onoff[N - 1 -itr] = bit;
        while(v / 2 > 0){
            itr++;
            v /= 2;

            bit = v % 2;
            onoff[N - 1 -itr] = bit;
        }

        bool success = true;
        for(int j = 0; j < M; j++) {
            //cout << "j:" <<  j << endl;
            int on = 0;
            for(int l = 0; l < k[j]; l++){
                //cout << "s[j][i]:" << s[j][l] << endl;
                if(onoff[s[j][l]-1] == 1){
                    on += 1;
                }
            }

            //cout << on << endl;
            if(on%2 != p[j]){
                success = false;
                break;
            }
        }

        if(success){
            ans++;
        }
    }

    cout << ans << endl;
    

    return 0;
}