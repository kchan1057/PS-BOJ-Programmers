#include <string>
using namespace std;

string solution(string s, string skip, int index) {
    for (char& c : s) {
        int count = 0;

        while (count < index) {
            c++;

            if (c > 'z')
                c = 'a';

            if (skip.find(c) == string::npos)
                count++;
        }
    }

    return s;
}