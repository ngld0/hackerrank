#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size ;
    
    cin >> size;
    vector<int> v(size);
    for(int i = 0;i<size;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        cout << it<<" ";
    }
    return 0;
}
