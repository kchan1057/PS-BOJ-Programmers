#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int ans = 0;
    
    for(int i = 0; i < d.size(); i++){
        if(budget - d[i] >= 0){
            ans++;
            budget -= d[i];
        }
        else return ans;
    }
    return ans;
}