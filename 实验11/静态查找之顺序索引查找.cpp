#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> m(n);
    for(auto& c : m){
        cin>>c;
    }
    int k;
    cin>>k;
    vector<pair<int,int>> fu(k);
    for(int i = 0; i < k; i++){
        cin>>fu[i].first;
    }
    for(int i = 0; i < fu.size(); i++){
        if(i > 0){
            auto& [a,b] = fu[i];
            b = upper_bound(m.begin(), m.end(), fu[i-1].first) - m.begin();
        }else{
            fu[i].second = 0;
        }
        
    }
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int tmp;
        cin>>tmp;
        int start = 0;
        int ans = 0;
        for(auto & [a,b] : fu){
                ans++;

            if(tmp <= a){
                start = b;
                break;
            }
        }
        for(int j = start; j < n; j++){
            ans++;
            if(m[j] == tmp){
                cout<<j+1<<"-"<<ans<<endl;
                break;
            }
            if(j == n - 1){
                cout<<"error"<<endl;
            }
        }
    }
}