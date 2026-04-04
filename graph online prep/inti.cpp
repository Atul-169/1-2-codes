#include<iostream>
using namespace std;
class Samp{
    int a,b;
    public:
    Samp(){
        a=0;
        b=0;
    }
    Samp(int x,int y){
        a=x;
        b=y;    
    }
    void show(){
        cout<<"a and b are: "<<a<<" "<<b<<endl;

    }
};
int main(){
    Samp *r=new Samp[2];
    for(int i=0;i<2;i++){
        r[i].show();
    }
}
