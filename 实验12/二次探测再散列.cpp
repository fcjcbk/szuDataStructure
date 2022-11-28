#include<iostream>
constexpr int HASH_NUM = 11;
constexpr int INF = 1 << 30;

using namespace std;
class Hash{
    int *arr = nullptr;
    int n;
public:
    Hash(int n) : n(n){
        arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = INF;
        }
    } 
    ~Hash(){
        if(arr){
            delete []arr;
        }
    }
    void push(int val){
        int pos = val % HASH_NUM;
        if(arr[pos] == INF){
            arr[pos] = val;
            return;
        }
        for(int i = 1; i < n; i++){
            int k = (pos + n + i * i) % n;
            if(arr[k] == INF){
                arr[k] = val;
                break;
            }else{
                k =  (pos + n - i * i) % n;
                if(arr[k] == INF){
                    arr[k] = val;
                    break;
                }
            }
        }
    }
    void search(int val){
        // int pos = val % HASH_NUM;
        int find = 0;
        // int t = 1;
        // while(arr[pos] != INF && arr[pos] != val){
        //     pos = (pos + n + t) % n;
        //     if(arr[pos] != INF && arr[pos] != val){
        //         t = -t;
        //         pos = (pos + n + t) % n;
        //         t = -t + 1;
        //     }
        //     find++;
        // }
        int pos = val % HASH_NUM;
        bool f = false;
        int ans = pos;
        if(arr[pos] == val){
            f = true;
        }
        if(!f){
            for(int i = 1; i < n; i++){
                int k = (pos + n + i * i) % n;
                find++;
                if(arr[k] == val){
                    f = true;
                    ans = k;
                    break;
                }else{
                    if(arr[k] == INF){
                        break;
                    }
                    find++;
                    k =  (pos + n - i * i) % n;
                    if(arr[k] == val){
                        f = true;
                        ans = k;
                        break;
                    }else if(arr[k] == INF){
                        break;
                    }
                }
            }
        }
        
        if(!f){
            cout<<0<<" "<<find+1<<endl;
        }else{
            cout<<1<<" "<<find+1<<" "<<ans+1<<endl;
        }
    }
    void print(){
        for(int i = 0; i < n; i++){
            string k = "NULL";
            if(arr[i] != INF){
                k = to_string(arr[i]);
            }
            if(i < n - 1){
                cout<<k<<" ";
            }else{
                cout<<k<<endl;
            }
        }
    }
};
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin>>n>>m;
        Hash hh(n);
        for(int j = 0; j < m; j++){
            int k;
            cin>>k;
            hh.push(k);
        }
        hh.print();
        int g;
        cin>>g;
        for(int j = 0; j < g; j++){
            int k;
            cin>>k;
            hh.search(k);
        }
    }
}