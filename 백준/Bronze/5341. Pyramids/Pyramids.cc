#include <bits/stdc++.h>
using namespace std;
int main(){
  while (true){
    int n; cin >> n;
    if (n == 0) break;
    int totalBlocks = n * (n + 1) / 2;
    cout << totalBlocks << "\n";
  }
  return 0;
}