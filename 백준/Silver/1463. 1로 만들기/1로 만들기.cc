#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    memset(arr, -1, sizeof(arr));
    arr[n] = 0; 
    queue<int> Q; Q.push(n);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur % 3 == 0 && arr[cur/3] == -1){
            arr[cur/3] = arr[cur]+1;
            if(cur/3 == 1) break;
            Q.push(cur/3);
        }
        if(cur % 2 == 0 && arr[cur/2] == -1){
            arr[cur/2] = arr[cur]+1;
            if(cur/2 == 1) break;
            Q.push(cur/2); 
        }
        if(cur-1 >= 1 && arr[cur-1] == -1){
            arr[cur-1] = arr[cur]+1;
            if(cur-1 == 1) break;
            Q.push(cur-1);
        }
    }
    cout << arr[1];
    return 0;   
}