#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gameOfStones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string gameOfStones(int n) {
    // Sol 1.
    // if(n % 7 > 1) return "First";
    // return "Second";
    // Sol 2.
    bool *dp = new bool[n + 1];
    dp[1] = false;
    dp[2] = true;
    dp[3] = true;
    dp[4] = true;
    dp[5] = true;
    for(int i = 6 ; i <= n;i++){
        
        if(dp[i-2] == false || dp[i-3] == false || dp[i-5] == false) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }
    if(dp[n] == true) return "First";
    return "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = gameOfStones(n);

        fout << result << "\n";
    }

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
