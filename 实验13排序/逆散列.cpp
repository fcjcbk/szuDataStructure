#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    vector<int> arr(n);
    vector<int> ans;
    vector<int> tmp;
    unordered_set<int> book;
    int count = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        if(t < 0){
            arr[i] = -1;
            continue;
        }
        count++;
        int j = i - t % n;
        while(j < 0){
            j = j + n;
        }
        mp[t] = j;

    
        arr[i] = t;
    }
    tmp = arr;
    sort(arr.begin(), arr.end());
    while(ans.size() != count){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                int t = mp[arr[i]];
                if(mp[arr[i]] == 0){
                    ans.push_back(arr[i]);
                    book.insert(arr[i]);
                    arr[i] = -1;
                    break;
                }else{
                    int q = arr[i] % n;
                    bool flag = true;
                    for(int j = q; j < q + t; j++){
                        if(!book.count(tmp[j%n])){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        ans.push_back(arr[i]);
                        book.insert(arr[i]);
                        arr[i] = -1;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans[0];
    for(int i = 1; i < count; i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
}