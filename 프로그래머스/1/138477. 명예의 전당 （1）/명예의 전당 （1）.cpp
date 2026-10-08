#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    pq.push(score[0]); ans.push_back(score[0]);
    for(int i = 1; i < score.size(); i++){
        if(pq.size() == k){
            if(pq.top() < score[i]){
                pq.pop();
                pq.push(score[i]);
            }
        }
        else pq.push(score[i]);
        ans.push_back(pq.top());
    }
    return ans;
}