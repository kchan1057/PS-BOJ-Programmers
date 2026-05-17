#include <string>
#include <vector>
#include <math.h>
using namespace std;
long long solution(long long n) {
    long long ans = -1;
    for(int i = 1; i <= sqrt(n); i++){
        if((long long)pow(i, 2) == n) ans = pow(i+1, 2);
    }
    return ans;
}