#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
//DP extralong fractional
void extraLongFactorials(int n) {
    int ans[1000];
    ans[0]=1;
    int a = 1;
    for(int i = 2;i<=n ;i++){
        //carry number
        int carry = 0;
        // 
        int j =0;
        while(j < a){
            int pod = ans[j] * i + carry;
            ans[j] = pod%10;
            carry = pod/10;
            j++;
        }
        
        while(carry){
            ans[a] = carry%10;
            carry/=10;
            a++;
        }
        
    }
    int i = a -1;
    while(i>=0){
        cout<< ans[i];
        i--;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
