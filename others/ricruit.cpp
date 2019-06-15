#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int cost;
};

bool checkCycle(vector<vector<Edge> > edge, int n){
    vector<int> stack;
    vector<int> visited(n, 0);
    stack.push_back(0);
    

    while(!stack.empty()){
        int i = stack.back();
        stack.pop_back();

        if(visited[i] == 1)return 1; // サイクルあり

        for(int j=0; j < edge[i].size(); j++){
            stack.push_back(edge[i][j].to);
        }
    }
    return 0;
}

int main() {

//   std::ifstream in(argv[1]);
//   std::cin.rdbuf(in.rdbuf());

  int n,q;
  cin >> n >> q;

  int a[n],b[n],c[n];
  for(int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  
  vector<vector<Edge> > edge(n);
  for(int i = 0; i < q; i++){
      Edge e = {b[i],c[i]};
    edge[a[i]].push_back(e);
  }

  checkCycle(edge, n);


  

  cout << "n:" << n << endl;
  cout << "q:" << q << endl;


  return 0;
}
