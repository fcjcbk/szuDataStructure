#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> vt(n, vector<int> (4));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin>>vt[i][j];
        }
        vt[i][3] = i; 
    }
    vector<vector<int>> vt1 = vt;
    sort(vt1.begin(), vt1.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return lhs[0] > rhs[0];
    });

    vector<vector<int>> vt2 = vt;
    sort(vt2.begin(), vt2.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return lhs[1] > rhs[1];
    });

    vector<vector<int>> vt3 = vt;
    sort(vt3.begin(), vt3.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return 1.0 * lhs[0] / lhs[2] > 1.0 * rhs[0]/ rhs[2];

    });

    vector<vector<int>> vt4 = vt;
    sort(vt4.begin(), vt4.end(), [](const vector<int>& lhs, const vector<int>& rhs){
        return 1.0 * lhs[1] / lhs[2] > 1.0 * rhs[1]/ rhs[2];
    });
    for(int i = 0; i < m; i++){
        int t;
        cin>>t;
        int minn = INT_MAX;
        int k = 0;
        for(int j = 0; j < n; j++){
            if(vt1[j][3] == t){
                if(j < minn){
                    minn = j;
                    k = 1;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(vt2[j][3] == t){
                if(j < minn){
                    minn = j;
                    k = 2;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(vt3[j][3] == t){
                if(j < minn){
                    minn = j;
                    k = 3;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(vt4[j][3] == t){
                if(j < minn){
                    minn = j;
                    k = 4;
                }
            }
        }
        if(i != m - 1){
            cout<<minn + 1<<":"<<k<<" ";
        }else{
            cout<<minn + 1<<":"<<k<<endl;
        }
    }
}