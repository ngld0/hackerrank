#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    map <int, string> count;
    count[1] = "one";
    count[2] = "two";
    count[3] = "three";
    count[4] = "four";
    count[5] = "five";
    count[6] = "six";
    count[7] = "seven";
    count[8] = "eight";
    count[9] = "nine";
    count[10] = "ten";
    count[11] = "eleven";
    count[12] = "twelve";
    count[13] = "thirteen";
    count[14] = "fourteen";
    count[15] = "quarter";
    count[16] = "sixteen";
    count[17] = "seventeen";
    count[18] = "eighteen";
    count[19] = "nineteen";
    count[20] = "twenty";
    count[21] = count[20] + " "+ count[1];
    count[22] = count[20] + " "+ count[2];
    count[23] = count[20] + " "+ count[3];
    count[24] = count[20] + " "+ count[4];
    count[25] = count[20] + " "+ count[5];
    count[26] = count[20] + " "+ count[6];
    count[27] = count[20] + " "+ count[7];
    count[28] = count[20] + " "+ count[8];
    count[29] = count[20] + " "+ count[9];
    count[30] = "half";
    
    string ans = "";
    if(m == 0)
        ans = count[h] + " o' clock";
    else if(m <= 30){
        string tmp1 = ((m) == 1 ? "" : "s");
        string tmp2 = (m != 30 && m != 15 ? " minute"+ tmp1 : "");
        ans = count[m] + tmp2 + " past "+ count[h];
    }if(m > 30){
        string tmp1 = ((m) == 1 ? "" : "s");
        ans = count[60 - m]+ (m != 45 ? " minute" + tmp1 : "")+ " to " + count[h +1 ];
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
