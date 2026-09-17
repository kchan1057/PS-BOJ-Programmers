#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int k : scoville) pq.push(k);
    int ans = 0;
    while(1){
        bool chk = 1;
        if(pq.top() < K) chk = 0;
        if(chk) return ans;
        if(pq.size() < 2) return -1;
        auto cur1 = pq.top(); pq.pop();
        auto cur2 = pq.top(); pq.pop();
        int t = cur1 + cur2*2;
        pq.push(t);
        ans++;
    }
    return -1;
}