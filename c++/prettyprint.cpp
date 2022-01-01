#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        std::cout << resetiosflags(ios::uppercase|ios::scientific);
        std::cout << std::setiosflags (ios::left|ios::fixed);
        std::cout << setw(0) << std::hex;
        std::cout << std::setiosflags (ios::showbase);
        std::cout << (unsigned long)A << std::endl;
        
        std::cout << resetiosflags(ios::showbase);
        std::cout << setw(0xf) << setfill('_')<< std::dec ;
        std::cout << setiosflags (ios::showpos) << setprecision(2);
        std::cout  << B << endl;
        
        std::cout << resetiosflags(ios::fixed|ios::showpos);
        std::cout << setiosflags (ios::scientific | ios::uppercase) << setprecision(9);
        std::cout << C << std::endl;
		/* Enter your code here */

	}
	return 0;

}
