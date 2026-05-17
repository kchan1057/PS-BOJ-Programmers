#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0; int k = x;
    do{
        sum += x%10;
    } while(x /= 10);
    return k % sum == 0 ? 1 : 0;
}