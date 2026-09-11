#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = 0, prime[1] = 0;
    
    for(int i = 2; i*i <= n; i++){
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) prime[j] = 0;
        }
    }
    int count = 0;
    
    for(int i = 2; i <= n; i++){
        if(prime[i]) count++;
    }
    return count;
}