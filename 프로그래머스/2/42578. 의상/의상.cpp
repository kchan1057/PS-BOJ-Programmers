#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mp;
int solution(vector<vector<string>> clothes) {
    
    for(int i = 0; i < clothes.size(); i++){
        mp[clothes[i][1]]++;
    }
    
    int k = 1;
    for(auto pair : mp) k *= (pair.second+1);
    
    return k-1;
}