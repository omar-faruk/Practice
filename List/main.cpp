#include <bits/stdc++.h>
#include "list.h"

using namespace std;

class Location{
public:
    float lon;
    float lat;

    Location(){

    }
    Location(float ln,float lt){
        lon = ln;
        lat = lt;
    }

    bool operator >(Location const &element1){
        if(lon > element1.lon){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator >=(Location const &element1){
        if(lon >= element1.lon){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator == (Location const &element1){

        if((lon == element1.lon) && (lat == element1.lat)){
            return  true;
        }
        else{
            return false;
        }
    }

    void print(){
        printf("longitude: %f latitude:%f\n",lon,lat);
    }
};

int main()
{

    Location a[10];
    a[1] = Location(90.5,35.6);
    a[2] = Location(95.5,31.6);
    a[3] = Location(105.5,40.6);
    a[4] = Location(86.5,60.6);
    a[5] = Location(50.5,10.6);

    List<Location,10> mylist;
    mylist.insert(a[1]);
    mylist.insert(a[2]);
    mylist.insert(a[3]);
    mylist.insert(a[4]);
    mylist.insert(a[5]);

    cout<<"Insert into List"<<endl;



    cout<<"List current size: "<<mylist.size()<<endl;
    cout<<"List First Element: "<<mylist.first().lon<<endl;
    cout<<"List last Element: "<<mylist.last().lon<<endl;

    mylist.printList();

    cout<<mylist.exist(a[1])<<endl;


    return 0;
}