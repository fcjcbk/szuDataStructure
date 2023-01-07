#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t = 0;
    int ans = 0;
    //如果数组交换过程中0只在最后一步交换到数组下标为0的位置则答案为数组中除0之外与自身下标不同元素的个数，否则要加一
    unordered_map<int, int>mp;
    vector<int> vt(n);
    for(int i = 0; i <  n; i ++){
        cin>>vt[i];
        if(vt[i] != 0 && vt[i] != i){
            ans++;
        }
        mp[vt[i]] = i;
        if(vt[i] == 0){
            t = i;
        }
    }
    vector<int> m = vt;
    sort(m.begin(), m.end());
    while(1){
        int f = mp[t];
        swap(vt[t], vt[mp[t]]);
        t = f;
        if(t == 0 && vt[t] == 0){
            if(vt != m){
                ans++;
            }
            break;

        }

        // ans++;
    }
    cout<<ans<<endl;
}