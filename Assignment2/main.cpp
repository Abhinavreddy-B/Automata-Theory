#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ROCK = 0;
int PAPER = 1;
int SCISSOR = 2;

class State {
    public:
        int num;
        int rps;
        int next[3];
        State(){
            num = 1;
            rps = 0;
            next[0] = next[1] = next[2] = 0;
        };
        State(int rps_input,int numb){
            rps = rps_input;
            num = numb;
        };
};


bool cmp(State &a,State &b){
    return a.num < b.num;
}

int main(){
    int n;
    cin>>n;
    int pos[n+1];
    vector<State> arr(n+1);
    for(int i=1;i<=n;i++){
        pos[i] = i;
        char x;
        int r,p,s;
        cin>>x>>r>>p>>s;
        // cout<<x<<'\n';
        switch(x){
            case 'R':
                arr[i].rps = ROCK;
                break;
            case 'P':
                arr[i].rps = PAPER;
                break;
            case 'S':
                arr[i].rps = SCISSOR;
                break;
            default:
                cout<<"Error\n";
        }
        arr[i].next[0] = r;
        arr[i].next[1] = p;
        arr[i].next[2] = s;
    }
    map<ll,State> associate;
    map<ll,bool> known;
    set<int> S;
    for(int i=1;i<=n;i++){
        S.insert(i);
    }
    // int start_state = foo(S,arr,associate,known);
    vector<State> ans;
    for(auto i: associate){
        ans.push_back(i.second);
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<'\n';
    for(auto i: ans){
        switch(i.rps){
            case 0:
                cout<<'R';
                break;
            case 1:
                cout<<'P';
                break;
            case 2:
                cout<<'S';
                break;
        }
        cout<<' '<<i.next[0]<<' '<<i.next[1]<<' '<<i.next[2]<<'\n';
    }
    // cout<<"Hello\n";
}