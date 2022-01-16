#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    
    int alpha[26] = {0}, check = 0;
    
    for(char c : s){
        alpha[c - 'a']++;
        
    } 
    for(int i = 0; i < 26;i++){
        if( alpha[i]%2 == 1) check++;
    }
    return check< 2? "YES": "NO";
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
