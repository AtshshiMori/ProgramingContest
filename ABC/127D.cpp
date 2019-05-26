#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool pairCompare(const pair<int, ll>& firstElof, const pair<int, ll>& secondElof)
{
    return firstElof.second > secondElof.second;
}

int main(){
    int N,M;
    cin >> N >> M;

    vector<ll> A;
    ll a,c;
    int b;
    vector<pair<int, ll> > p(M);
    for(int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < M; i++) {
        cin >> b >> c;
        
        p[i] = pair<int, ll>(b, c);
    }

    //Aを降順にソート
    sort(A.begin(), A.end(), greater<int>());
  
    //cが降順にソート
    sort(p.begin(), p.end(), pairCompare);

    //後ろに０を代入しておく
    A.push_back(0);
    p.push_back(pair<int, ll>(0, 0));

    int count = 0;
    ll ans = 0;
    int itrA = 0,itrp = 0;

    while(count < N){
        if(A[itrA] >= p[itrp].second){
            ans += A[itrA];
            itrA++;
        }else{
            ans += p[itrp].second;
            if(p[itrp].first > 1){
                p[itrp].first--;
            }else{
                itrp++;
            }
        }
        count++;
    }
    
    cout << ans << endl;


    return 0;
}