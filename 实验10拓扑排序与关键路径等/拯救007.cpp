#include<bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
double get_dis(double x, double y, double x1, double y1){
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
int main(){
    int n;
    double d;
    cin>>n>>d;
    queue<int> qu;
    vector<pair<double,double>> point(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++){
        double a, b;
        cin>>a>>b;
        point[i] = make_pair(a, b);
        if(get_dis(a,b , 0, 0) <= 15.0/2 + d){
            qu.push(i);
        }
    }
    bool flag = false;
    while(!qu.empty()){
        int p  = qu.front();
        auto [a,b] = point[p];
        vis[p] = true;
        qu.pop();
        if(a + d >= 50.0 || a - d <= -50.0 || b + d >= 50.0 || b - d <= -50.0){
            flag = true;
            break;
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == false && get_dis(a, b, point[i].first, point[i].second) <= d){
                qu.push(i);
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}