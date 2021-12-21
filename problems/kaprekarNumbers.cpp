#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */
 
 bool iskaprekarNumber(int n){
    long square =(long) n * n ; 
    string sq  = to_string(square); 
    int len = sq.length()/2;
    if(len == 0 ){
        if( square == n)  return true;
        
    } 
    else if (stoi(sq.substr(0,len))+stoi(sq.substr(len,sq.length()-len)) == n) return true;
    
    return false;
 }

void kaprekarNumbers(int p, int q) {
    vector<int> ans;
    while(p<=q){
        if(iskaprekarNumber(p)) ans.push_back(p);
        p++;
    }
    if(ans.size() ==0) cout<< "INVALID RANGE";
    else for(auto a : ans){
        cout<< a<<" ";
    }
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
