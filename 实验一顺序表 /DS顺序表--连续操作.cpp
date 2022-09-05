#include<iostream>
using namespace std;
const int SIZE=1000;
class arr{
    int *array=nullptr;
    int size;
public:
    arr(int size,int arra[]):size(size){

        array=new int[SIZE];
        for(int i=0;i<size;i++){
            array[i]=arra[i];
        }
        print();
    }
    void print(){
        cout<<size<<" ";
        for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    void multiInsert(int index,int n,int val[]){
        if(n+size>=SIZE||index<0||index>=size+1){
            return;
        }
        for(int i=size-1;i>=index;i--){
            array[i+n]=array[i];
        }
        // print();
        for(int i=0;i<n;i++){
            array[index+i]=val[i];
        }
        size+=n;
        print();
    }
    void multiDel(int index,int n){
        if(index<0||index>size||n>size){
            return;
        }
        for(int i=index;i<index+n;i++){
            array[i]=array[i+n];
            
        }
        size-=n;
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
    int s,si;
    cin>>s>>si;
    int use[si];
    for(auto &c:use){
        cin>>c;
    }
    tmp.multiInsert(s-1,si,use);
    int start,n;
    cin>>start>>n;
    tmp.multiDel(start-1,n);

}