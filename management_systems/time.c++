
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct Time{

    private:
    int hour;
    int min;
    int sec;

    public:
    // constructor

    Time(int hours,int mins,int secs){
        hour = hours;
        min = mins;
        sec = secs;
    }
    // setter getters 
    void setH(int h){
        hour = h;

    }
    void setM(int m){
        min = m;

    }
    int setS(int s){
        sec = s;

    }
    int getH(){
        return hour;

    }
    int getM(){
        return min;
    }
    
    int getS(){
        return sec;
    }

    void print_in_sec(){

        sec = 360*getH() + 60*getM() + getS();

        cout<<" Total time in second is : "<<endl;


    }
    






};


int main(){
    string time;
    int h,m,s;

    // asking timer from user 
    cout<<"Enter time (hh:mm:ss): \n";
    cin>>time;

struct tm;
strptime(time, "%d %b %Y %H:%M:%S", &tm);

printf("year: %d; month: %d; day: %d;\n", tm.tm_year, tm.tm_mon, tm.tm_mday);





    Time t(int h, int m,int s);

    //t.print_in_sec();




    return 0;

};