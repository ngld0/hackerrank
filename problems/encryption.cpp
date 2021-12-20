#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    string str = "";
    for(int i = 0; i < s.length();i++){
        if(s[i] != ' ') str += s[i];
    }
    int L = str.length();
    int row = (int)sqrt(1.0 * L);
    int col = row ;
    
    while(row * col < L){
        if(row < col) row++;
        else col++;
    }
    string ans="";  
    
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            if(j*col + i < L)
                ans += str[j*col + i];
        ans += " ";
        cout<<ans<<endl;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
