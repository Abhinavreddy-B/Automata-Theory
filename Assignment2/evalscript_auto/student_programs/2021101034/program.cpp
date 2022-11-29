#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll returnbits(set<int> & s){
    ll ans=0;
    for(auto i: s){
        ans+=(1 << (i-1));
    }
    return ans;
}


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

int num=1;

int foo(set<int> s,vector<State> &arr,map<ll,State> &associate,map<ll,bool> &known){
    ll encoding = returnbits(s);
    // cout<<"Inside\n";
    if(known[encoding]){
        return associate[encoding].num;
    }
    known[encoding] = true;
    int cnt[3]={0,0,0};
    for(auto i: s){
        cnt[arr[i].rps]++;
    }
    int current_number = num;
    if(cnt[0] >= cnt [1] && cnt[0] >= cnt[2]){
        associate[encoding] = *(new State(1,num));
        num++;
    }else if(cnt[1] >= cnt [2] && cnt[1] >= cnt[0]){
        associate[encoding] = *(new State(2,num));
        num++;
    }else if(cnt[2] >= cnt [0] && cnt[2] >= cnt[1]){
        associate[encoding] = *(new State(0,num));
        num++;
    }
    set<int> s_new;
    for(int j=0;j<3;j++){
        for(auto i: s){
            if(arr[i].rps == j){
                s_new.insert(arr[i].next[associate[encoding].rps]);
            }
        }
        if(!s_new.empty()){
            associate[encoding].next[j] = foo(s_new,arr,associate,known);
        }else{
            associate[encoding].next[j] = associate[encoding].num;
        }
        s_new.clear();
    }
    return current_number;
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
    int start_state = foo(S,arr,associate,known);
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