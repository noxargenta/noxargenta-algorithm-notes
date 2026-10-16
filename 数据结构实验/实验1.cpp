#include <bits/stdc++.h>///严坤鹏 2025214550
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
    Node* next=nullptr;
    while(cur!=nullptr){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    head=pre;
}

void delListNode(Node*& head) {             
    Node* p = head;                              

    while (p != nullptr) {                       
        Node* q = p;                             
        while (q->next != nullptr) {             
            if (q->next->val == p->val) {      
                Node* del = q->next;             
                q->next = del->next;             
                delete del;                      
            } else {                             
                q = q->next;                     
            }                                    
        }                                        
        p = p->next;                             
    }                                            
}   
void destroyList(Node*& head) {                  
    while (head != nullptr) {                    
        Node* temp = head;                       
        head = head->next;                       
        delete temp;                             
    }                                            
}    

void solve() {
    Node* list = nullptr;                       
    int choice;                                 

    do {                                        
        cout << "\n===== 单链表算法实验 =====\n";
        cout << "1. 头插法创建单链表\n";        
        cout << "2. 尾插法创建单链表\n";        
        cout << "3. 输出链表\n";                
        cout << "4. 逆置链表\n";                
        cout << "5. 删除值相等的结点（去重）\n";
        cout << "0. 退出\n";                    
        cout << "请选择：";                     
        cin >> choice;                          

        switch (choice) {                       
        case 1: {                               
            int n;                              
            cout << "请输入结点个数 n：";       
            cin >> n;                           
            destroyList(list);                  
            list = toucha_ctList(n);            
            cout << "头插法创建结果：";         
            printNode(list);                    
            break;                              
        }                                       
        case 2: {                               
            int n;                              
            cout << "请输入结点个数 n：";       
            cin >> n;                           
            destroyList(list);                  
            list = weicha_ctList(n);            
            cout << "尾插法创建结果：";         
            printNode(list);                    
            break;                              
        }                                       
        case 3:                                 
            cout << "当前链表：";               
            printNode(list);                    
            break;                              
        case 4:                                 
            reverseList(list);                  
            cout << "逆置后链表：";             
            printNode(list);                    
            break;                              
        case 5:                                 
            delListNode(list);              // 
            cout << "删除值相等结点后链表：";   
            printNode(list);                    
            break;                              
        case 0:                                 
            cout << "退出程序。" << endl;       
            break;                              
        default:                                
            cout << "输入有误，请重新选择。" << endl;
        }                                       
    } while (choice != 0);                      

    destroyList(list);                           // 程序结束前释放链表内存
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}