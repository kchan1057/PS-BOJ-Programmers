#include <string>
#include <vector>

using namespace std;
int one_count, zero_count;
void act(int x, int y, int size, vector<vector<int>>& arr) {
    
    if(size == 1){
        if(arr[x][y] == 1) one_count++;
        else zero_count++;
        return;
    }
    bool chk = 1;
    int start = arr[x][y];
    for(int i = x; i < x+size; i++) {
        for(int j = y; j < y+size; j++){
            if(start != arr[i][j]) {
                chk = 0;
            }
        }
    }
    if(chk) {
        if(start == 0) zero_count++;
        else one_count++;
        return;
    }
    else {
        act(x, y, size/2, arr);
                act(x+size/2, y, size/2, arr);
                act(x, y+size/2, size/2, arr);
                act(x+size/2, y+size/2, size/2, arr);
    }
}
vector<int> solution(vector<vector<int>> arr) {
    int arr_size = arr.size();
    
    act(0, 0, arr_size, arr);
    
    return {zero_count, one_count};
}