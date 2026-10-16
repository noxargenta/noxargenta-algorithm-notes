#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
struct Node{
    ll val;
    Node *next; 
};
Node *toucha_ctList(ll n){
    Node *head=nullptr;
    Node *cur=nullptr;
    cout  << "输入"  << n << "个数字" <<endl;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        Node * newdat=new Node();
        newdat->val=x;
        newdat->next=head;
        head=newdat;
    }
    return head;
}

Node * weicha_ctList(ll n){//n个数字的链表
    Node * head=nullptr;
    Node *cur=nullptr;
    cout  << "输入"  << n << "个数字" <<endl;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        Node *nextNode=new Node();
        nextNode->val=x;
        
    }

}

void solve() {

}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}