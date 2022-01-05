#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
// class template:

template <class T> class AddElements{
    T element;
    public: 
        AddElements(T x){
            element = x;
        }
        T add(T x){
            return (x + element);
        }
        T concatenate(T arg){
            return element + arg;
        }
};
// template <> class AddElements<string>{
//     string element;
//     public:
//         AddElements(string arg){
//             element = arg;
//         }
//         string concatenate(string arg){
//             return element + arg;
//         }
// };
// due to the time is limited, so we use the fast IO for competitive programming to boost speed up.
int speed_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static s = speed_up();

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
