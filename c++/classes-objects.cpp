#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student{
    
private: 
    int score[5];
public:
    void input();
    int calculateTotalScore();
};
void Student::input(){
    //int s1, s2, s3, s4, s5;
    cin >> score[0]>> score[1] >>score[2]>>score[3]>>score[4];
}
int Student::calculateTotalScore(){
    
    return score[0] + score[1] + score[2] + score[3] + score[4];
}

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
