#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    stringstream ss(video_len);
    string min = "", sec = "";
    getline(ss, min, ':'); getline(ss, sec, ':');
    int videoLen = stoi(min)*60 + stoi(sec);
    
    ss.clear(); ss.str(pos);
    getline(ss, min, ':'); getline(ss, sec, ':');
    int posLen = stoi(min)*60 + stoi(sec);
    
    ss.clear(); ss.str(op_start);
    getline(ss, min, ':'); getline(ss, sec, ':');
    int opStartLen = stoi(min)*60 + stoi(sec);
    
    ss.clear(); ss.str(op_end);
    getline(ss, min, ':'); getline(ss, sec, ':');
    int opEndLen = stoi(min)*60 + stoi(sec);
    
    if(posLen >= opStartLen && posLen <= opEndLen) posLen = opEndLen;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "prev"){
            if(posLen - 10 < 0) posLen = 0;
            else posLen -= 10;
        }
        
        else {
            if(posLen + 10 > videoLen) posLen = videoLen;
            else posLen += 10;
        }
        if(posLen >= opStartLen && posLen <= opEndLen) posLen = opEndLen;
    }
    
    string result = "";
    string resultMin = to_string(posLen / 60);
    string resultSec = to_string(posLen % 60);
    if(resultMin.length() == 1) resultMin = "0" + resultMin;
    if(resultSec.length() == 1) resultSec = "0" + resultSec;
    
    result = resultMin + ":" + resultSec;
    return result;
}