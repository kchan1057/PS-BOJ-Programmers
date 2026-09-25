#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int> order) {
    queue<int> con;
    stack<int> st;
    for (int num = 1; num <= order.size(); num++) con.push(num);

    int i = 0;
    while (i < order.size()) {
        int target = order[i];

        if (!st.empty() && st.top() == target) {
            st.pop();
            i++;
        } else if (!con.empty()) {
            if (con.front() == target) {
                con.pop();
                i++;
            } else {
                st.push(con.front());
                con.pop();
            }
        } else {
            break;
        }
    }
    return i;
}