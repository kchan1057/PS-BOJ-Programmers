#include <string>
using namespace std;
long long solution(int a, int b) {
    int c, d = 0;
    long long ans = 0;
    if(a > b) {
        c = a;
        d = b;
        for(int i = d; i <= c; i++) ans += i;
    }
    else if(a < b) {
        c = b;
        d = a;
        for(int i = d; i <= c; i++) ans += i;
    }
    else return a;
    return ans;
}