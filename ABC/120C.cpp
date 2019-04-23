#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  
  int cnt_r = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '0') {
      cnt_r++;
    }
  }

  if(cnt_r > S.length()/2){
	  cout << (S.length() - cnt_r) * 2 << endl;
  }else{
	  cout << cnt_r * 2 << endl;
  }

  return 0;
}