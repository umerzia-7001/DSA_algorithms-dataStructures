#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct Point{
    private:
    int x;
    int y;

    public:
    Point(int x_1,int y_1){ // constructor
        x = x_1;
        y = y_1;
    }
// setter getters 
    void setX(int x1){
        x = x1;

    }
    void setY(int y1){
        y = y1;

    }
    int getX(){
        return x;

    }
    int getY(){
        return y;
    }
    // function to summ cordinates 
    static Point sum(int x1,int y1, int x2,int y2){

        int x3 = x1 + x2;
        int y3 = y1 + y2;

        return Point(x3,y3);

    }
    // display cordinated of point
    void display(){
        cout<<x<<","<<y<<endl;

    }
};


int main(){

    int x1,x2,y1,y2;

    cout<<"Enter cordinates for p1  \n";
    cin>>x1;
    cin>>y1;
    cout<<"Enter cordinates for p2  \n";
    cin>>x2;
    cin>>y2;
    
    
    // making points 
    Point p(0,0);

    Point point_1(x1,y1);
    Point point_2(x2,y2);


    p = point_1.sum(x1,y1,x2,y2);
    cout<<"Coordinates for p1 + p2 are "<<endl;
    p.display();

    

    return 0;
};