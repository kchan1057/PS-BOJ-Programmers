#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ch_base(int n, int k){
    string a = "";
    do{
        a += to_string((n%k));
        } while(n /= k);
    
    reverse(a.begin(), a.end());
    return a;
}

bool isPrime(string a) {
    long long k = stoll(a);
    if(k == 1) return 0;
    for(int i = 2; i*i <= k; i++){
        if(k % i == 0) return 0;
    }
    return 1;
}

int solution(int n, int k) {
    string base = ch_base(n, k);
    int ans = 0;
    string a = "";
    if(base.length() == 1){
        return isPrime(base) ? 1 : 0;
    }
    for(int i = 0; i < base.length(); i++) {
        if(base[i] == '0' && a.length() != 0){
            if(isPrime(a)) ans++;
            a = "";
        }
        else if(base[i] != '0') a += base[i];
    }
    if(a.length() != 0 && isPrime(a)) ans++;
    return ans;
}