#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string superReducedString(string s){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    if(s.length() < 2) return "Empty String\n";
    for(int i = 1 ; i < s.length() ;i++){
        if(s[i] == s[i-1]){
            s.erase(i-1,2);
            i = 0;
        }
    }
    if(s.length()!= 0) return s;
    return "Empty String\n";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
