#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    if(n < k) return;
    deque<int > ans(k);
    for(int i =0 ; i < n;i++){
        // init k size element of queue
        if (ans.empty()){
            ans.push_back(i);
        }
        // pop element outside k size
        if (ans.front() <= (i - k)){
            ans.pop_front();
        }
        // move max
        while (!ans.empty() && arr[i] >= arr[ans.back()]){
            ans.pop_back();
        }
        ans.push_back(i);
        
        if (i >= (k - 1)){
            cout << arr[ans.front()] << " ";
        }
    }
    cout<<endl;
    
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
