#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<pair<int, int>> Q;
    vector<int> ans;
    for(int i = 0; i < speeds.size(); i++) Q.push({progresses[i], speeds[i]});
    
    int now = 0;
    
    while(!Q.empty()){
        int p = Q.front().X, s = Q.front().Y;
        int cnt = 0;
        if(p < 100){
            if((100-(p + now*s))%s != 0) now += (100-(p + now*s))/s + 1;
            else now += (100-(p + now*s))/s;
        }
        
        while(Q.front().X+now*Q.front().Y>= 100) {
            Q.pop();
            cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}