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
    Node *nextNode=new Node();
    Node *ini=nextNode;
    cout  << "输入"  << n << "个数字" <<endl;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        head=nextNode;
        head->val=x;
        if(i==n){
            head->next=nullptr;
            nextNode=nullptr;
        }else {
            head->next=new Node();
            nextNode=head->next;
        }

    }
    return ini;
}

void printNode(Node * head){
    if(head==nullptr){
        cout << "这是一个空链表\n";
        return;
    }
    Node *p=head;
    while(p!=nullptr){
        cout << p->val;
        if(p->next!=nullptr){
            cout << " -> ";
        }else {
            cout << " -> nullptr\n";
        }
        p=p->next;
    }
    cout << endl;

}
//链表反转
void reverseList(Node* &head){
    Node* cur=head;
    Node* pre=nullptr;
    while(cur!=nullptr){
        Node* next=cur->next;
        cur->next=pre;
        
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