#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string solution(string s) {
    stringstream ss(s);
    int num; vector<int> vc;
    while(ss >> num) vc.push_back(num);
    return to_string(*min_element(vc.begin(), vc.end())) + " "
        + to_string(*max_element(vc.begin(), vc.end()));
}