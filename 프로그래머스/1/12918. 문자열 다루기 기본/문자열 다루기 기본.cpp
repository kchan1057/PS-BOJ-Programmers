#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool chk = true;
    if((s.length() == 4 || s.length() == 6)) {
        for(int i = 0; i < s.length(); i++){
            if(!isdigit(s[i])) chk = false;
        }
    }
    else chk = false;
    return chk;
}