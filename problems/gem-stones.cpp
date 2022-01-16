#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */
#define min(a,b) a>b?b:a;

int gemstones(vector<string> arr) {
    int ans = 101;
    int idx;
    vector<char> tt;  
   // find the arr with min length;
    for(int i = 0; i < arr.size();i++){
        if(ans > arr[i].length()){
            idx = i;
            ans = arr[i].length();
        }
    }
     // put each char of arr[idx] to a vector (differrent char), can be used by set in c++;
    for(int i = 0; i < arr[idx].length();i++){
       if(tt.empty() || !count(tt.begin(),tt.end(), arr[idx][i]))
            tt.push_back(arr[idx][i]);
            
    }
    //set answer is the vector size;
    ans =  tt.size();
    // check other arrays.
    for(int i = 0; i < arr.size();i++){
        //if the array is the array, that have min length then skip it.
        if(i == idx){
            continue;
        }
        // compare arr with each character in vector; if the arr not contains char in vector, then the result -1, respectively;
        for(int j = 0 ; j < tt.size();j++){
            
            if(tt[j] != -1 && arr[i].find(tt[j]) == string::npos){
                ans--;
                tt[j] = -1;
            }
        }
        
    }
    
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
