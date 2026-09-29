#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

int toDays(const string& date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));

    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> term;

    for (string s : terms) {
        string type;
        int month;

        stringstream ss(s);
        ss >> type >> month;

        term[type] = month;
    }

    vector<int> answer;
    int todayDays = toDays(today);

    for (int i = 0; i < privacies.size(); i++) {
        string date, type;

        stringstream ss(privacies[i]);
        ss >> date >> type;

        int expireDays = toDays(date) + term[type] * 28;

        if (expireDays <= todayDays) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}