#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int ans = 0;
    for (int i = 0; i < skill_trees.size(); i++)  {
        string filtered = "";

        for (char c : skill_trees[i]) {
            if (skill.find(c) != string::npos) filtered += c; 
        }
    
        if (skill.substr(0, filtered.size()) == filtered) ans++;
    }
    return ans;
}