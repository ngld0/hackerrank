#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q;
    std::cin >> Q;
    set<int> xSet;
    for(int i = 0 ; i < Q; i ++){
        int type, x;
        std::cin>>type >> x;
        
        if(type == 1) {
            
            xSet.insert(x);
            
        }if(type==2 &&xSet.find(x)!= xSet.end()){
            xSet.erase(x);
        }else if(type==3){
            if(xSet.find(x)!= xSet.end())
                std::cout<<"Yes"<<endl;
            else 
                std::cout<<"No"<<endl;;
        }
 
    }
    return 0;
}



