#include <iostream>
#include <string>
using namespace std;
int solution(int n){
    string st = to_string(n);
    int t = 0;
    for(char k : st) t += k - '0';
    return t;
}