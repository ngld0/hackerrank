#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned modulo = (unsigned)(pow(2, 31));
    
    int N, S, P, Q;
    
    cin >> N >> S >> P >> Q;

    bool r = false;
    
    unsigned ans = 0;
    unsigned pre = S % modulo;
    unsigned cur = -1;
    unsigned i = 1;
    do 
    {
        cur = (pre * P + Q) % modulo;
        if (cur != pre) 
        {
            pre = cur;
            ans++;
        } 
        else 
        {
            r = true;
        }
        ++i;
    } while (i < N && !r);
    
    cout << ans + 1 << endl;    
    return 0;
}
