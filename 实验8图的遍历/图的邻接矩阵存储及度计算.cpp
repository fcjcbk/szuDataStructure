#include<iostream>
using namespace std;
int mp[1000][1000];
int find(string a, string ar[], int n){
    for(int i = 0; i < n; i++){
        if(ar[i] == a){
            return i;
        }
    }

    return -1;
}
int main(){
    int  t;
    cin>>t;
    for(int i = 0; i < t; i++){
        for(auto& a: mp){
            for(auto& b:a){
                b = 0;
            }
        }
        char c;
        int n;
        cin>>c>>n;
        
        string ar[n];
        for(int j = 0; j < n; j++){
            cin>>ar[j];
        }
        int k;
        cin>>k;
        string gu;
        if(c == 'D'){
            for(int j = 0; j < k; j++){
                string e,f;
                cin>>e>>f;
                mp[find(e, ar , n)][find(f, ar, n)]  = 1;
            }
            for(int j = 0; j < n; j++){
                for(int x = 0; x < n; x++){
                    if(x < n-1){
                        cout<<mp[j][x]<<" ";
                    }else{
                        cout<<mp[j][x]<<endl;
                    }
                }
            }
            for(int j = 0; j < n; j++){
                
                int chu = 0;
                int ru = 0;
                for(int x = 0; x < n; x++){
                    if(mp[j][x] == 1){
                        chu++;
                    }
                    if(mp[x][j] == 1){
                        ru++;
                    }
                }
                if(chu + ru != 0){
                    cout<<ar[j]<<": "<<chu<<" "<<ru<<" "<<chu + ru <<endl;
                }else{
                    gu += ar[j] +"\n";
                }
            }
        }else{
            for(int j = 0; j < k; j++){
                string e,f;
                cin>>e>>f;
                int a1 = find(e, ar , n);
                int a2 = find(f, ar, n);
                mp[a1][a2] = 1;
                mp[a2][a1] = 1;
            }
            for(int j = 0; j < n; j++){
                for(int x = 0; x < n; x++){
                    if(x < n-1){
                        cout<<mp[j][x]<<" ";
                    }else{
                        cout<<mp[j][x]<<endl;
                    }
                }
            }
            for(int j = 0; j < n; j++){
                
                int du = 0;
                for(int x = 0; x < n; x++){
                    if(mp[j][x] == 1){
                        du++;
                    }
                }
                if(du>0){
                    cout<<ar[j]<<": "<<du<<endl;
                }else{
                    gu += ar[j] +"\n";
                }

            }
            
        }
        if(gu != ""){
            cout<<gu;
        }
        
    }
}