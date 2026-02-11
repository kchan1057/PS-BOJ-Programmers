#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        string s, arr, k = ""; 
        cin >> s;
        int n; cin >> n;
        cin >> arr;
        deque<int> dq;
        for(int i = 1; i < arr.size(); i++){
            if(arr.size() == 2) break;
            if(arr[i] == ',' || arr[i] == ']') {
                if(!k.empty()) { 
                    dq.push_back(stoi(k));
                    k = "";
                }
            }
            else k += arr[i];
        }
        bool chk = true; //R시 false로 변경.
        bool er = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R') chk = !chk;
            else{
                if(dq.empty()) er = true;
                else{
                    if(chk) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }
        if(er) cout << "error\n";
        else{
            cout << '[';
            int sz = dq.size();
            if(chk){
                for(int i = 0; i < sz; i++){
                    if(i != sz-1){
                        cout << dq.front() << ',';
                        dq.pop_front();
                    }
                    else cout << dq.front();
                }
            }
            else {
                for(int i = 0; i < sz; i++){
                    if(i != sz-1){
                        cout << dq.back() << ',';
                        dq.pop_back();
                    }
                    else cout << dq.back();
                }
            }
            cout << "]\n";
         }
    }
    return 0;
}