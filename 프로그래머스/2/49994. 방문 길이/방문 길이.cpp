#include <string>
#include <set>
using namespace std;
set<pair<pair<int, int>, pair<int, int>>> s;
int solution(string dirs) {
    int count = 0;
    int x = 0, y = 0;
    for(char k : dirs){
        if(k == 'U'){
            int nx = x, ny = y+1;
            if(ny > 5) continue;
            int a = s.size();
            s.insert({{x, y}, {nx, ny}});
            s.insert({{nx, ny}, {x, y}});
            if(a+2 == s.size()) count++;
            x = nx, y = ny;
        }
        
        else if(k == 'L'){
            int nx = x-1, ny = y;
            if(nx <  -5) continue;
            int a = s.size();
            s.insert({{x, y}, {nx, ny}});
            s.insert({{nx, ny}, {x, y}});
            if(a+2 == s.size()) count++;
            x = nx, y = ny; 
        }
        
        else if(k == 'R') {
            int nx = x+1, ny = y;
            if(nx > 5) continue;
            int a = s.size();
            s.insert({{x, y}, {nx, ny}});
            s.insert({{nx, ny}, {x, y}});
            if(a+2 == s.size()) count++;
            x = nx, y = ny; 
        }
        
        else{
            int nx = x, ny = y-1;
            if(ny < -5) continue;
            int a = s.size();
            s.insert({{x, y}, {nx, ny}});
            s.insert({{nx, ny}, {x, y}});
            if(a+2 == s.size()) count++;
            x = nx, y = ny; 
        }
    }
    return count;    
}