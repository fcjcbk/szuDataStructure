#include<bits/stdc++.h>
using namespace  std;
void shift(vector<int>& arr, int start, int end){
    int parent = start;
    int child = 2 * parent + 1;
    while(child <= end){
        if(child+ 1 <= end && arr[child+ 1] < arr[child]){
            child++;
        }
        if(arr[parent] < arr[child]){
            break;
        }
        swap(arr[parent], arr[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}
void build_heap(vector<int>& arr){
    int len = arr.size() - 1;
    for(int i = len/2; i >= 0; i--){
        shift(arr, i, len);
    }
}
void print(const vector<int>& arr);
void heap_sort(vector<int>& arr){
    build_heap(arr);
    print(arr);
    int len = arr.size() - 1;
    for(int i = arr.size() - 1; i >= 1 ; i--){
        swap(arr[i], arr[0]);
        len--;
        shift(arr, 0, len);
        print(arr);
    }
    
}
void print(const vector<int>& arr){
    cout<<arr.size()<<" ";
    cout<<arr[0];
    for(int i = 1; i < arr.size(); i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
void solve(vector<int>& arr, int a, int b){
    int index1 = -1;
    int index2 = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == a){
            index1 = i;
        }
        if(arr[i] == b){
            index2 = i;
        }
    }
    if(abs(index1 -index2) == 1){
        cout<<"T"<<endl;
    }else{
        cout<<"F"<<endl;
    }
    
}
void solve1(vector<int>& arr, int a, int b){
    int index1 = -2;
    int index2 = -2;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == a){
            index1 = i;
        }
        if(arr[i] == b){
            index2 = i;
        }
    }
    if(index1 == (index2 - 1)/2){
        cout<<"T"<<endl;
    }else{
        cout<<"F"<<endl;
    }
    
}
void solve3(vector<int>& arr, int a, int b){
    int index1 = -2;
    int index2 = -2;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == a){
            index1 = i;
        }
        if(arr[i] == b){
            index2 = i;
        }
    }
    if(index1 == 2* index2 + 1 || index1 == 2*index2 + 2){
        cout<<"T"<<endl;
    }else{
        cout<<"F"<<endl;
    }
    
}
int main(){
    int n, t;
    cin>>n>>t;
    vector<int> arr(n);
    for(auto& a : arr){
        cin>>a;
    }
    build_heap(arr);
    string s;
    getchar();
    for(int i = 0; i < t; i++){
        getline(cin, s);
        int m = s.size();
        if(s[m - 1] == 't'){
            int tmp = 0;
            for(auto & c : s){
                if(isdigit(c)){
                    tmp = tmp * 10 + c -'0';
                }else{
                    break;
                }
            }
            if(tmp == arr[0]){
                cout<<"T"<<endl;
            }else{
                cout<<"F"<<endl;
            }
        }else if(s[m - 1] == 's'){
            int tmp1 = 0, tmp2 = 0;
            int index = 0;
            for(auto & c : s){
                if(isdigit(c)){
                    tmp1 = tmp1 * 10 + c -'0';
                    index++;
                }else{
                    break;
                }
            }
            s = s.substr(index + 5);
            for(auto & c : s){
                if(isdigit(c)){
                    tmp2 = tmp2 * 10 + c -'0';
                    index++;
                }else{
                    break;
                }
            }
            solve(arr, tmp1, tmp2);

        }else{
            bool flag = true;
            for(const auto & c : s){
                if(c == 'r'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int tmp1 = 0, tmp2 = 0;
                int index = 0;
                for(auto & c : s){
                    if(isdigit(c)){
                        tmp1 = tmp1 * 10 + c -'0';
                        index++;
                    }else{
                        break;
                    }
                }
                s = s.substr(index + 15);
                for(auto & c : s){
                    if(isdigit(c)){
                        tmp2 = tmp2 * 10 + c -'0';
                        index++;
                    }else{
                        break;
                    }
                }
                solve3(arr, tmp1, tmp2);
            }else{
                int tmp1 = 0, tmp2 = 0;
                int index = 0;
                for(auto & c : s){
                    if(isdigit(c)){
                        tmp1 = tmp1 * 10 + c -'0';
                        index++;
                    }else{
                        break;
                    }
                }
                s = s.substr(index + 18);
                for(auto & c : s){
                    if(isdigit(c)){
                        tmp2 = tmp2 * 10 + c -'0';
                        index++;
                    }else{
                        break;
                    }
                }
                solve1(arr, tmp1, tmp2);
            }
        }
        
    }
}