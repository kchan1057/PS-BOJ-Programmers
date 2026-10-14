#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int ans = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        for (int j = 0; j < skill_trees[i].size(); ) {
            if (skill.find(skill_trees[i][j]) == string::npos) {
                skill_trees[i].erase(j, 1);
            } else {
                j++;
            }
        }
    }
    
    for(int i = 0; i < skill_trees.size(); i++){
        if(skill_trees[i] == skill.substr(0, skill_trees[i].length())) ans++;
    }
    return ans;
}