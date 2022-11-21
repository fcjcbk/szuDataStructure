#include<bits/stdc++.h>
using namespace std;
double find(double t){
    double left = 0;
    double right =t;
    double ans= 0;
    while(abs(ans * ans - t) >= 0.00001){
        ans = (left + right) / 2;
        double tmp = ans * ans;
        if(tmp > t){
            right = ans;
        }else{
            left = ans;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        double k;
        cin>>k;
        printf("%.3lf\n", find(k));
    }
}