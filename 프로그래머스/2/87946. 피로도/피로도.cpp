#include <string>
#include <vector>
using namespace std;
int ans = 0;
bool isused[9];
void dfs(int a, int k, int b, vector<vector<int>>& dungeons){
    ans = max(ans, b);
    if(a == dungeons.size()){
        return;
    }
    
    for(int i = 0; i < dungeons.size(); i++){
        if(isused[i]) continue;
        if(k < dungeons[i][0] || k - dungeons[i][1] < 0) continue;
        isused[i] = 1;
        k -= dungeons[i][1];
        dfs(a+1, k, b+1 , dungeons);
        k += dungeons[i][1];
        isused[i] = 0;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, 0, dungeons);
    return ans;
}