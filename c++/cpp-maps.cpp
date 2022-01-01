#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    std::cin>>Q;
    std::map<string, int> st;
    for(int i = 0;i<Q;i++){
        int type;
        std::cin>>type;
        string name;
        int mark;
        std::cin>> name;
        if(type ==1) {
            std::cin >> mark;
            if(st.find(name)!= st.end()){
               int s = st.find(name)->second;
               st.erase(name);
               st.insert(pair<string, int>(name, mark + s));
            }  else          
                st.insert(pair<string, int>( name, mark));
        }
        else if(type==2){
            if(st.find(name)!= st.end())
                st.erase(name);
        }
        else if(type==3){
            if(st.find(name)!= st.end())
                std::cout<<st.find(name)->second <<endl;
            else 
                std::cout<<0<<endl;
        }
        
    }

    return 0;
}



