#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//return negative index when not found, possible is index of q.
// time limited! so we can use the STL lower bound function of vector
int getIdx(vector<int> v, int q){
    int left = 0, right = v.size()-1;
    int mid =0;
    while(left <= right){
        mid = left + (right -left)/2;
        if(v[mid] == q) return mid;
        else if(v[mid] > q) right = mid--;
        else if(v[mid] < q) left = mid++;
    }
    cout<<mid<<endl;
    return -mid;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i< n;i++){
        
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cin >> q;
    
    for(int i = 0 ; i < q;i++){
        int query;
        cin>>query;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), query);
        if (v[low - v.begin()] == query)
            cout << "Yes " << (low - v.begin()+1) << endl;
        else
            cout << "No " << (low - v.begin()+1) << endl;
    }
    
    return 0;
}
