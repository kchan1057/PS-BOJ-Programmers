#include <string>
#include <vector>

using namespace std;
int chk(int num) {
    int cnt = 0;
    for(int i = 1; i*i <= num; i++){
        if(num % i == 0){
            if(i*i == num) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
int solution(int number, int limit, int power) {
    int sum = 0;
    for(int i = 1; i <= number; i++) {
        if(chk(i) <= limit) sum += chk(i);
        else sum += power;
    }
    
    return sum;
}