#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    
    std::cin>> n;
    int j = n, i = 0, arr[n];
    while (i<n){
        std::cin>>arr[i];
        i++;
    }
    
    while(j--){
        std::cout<<arr[j]<<" ";
        
    }
    return 0;
}
