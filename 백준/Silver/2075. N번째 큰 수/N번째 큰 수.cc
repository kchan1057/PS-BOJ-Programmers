#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n*n; i++){
        int k; cin >> k;
        if(pq.size() < n) pq.push(k);
        else{
            if(pq.top() < k){
                pq.pop();
                pq.push(k);
            }   
        }
    }
    cout << pq.top();
    return 0;
}