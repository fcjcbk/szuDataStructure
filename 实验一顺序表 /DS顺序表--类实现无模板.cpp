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
    void insert(int index,int val){
        if(size+1>SIZE||index>=size+1||index<0){
            cout<<"error"<<endl;
            return;
        }
        for(int i=size+1;i>index;i--){
            array[i]=array[i-1];
        }
        array[index]=val;
        size++;
        print();
    }
    void delete_elem(int index){
        if(index<0||index>size){
            cout<<"error"<<endl;
            return;
        }
        for(int i=index;i<size;i++){
            array[i]=array[i+1];
            
        }
        size--;
        print();
    }
    int search(int index){
        if(index<0||index>size){
            cout<<"error"<<endl;
            return -1;
        }
        return array[index];
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
    cin>>c>>d;
    tmp.insert(c-1,d);
    cin>>c>>d;
    tmp.insert(c-1,d);
    cin>>c;
    tmp.delete_elem(c-1);
    cin>>c;
    tmp.delete_elem(c-1);
    cin>>c;
    int k=tmp.search(c-1);
    if(k>=0){
        cout<<k<<endl;
    }
    cin>>c;
    k=tmp.search(c-1);
    if(k>=0){
        cout<<k<<endl;
    }

}