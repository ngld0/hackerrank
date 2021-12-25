#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    std::cin >> n >> q;
    vector<vector<int>> arr;
    for(int i = 0; i < n ; i++){
        int k; 
        std::cin>>k;
        int j = 0;
        vector<int> tem(k) ;
        for (int j = 0; j < k;j++){
            std::cin>>tem[j];
        }
        arr.push_back(tem);
       
    }
    while (q--){
        int ar, index;
        std::cin>>ar>>index;
        std::cout << arr[ar][index]<<endl;
    }
    
    return 0;
}
