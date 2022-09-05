#include<iostream>
using namespace std;
const int SIZE=1000;
class arr{
    int *array=nullptr;
    int size;
public:
    arr(int size,int arr1[],int n,int arr2[],int m):size(m+n){

        array=new int[SIZE];
        int i=0,j=0;
        int k=0;
        while(i<n||j<m){
            if(i<n&&j<m){
                if(arr1[i]<arr2[j]){
                    array[k++]=arr1[i++];
                }else{
                    array[k++]=arr2[j++];
                }
            }else if(i<n){
                array[k++]=arr1[i++];
            }else{
                array[k++]=arr2[j++];
            }
            
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
    
    ~arr(){
        if(array){
            delete []array;
        }
    }
};
int main(){
    int a;
    cin>>a;
    int b[a];
    for(auto &d:b){
        cin>>d;
    }
    int c;
    cin>>c;
    int e[c];
    for(auto &d:e){
        cin>>d;
    }
    arr tmp(a+c,b,a,e,c);
    

}