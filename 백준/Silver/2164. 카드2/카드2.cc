#include <bits/stdc++.h>
using namespace std;

int main() {
    int a; cin >> a;
    queue<int> arr;
    for(int i = 1 ; i <=a; i++)
        arr.push(i);
    while(arr.size() != 1)
        {
            arr.pop(); //버리기
            arr.push((arr.front())); //앞에꺼 넘기기
            arr.pop(); //넘긴 앞에꺼 버리기.

        }
    cout << arr.front() << '\n';
    return 0;
}