#include <bits/stdc++.h>
using namespace std;

int x = 0;
vector<pair<int, int>> v;

void TOH(int n,int a, int b, int c) {
  x++;
  if(n==1) {
    v.push_back({a,c});
  }
  else {
    TOH(n-1,a,c,b);
    v.push_back({a,c});
    TOH(n-1,b,a,c);
  }
}

int main() {
    int n;
    cin >> n;
  TOH(n, 1, 2, 3);
  cout << x << "\n";
  for(auto p : v) {
      cout << p.first << " " << p.second << "\n";
  }
}
