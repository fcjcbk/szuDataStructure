#include<bits/stdc++.h>
#include <vector>
using namespace std;
bool f = false;
void insert(vector<int> arr, const vector<int>& target){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int k = arr[i];
        int  j = i - 1;
        while(j >= 0 && arr[j] > k){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
        if(arr == target){
            f = true;
            continue;
        }
        if(f){
            cout<<"Insertion Sort"<<endl;
            cout<<arr[0];
            for(int g = 1; g < n; g++){
                cout<<" "<<arr[g];
            }
            cout<<endl;
            break;
        }
    }
}

class merge1{
    vector<int> tmp;
    void merge_sort(vector<int>& arr, const vector<int> &target){
        int n = arr.size();
        int max_len = 2;
        while(max_len < n){
            max_len *= 2;
        }
        for(int len = 2; len < max_len + 1 ; len *= 2){
            for(int start = 0; start < n; start += len){
                int i = start;
                int j = start + len / 2;
                if(j > n){
                    break;
                }
                int mid = j - 1;
                int index = start;
                while(i <= mid && j < start + len && j < n){
                    if(arr[i] <= arr[j]){
                        tmp[index++] = arr[i++];
                    }else{
                        tmp[index++] = arr[j++];
                    }
                    
                }
                while(i <= mid){
                    tmp[index++] = arr[i++];
                }
                while(j < len + start && j < n){
                    tmp[index++] = arr[j++];
                }
                for(int k = start; k < len + start && k < n ; k++){
                    arr[k] = tmp[k];
                }
                
            }
            // cout<<arr[0];
            // for(int i = 1; i < arr.size(); i++){
            //     cout<<" "<<arr[i];
            // }
            // cout<<endl;
            if(arr == target){
                f = true;
                continue;
            }
            if(f){
                cout<<"Merge Sort"<<endl;
                cout<<arr[0];
                for(int i = 1; i < arr.size(); i++){
                    cout<<" "<<arr[i];
                }
            }
        }
    }
public:
    void sort(vector<int>& nums, const vector<int> & target){
        tmp.resize((int)nums.size(), 0);
        merge_sort(nums, target);

    }
};

int main(){
    int n ;
    cin>>n;
    vector<int> arr(n), num(n);
    for(auto & c : arr){
        cin>>c;
    }
    for(auto & c : num){
        cin>>c;
    }
    vector<int> arr1 = arr;
    insert(arr, num);
    if(!f){
        merge1 m;
        m.sort(arr1, num);
    }
}

