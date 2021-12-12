#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */


string timeConversion(string s) {
    int hh,mm,ss;
    hh= (s[0]-'0')*10 + (s[1]-'0');
    mm= (s[3]-'0')*10+(s[4]-'0');
    ss=(s[6]-'0')*10+(s[7]-'0');
    if (s[8]=='A'&& hh==12 )
    {
        hh=00;
        
    }
    else if ( s[8]=='P')
    {
        if ( hh==12 )
        {
            hh=12;
            
        }
        else 
        {
            hh=hh+12;      
        }
    }
    //format the result with 2 digit when convert int to string
    std::stringstream hr, mn, sec;
    hr << std::setw(2) << std::setfill('0') << hh;
    mn << std::setw(2) << std::setfill('0') << mm;
    sec << std::setw(2) << std::setfill('0') << ss;
    //printf("%02d:%02d:%02d\n", hr, mm, sec);
    
    return hr.str() +":"+mn.str()+":"+sec.str();
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
