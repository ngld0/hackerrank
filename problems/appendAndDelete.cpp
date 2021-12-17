#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */
/*
  S = hackerhappy
  t = hackerrank
  -> count = 6
  -> check = 5 + 4 = 9
  check <= k && (check)%2==k%2) => yes
  or
  (s.size() + t.size()) <= k => yes
  
*/

string appendAndDelete(string s, string t, int k) {
    
    int count = 0;
  
    // // counting the same characters between string s and string t 
    while(count < s.size() && count < t.size()){
        
        if(s[count] != t[count]) break;
        
        count++;
    }
    // checking total the last different of string s and string t
    int check  = s.size() - count + t.size() - count;
    
    if( (check <= k && (check)%2==k%2) || (s.size() + t.size()) <= k)
    {
        return "Yes";
    }
    
    
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
