#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    
    int a,b;
    std::cin >> a>>b;
    for(int i = a; i<=b;i++){
        if(i==1) std::cout<<"one"<<std::endl;
        else if(i==2) std::cout<<"two"<<std::endl;
        else if (i==3) std::cout<<"three"<<std::endl;
        else if(i==4) std::cout<<"four"<<std::endl;
        else if(i==5) std::cout<<"five"<<std::endl;
        else if(i==6) std::cout<<"six"<<std::endl;
        else if(i==7) std::cout<<"seven"<<std::endl;
        else if(i==8) std::cout<<"eight"<<std::endl;
        else if(i==9) std::cout<<"nine"<<std::endl;
        else if(i >9){
            if(i%2) std::cout<<"odd"<<std::endl;
            else std::cout<<"even"<<std::endl;
            
        }
        
    }
    return 0;
}
