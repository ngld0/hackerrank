#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, rm_idx, a, b;
    std::cin>>N;
    std::vector<int> arr(N);
    
    for(int i = 0; i < N;i++){
        std::cin>>arr[i];
    }
    std::cin>>rm_idx;
    
    arr.erase(arr.begin()+rm_idx -1);
    
    std::cin>>a>>b;
    
    arr.erase(arr.begin()+a -1, arr.begin()+b-1);
    
    std::cout<<arr.size()<<std::endl;
    int it = 0;
    while(it<arr.size()){
        std::cout<<arr[it] << " ";
        it++;
    }
    return 0;
}
