#include<bits/stdc++.h>
#include <vector>
using namespace std;

class arr{
    vector<int> vt;
    int size;
public:
    arr(vector<int> ar){
        vt = ar;
        size = ar.size();
    }
    void print(){
        cout<<size<<" ";
        for(int i = 0; i < size; i++){
            cout<<vt[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int pos, int target){
        if(pos > size || pos < 0){
            cout<<"ERROR"<<endl;
            return;
        }
        if(size + 1 > vt.size()){
            vt.push_back(0);
        }
        for(int i = size - 1; i >= pos; i--){
            vt[i + 1] = vt[i]; 
        }
        vt[pos] = target;
        size++;
        print();
    }
    void del(int pos){
        if(pos < 0 || pos >= size){
            cout<<"ERROR"<<endl;
            return;
        }
        for(int i = pos; i < size - 1; i++){
            vt[i] = vt[i + 1];
        }
        size--;
        print();
    }
    void del_t(int target){
        int k = -1;
        for(int i = 0; i < size; i++){
            if(vt[i] == target){
                k = i;
                break;
            }

        }
        del(k);
    }
    void find(int target){
        int k = -1;
        int time = 0;
        for(int i = size - 1; i >= 0; i--){
            time++;
            if(vt[i] == target){
                k = i;
                break;
            }
        }
        if(k != -1){
            cout<<1<<" "<<k + 1<<" "<<time<<endl;
        }else{
            cout<<"0 0 "<<time + 1<<endl;
        }
    }
};
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<int> ar(n);
        for(auto & c : ar){
            cin>>c;
        }
        arr a(ar);
        a.print();
        int c, b;
        cin>>c>>b;
        a.insert(c - 1, b);
        cin>>c;
        a.del(c - 1);
        cin>>b;
        a.del_t(b);
        cin>>c;
        a.find(c);
        
    }
    cout<<endl;
    cout<<endl;
}