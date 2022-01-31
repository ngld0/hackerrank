#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
// checking valid weather consecutive character is same ?
bool helper(string s) {
    if(s.length() ==1)return false;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i-1])
            return false;
    return true;
}

int alternate(string s) {
    int ans = 0;
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++) {
            //if (a == b) continue;
            string t;
            for (int i=0; i<s.size(); i++) {
                if (s[i] == a || s[i] == b) t += s[i];
            }
            
            if (helper(t)) ans = max(ans,  (int)t.length());
        }
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
