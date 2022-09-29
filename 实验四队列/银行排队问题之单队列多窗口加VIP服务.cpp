#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<vector<int>> v;
    queue<vector<int>> vi;
    unordered_set<int> mark;
    int last_finish=0;
    for(int i=0;i<n;i++){
        vector<int> c(4);
        cin>>c[0]>>c[1]>>c[2];
        c[3]=i;
        if(c[2]!=0){
            vi.emplace(c);
        }
        v.emplace(c);
        mark.insert(i);
    }
    int m,vip;
    cin>>m>>vip;
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
        bool f=true;
        while(!vi.empty()&&vi.front()[0]<=time&&f){
            f=false;
            if(!mark.count(vi.front()[3])){
                vi.pop();
                f=true;
                continue;
            }
            if(qu[vip].empty()){
                if(vi.front()[1]>60){
                        qu[vip].push(60+time);
                }else{
                    qu[vip].push(time+vi.front()[1]);

                }
                // cout<<"push "<<vi.front()[0]<<" "<<vi.front()[1]<<" "<<vi.front()[2]<<" to "<<vip<<" in "<<time<<endl;
                mark.erase(vi.front()[3]);
                int wt=time-vi.front()[0];
                sum+=wt;
                m_wait_time=max(m_wait_time,wt);
                vi.pop();
                f=true;
            }
            // else{
            //     for(int i=0;i<m;i++){
            //         if(qu[i].empty()){
            //             qu[i].push(time+vi.front()[1]);
            //             int wt=time-vi.front()[0];
            //             m_wait_time=max(m_wait_time,wt);
            //             sum+=wt;
            //             vi.pop();
            //             f=true;
            //             break;
            //         }
            //     }
            // }
        }
        bool f1=true;
        while(!v.empty()&&v.front()[0]<=time&&f1){
            f1=false;
            if(!mark.count(v.front()[3])){
                v.pop();
                f1=true;
                continue;
            }
            if(v.front()[2]==1&&qu[vip].empty()){
                if(v.front()[1]>60){
                        qu[vip].push(60+time);
                }else{
                    qu[vip].push(time+v.front()[1]);
                }

                // cout<<"push "<<vi.front()[0]<<" "<<vi.front()[1]<<" "<<vi.front()[2]<<" to "<<vip<<" in "<<time<<endl;
                mark.erase(v.front()[3]);
                int wt=time-v.front()[0];
                sum+=wt;
                m_wait_time=max(m_wait_time,wt);
                v.pop();
                f1=true;
                continue;
            }
            for(int i=0;i<m;i++){
                if(qu[i].empty()){
                    mark.erase(v.front()[3]);
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