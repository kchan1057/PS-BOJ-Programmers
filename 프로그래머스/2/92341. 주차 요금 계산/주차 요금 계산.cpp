#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int, vector<int>> mp;
    
    for(int i = 0; i < records.size(); i++){
        int t = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        int num = stoi(records[i].substr(6, 4));
        mp[num].push_back(t);
    }
    for(auto [key, vec] : mp){
        if(vec.size() % 2 == 1) mp[key].push_back(1439);
    }
    for(auto [key, vec] : mp) sort(vec.begin(), vec.end());
    vector<int> sumTime;
    for(auto [key, vec] : mp) {
        int len = vec.size();
        int sum = 0;
        for(int i = 0; i < vec.size(); i += 2) sum += (vec[i+1] - vec[i]);
        sumTime.push_back(sum);   
    }
    vector<int> answer;
    for(int i = 0; i < sumTime.size(); i++) {
        if(sumTime[i] <= fees[0]){
            answer.push_back(fees[1]);
        }
        else {
            int t = fees[1];
            sumTime[i] -= fees[0];
            t += ceil((double)sumTime[i]/fees[2]) * fees[3];
            answer.push_back(t);
        }
    }
    return answer;
}