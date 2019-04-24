#include <bits/stdc++.h>
using namespace std;

//Union Find tree
struct UnionFind {
    vector<int> par;//parent of node
    vector<int> size;//element count

    //constructor
    UnionFind(int N) {
        par.resize(N);
        size.resize(N);
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int root(int x){
        if(x == par[x])return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        if(root(x) == root(y)){
            return;
        }

        size[root(y)] += size[root(x)];
        par[root(x)] = root(y);
    }
    
    bool same(int x, int y){
        return root(x) == root(y);
    }

    int getSize(int x){
        return size[root(x)];
    }
};

int main(){
    long long N,M;

    cin >> N >> M;

    int A[M],B[M];
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    UnionFind uf(N);
    long long ans[M];
    ans[M-1] = N * (N-1) / 2;
    for(int i = M-1; i > 0; i--) {
        ans[i-1] = ans[i];
        if(!uf.same(A[i],B[i])){
            ans[i-1] = ans[i] - (uf.getSize(A[i]) * uf.getSize(B[i]));
            uf.unite(A[i],B[i]);
        }
    }

    for(int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}