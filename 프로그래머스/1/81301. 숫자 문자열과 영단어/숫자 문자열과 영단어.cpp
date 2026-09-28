#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    
    vector<string> vc = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
    
    for(int i = 0; i < vc.size(); i++){
        auto pos = 0;
        while((pos = s.find(vc[i], pos)) != string::npos){
            s.replace(pos, vc[i].length(), to_string(i));
            pos += 1;
        }
    }
    return stoi(s);
}