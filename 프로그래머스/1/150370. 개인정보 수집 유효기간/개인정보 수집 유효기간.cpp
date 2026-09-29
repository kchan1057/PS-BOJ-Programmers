#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> mp_term;
    for(int i = 0; i < terms.size(); i++){
        stringstream ss(terms[i]);
        string a, b; ss >> a >> b;
        mp_term[a] = stoi(b);
    }
    
    vector<int> ans;
    for(int i = 0; i < privacies.size(); i++){
        stringstream ss(privacies[i]);
        string a, b; ss >> a >> b;
        int ori_year = stoi(a.substr(0, 4)), ori_month = stoi(a.substr(5, 2)), ori_day = stoi(a.substr(8, 2));
        int ps = mp_term[b];
        int tmp = ori_month + ps;

        ori_year += (tmp - 1) / 12;
        ori_month = (tmp - 1) % 12 + 1;
        if(ori_day == 1) {
            ori_day = 28;
            if(ori_month == 1){
                ori_month = 12;
                ori_year -= 1;
            }
            else ori_month -= 1;
        }
        else ori_day -= 1;
        bool chk = 0;
        if(stoi(today.substr(0, 4)) > ori_year) chk = 1;
        else if(stoi(today.substr(0, 4)) == ori_year){
            if(stoi(today.substr(5, 2)) > ori_month) chk = 1;
            else if(stoi(today.substr(5, 2)) == ori_month) {
                if(stoi(today.substr(8, 2)) > ori_day) chk = 1;
            }
        }
        
        if(chk) ans.push_back(i+1);
    }
    return ans;
}