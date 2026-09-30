#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int len = triangle.size();
    int d[505][505] = {};
    d[0][0] = triangle[0][0];
    
    for(int i = 1; i < len; i++) {
        for(int j = 0; j <= i; j++){
            if(j == 0) d[i][j] += (triangle[i][j] + d[i-1][j]);
            else if(j == i) d[i][j] += (triangle[i][j] + d[i-1][j-1]);
            else d[i][j] += (triangle[i][j] + max(d[i-1][j-1], d[i-1][j]));
        }
    }
    
    int ans = *max_element(d[len-1], d[len-1] + len);
    return ans;
}