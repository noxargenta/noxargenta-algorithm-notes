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
    Node* list = nullptr;                        // 定义链表头指针，初始为空
    int choice;                                  // 定义菜单选择变量

    do {                                         // 进入菜单循环
        cout << "\n===== 单链表算法实验 =====\n"; // 输出菜单标题
        cout << "1. 头插法创建单链表\n";         // 输出菜单项 1
        cout << "2. 尾插法创建单链表\n";         // 输出菜单项 2
        cout << "3. 输出链表\n";                 // 输出菜单项 3
        cout << "4. 逆置链表\n";                 // 输出菜单项 4
        cout << "5. 删除值相等的结点（去重）\n"; // 输出菜单项 5
        cout << "0. 退出\n";                     // 输出菜单项 0
        cout << "请选择：";                      // 提示输入选择
        cin >> choice;                           // 读取用户选择

        switch (choice) {                        // 根据用户选择执行对应功能
        case 1: {                                // 选择 1：头插法创建单链表
            int n;                               // 定义结点个数变量
            cout << "请输入结点个数 n：";        // 提示输入结点个数
            cin >> n;                            // 读取结点个数
            destroyList(list);                   // 先释放旧链表内存
            list = toucha_ctList(n);              // 调用头插法创建链表
            cout << "头插法创建结果：";          // 输出提示
            printNode(list);                     // 输出创建后的链表
            break;                               // 跳出 switch
        }                                        // case 1 结束
        case 2: {                                // 选择 2：尾插法创建单链表
            int n;                               // 定义结点个数变量
            cout << "请输入结点个数 n：";        // 提示输入结点个数
            cin >> n;                            // 读取结点个数
            destroyList(list);                   // 先释放旧链表内存
            list = weicha_ctList(n);              // 调用尾插法创建链表
            cout << "尾插法创建结果：";          // 输出提示
            printNode(list);                     // 输出创建后的链表
            break;                               // 跳出 switch
        }                                        // case 2 结束
        case 3:                                  // 选择 3：输出链表
            cout << "当前链表：";                // 输出提示
            printNode(list);                     // 调用输出函数
            break;                               // 跳出 switch
        case 4:                                  // 选择 4：逆置链表
            reverseList(list);                   // 调用逆置函数
            cout << "逆置后链表：";              // 输出提示
            printNode(list);                     // 输出逆置后的链表
            break;                               // 跳出 switch
        case 5:                                  // 选择 5：删除值相等的结点
            delListNode(list);              // 调用去重函数
            cout << "删除值相等结点后链表：";    // 输出提示
            printNode(list);                     // 输出去重后的链表
            break;                               // 跳出 switch
        case 0:                                  // 选择 0：退出程序
            cout << "退出程序。" << endl;        // 输出退出提示
            break;                               // 跳出 switch
        default:                                 // 其他输入
            cout << "输入有误，请重新选择。" << endl; // 输出错误提示
        }                                        // switch 结束
    } while (choice != 0);                       // 当选择不为 0 时继续循环

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