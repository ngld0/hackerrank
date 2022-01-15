#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

bool check(vector<int> a){
    int n = a.size();
    int left = 0, right = n -1;
    cout<<right<<endl;
    while(left < right){
        
        if(a[left] == a[right]){
            left++;
            right--;
        }
        else return false;
    }
    return true;
}
string funnyString(string s) {
    
    vector<int> a;
    for(int i = 1; i < s.length();i++){
        int dif = abs((s[i-1]-'0') - (s[i]-'0'));
        
        a.push_back(dif);
        
    }
    if(check(a)) return "Funny";
    
    return "Not Funny";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

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
