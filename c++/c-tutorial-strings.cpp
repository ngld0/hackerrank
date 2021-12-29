#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    std::string a, b;
    cin>> a >> b;
    cout<< a.length() <<" "<< b.length()<<endl;
    cout<< a +b<<endl;
    char t = a[0];
    a[0] = b[0];
    b[0] = t;
    cout<< a <<" "<< b<<endl;
     
    
    return 0;
}
