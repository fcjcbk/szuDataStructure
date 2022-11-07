#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        int **a = new int*[n];
        for(int j = 0; j < n; j++){
            a[j] = new int[n];
        }
        bool f = true;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin>>a[j][k];
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(a[k][j] == 1 && a[j][l] == 1){
                        a[k][l] = 1;
                    }
                }
            }
        }
        bool ff = false;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(j != k){
                    if(!a[j][k]){
                        f = false;
                        break;
                    }
                }
            }
            if(ff){
                break;
            }
        }
        if(f){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        for(int j = 0; j < n; j++){
            delete []a[j];
        }
        delete []a;
    }
}