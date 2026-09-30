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
        ans.push_back(it - s.begin());
        ans.push_back(it - s.begin());
        return ans;
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
    int a, b, c;
    tie(a, b, c) = pq.top(); pq.pop();
    ans.push_back(b); ans.push_back(c);
    return ans;
}