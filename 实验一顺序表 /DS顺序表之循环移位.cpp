#include<iostream>
using namespace std;
const int SIZE=1000;
class arr{
    int *array=nullptr;
    int size;
public:
    arr(int size,int arra[]):size(size){

        array=new int[size];
        for(int i=0;i<size;i++){
            array[i]=arra[i];
        }
        print();
    }
    void print(){
        // cout<<size<<" ";
        for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    void right(int n){
        int *p=new int[size];
        for(int i=0;i<size;i++){
            p[(i+n)%size]=array[i];
        }
        delete []array;
        array=p;
        print();
    }
    void left(int n){
        int *p=new int[size];
        for(int i=0;i<size;i++){
            p[(i-n+size)%size]=array[i];
        }
        delete []array;
        array=p;
        print();
    }
    ~arr(){
        if(array){
            delete []array;
        }
    }
};
int main(){
    int t;
    cin>>t;
    int a[t];
    for(auto&c:a){
        cin>>c;
    }
    arr tmp(t,a);
    int c,d;
    for(int i=0;i<2;i++){
        cin>>c>>d;
        if(c==0){
            tmp.left(d);
        }else{
            tmp.right(d);
        }
    }
    
}