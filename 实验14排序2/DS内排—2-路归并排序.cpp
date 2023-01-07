#include<bits/stdc++.h>
#include <vector>
using namespace std;
class merge1{
    vector<string> tmp;
    // void merge_sort(vector<string>& arr, int left, int right){
    //     if(left >= right){
    //         return;
    //     }
    //     int mid = (left + right) >> 1;
    //     merge_sort(arr, left, mid);
    //     merge_sort(arr, mid + 1, right);
    //     int index = 0;
    //     int i = left, j = mid + 1;
    //     while(i <= mid && j <= right){
    //         if(arr[i] > arr[j]){
    //             tmp[index++] = arr[i++];
    //         }else{
    //             tmp[index++] = arr[j++];
    //         }
    //     }
    //     while(i <= mid){
    //         tmp[index++] = arr[i++];
    //     }
    //     while(j <= right){
    //         tmp[index++] = arr[j++];
    //     }
    //     for(int k = left; k <= right; k++){
    //         arr[k] = tmp[k - left];
    //     }
    //     cout<<arr[0];
    //     for(int i = 1; i < arr.size(); i++){
    //         cout<<" "<<arr[i];
    //     }
    //     cout<<endl;
    // }
    void merge_sort(vector<string>& arr){
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
                    if(arr[i] > arr[j]){
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
            cout<<arr[0];
            for(int i = 1; i < arr.size(); i++){
                cout<<" "<<arr[i];
            }
            cout<<endl;
        }
    }
public:
    void sort(vector<string>& nums){
        tmp.resize((int)nums.size(), "");
        merge_sort(nums);

    }
};
int main(){
    int t;
    cin>>t;
    merge1 m;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<string> str(n);
        for(auto & c : str){
            cin>>c;
        }
        m.sort(str);
        cout<<endl;

    }
}