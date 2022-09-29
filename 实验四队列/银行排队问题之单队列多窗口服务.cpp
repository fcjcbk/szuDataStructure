#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<vector<int>> v;
    int last_finish=0;
    for(int i=0;i<n;i++){
        vector<int> c(2);
        cin>>c[0]>>c[1];
        
        v.emplace(c);
    }
    int m;
    cin>>m;
    vector<queue<int>> qu(m);
    vector<int> ans(m);
    int m_wait_time=0;
    int time=0;
    int sum=0;
    bool f=false;
    while(time<200000){
        // f=false;
        // if(time==67){
        //     cout<<"hello"<<endl;
        // }
        for(int i=0;i<m;i++){
            while(!qu[i].empty()&&time>=qu[i].front()){
                last_finish=max(last_finish,time);
                // cout<<"finish: in "<<i<<" finish time is "<<time<<endl;
                ans[i]++;
                qu[i].pop();
            }
        }
        
        bool f1=true;
        while(!v.empty()&&v.front()[0]<=time&&f1){
            f1=false;
            for(int i=0;i<m;i++){
                if(qu[i].empty()){
                // cout<<"push "<<v.front()[0]<<" "<<v.front()[1]<<" "<<v.front()[2]<<" to "<<i<<" in "<<time<<" will finish in "<<time+v.front()[1]<<endl;;
                    if(v.front()[1]>60){
                        qu[i].push(60+time);
                    }else{
                        qu[i].push(time+v.front()[1]);

                    }
                    int wt=time-v.front()[0];
                    m_wait_time=max(m_wait_time,wt);
                    sum+=wt;
                    v.pop();
                    f1=true;
                    break;
                }
            }
        }
        time++;
        // cout<<time<<endl;
    }

    printf("%.1f %d %d\n",static_cast<double>(sum)/n,m_wait_time,last_finish);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    


}