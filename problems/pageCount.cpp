#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */
/*
Clean code!!!!
we should use p%2 == 0 or p%2 != 0, it's is easier to understand
*/
int pageCount(int n, int p) {
    int ans = 0, start = 0, end = n, sflips = 0, eflips = 0;
    // p%2 = 1 <=> true 
    // condition if else; if (1) => true ; if(0) false;
    if(p%2){
        start = 1;
        // n%2 not equal to 1.
        if(n%2 == 0) end = n+1;
        //the following condition is n%2 equal to 1.
        else  end = n-1;
    }
    //check n%2 equals to 1 (mean n%2 = 1)
    else if(n%2) end = n-1;
    
    while(start < p){
        start += 2;
        sflips++;
    }
    while(end > p){
        end -= 2;
        eflips++;
    }
    
    
    return min(sflips, eflips);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
