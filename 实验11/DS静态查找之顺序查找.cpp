#include<bits/stdc++.h>
#include <climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int target;
        cin>>target;
        a[0] = target;
        for(int j = n - 1; ; j--){
            if(a[j] == target){
                if(j != 0){
                    cout<<j+1<<endl;
                }else{
                    cout<<"error"<<endl;
                }
                break;
            }
        }
    }
}