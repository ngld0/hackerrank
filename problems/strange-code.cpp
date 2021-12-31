#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */

long strangeCounter(long t) {
    long n = 3, time = 1;
    //the time reset that cycle that contain the time t(t in range [time, time + value -1] of the initial cycle time)
  //example t = 21 => t in rage [10, 10 + 12 -1]
  // example t = 1000 => t in range [766, 766 + 768 -1];
    while (n*2 - 2 <= t){
        time += n;
        n *=2;
        //cout<< n <<"time: "<< time <<endl;
    }
    // in all cycles, the values will be decrease time by time, so when we know the cycle initial contain time t, then we can cal by (initial value - |t - initial time|) ->> boom~~~~
    return (long)(n - abs(time - t));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
