#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> ans;
vector<int> solution(vector<int> s, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int st = 0, en = 1;
    int sum = s[st] + s[en];
    auto it = find(s.begin(), s.end(), k);
    if(it != s.end()){
        int idx= it - s.begin();
        return {idx, idx};
    }
    while(en < s.size()) {
        if(sum < k) {
            en++;
            if(en < s.size()) sum += s[en];
        }
        else if(sum > k) {
            sum -= s[st];
            st++;
        }
        else {
            pq.push({en-st, st, en});
            sum -= s[st];
            st++;
        }
    }
    auto [a, b, c] = pq.top(); pq.pop();
    return {b, c};
}