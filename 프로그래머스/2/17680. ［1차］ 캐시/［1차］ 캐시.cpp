#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    for(int i = 0; i < cities.size(); i++){
        for(int j = 0; j < cities[i].length(); j++){
            if(isupper(cities[i][j])) cities[i][j] = tolower(cities[i][j]);
        }
    }
    vector<string> cache;
    int sum = 0;
    for(int i = 0; i < cities.size(); i++) {
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if(it == cache.end()){
            sum += 5;
            cache.push_back(cities[i]);
            if(cache.size() > cacheSize) cache.erase(cache.begin());
        }
        else{
            sum += 1;
            cache.erase(it);
            cache.push_back(cities[i]);
            
        }
    }
    return sum;
}