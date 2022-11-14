#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        int **mp = new int*[n];
        for(int j = 0; j < n; j++){
            mp[j] = new int[n];
        }
        int *in = new int[n];
        int *vis = new int[n];

        for(int j = 0; j < n; j++){
            in[j] = 0;
            vis[j] = 0;
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin>>mp[j][k];
                if(mp[j][k] == 1){
                    in[k]++;
                }
            }
        }
        // for(int j = 0; j < n; j++){
        //     cout<<in[j]<<endl;
        // }
        for(int l = 0; l < 10*n; l++){
            for(int j = 0; j < n; j++){
                if(vis[j]){
                    continue;
                }
                if(in[j] == 0){
                    cout<<j<<" ";
                    vis[j] = 1;
                    for(int k = 0; k < n; k++){
                        if(mp[j][k] == 1){
                            in[k]--;
                        }
                    }
                }
                
                
            }
        }
        
        for(int j = 0; j < n; j++){
            delete [] mp[j];
        }
        delete[] in;
        delete[] vis;
        delete[] mp;
        cout<<endl;
    }
}