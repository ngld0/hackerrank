#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop{
    int start_time,end_time, duration;
};
struct Available_Workshops{
    int n;
    vector<Workshop> arr; 
};

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* avai_ws = new Available_Workshops;
    avai_ws->n = n;
    for(int i = 0;i<n;i++){
        Workshop a;
        a.start_time = start_time[i];
        a.end_time = start_time[i] + duration[i];
        a.duration = duration[i];
        avai_ws->arr.push_back(a);
    }
    return avai_ws;
    
}
bool compare(Workshop a, Workshop b){
    return a.end_time < b.end_time;
};
int CalculateMaxWorkshops(Available_Workshops* ptr){
    int ans = 0,curTime = 0;
    sort(ptr->arr.begin(), ptr->arr.end(), compare); 
    
    for(int i = 0;i< ptr->n;i++){
        
        if(ptr->arr[i].start_time>= curTime){
            ans++;
            curTime = ptr->arr[i].end_time;
        }
    }
    return ans;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
