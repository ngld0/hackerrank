#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box{
private:
    int l,b,h;
public:
    Box();
    Box(int, int, int);
    Box(Box &);
    int getLength();
    int getBreadth ();
    int getHeight ();
    long long CalculateVolume();
    bool operator<(Box&);
    friend ostream& operator<<(ostream& out, Box& B);
};
Box::Box(){
    l = b = h = 0;
}
Box::Box(int l, int b, int h){
    this->l = l;
    this->b  = b;
    this->h = h;
}
Box::Box(Box &B){
    this->b = B.b;
    this->l = B.l;
    this->h = B.h;
}
int Box::getLength(){
    
    return this->l;
}
int Box::getBreadth (){
    return this->b;
}
int Box::getHeight (){
    return this->h;
}
long long Box::CalculateVolume(){
    return (long long)l*h*b;
    
}
bool Box::operator<(Box& B){
    return (this->l < B.l || (this->b < B.b && this->l == B.l) ||(this->h < B.h && this->b == B.b && this->l ==B.l));
}
ostream& operator<<(ostream& out, Box& B){
    out<<B.l<<" "<<B.b<<" "<<B.h;
    return out;
}



