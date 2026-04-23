#include <iostream>
using namespace std;

// 1. 定义单链表节点结构体 (标准格式)
struct ListNode {
    int val;
    ListNode* next;
    
    // 构造函数，方便初始化
    ListNode(int x) : val(x), next(nullptr) {}
};

// ==================== 以下为模块化功能函数 ====================

// 功能1：根据数组尾插法创建链表
ListNode* createList(int arr[], int size) {
    ListNode dummy(0); // 哑节点，方便统一操作
    ListNode* tail = &dummy;
    for (int i = 0; i < size; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return dummy.next;
}

// 功能2：打印链表 (严格符合样例格式)
void printList(const string& prefix, ListNode* head) {
    cout << prefix;
    ListNode* p = head;
    while (p != nullptr) {
        cout << p->val;
        p = p->next;
    }
    cout << endl;
}

// 功能3：核心算法 —— 求两链表的差集 Lc = La - Lb
ListNode* getDifference(ListNode* La, ListNode* Lb) {
    ListNode dummy(0); 
    ListNode* tail = &dummy;

    // 外层循环：遍历链表 La
    for (ListNode* p = La; p != nullptr; p = p->next) {
        bool found = false;
        
        // 内层循环：在链表 Lb 中查找是否存在 p->val
        for (ListNode* q = Lb; q != nullptr; q = q->next) {
            if (p->val == q->val) {
                found = true; // 在 Lb 中找到了，说明不是差集元素
                break;        // 提前退出内层循环，稍微优化性能
            }
        }
        
        // 如果在 Lb 中没找到，则将其作为新节点加入 Lc
        if (!found) {
            tail->next = new ListNode(p->val);
            tail = tail->next;
        }
    }
    
    return dummy.next;
}

// 功能4：释放链表内存 (好习惯，加分项！)
void destroyList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==================== 主函数 ====================

int main() {
    // 准备测试数据 (在作业中用基础数组传递最稳妥)
    int arrA[] = {2, -8, 4, 5, 11, 7};
    int arrB[] = {2, 3, 5, 6};
    
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);

    // 1. 创建链表
    ListNode* La = createList(arrA, sizeA);
    ListNode* Lb = createList(arrB, sizeB);

    // 2. 打印原链表
    printList("链表La:", La);
    printList("链表Lb:", Lb);

    // 3. 计算差集 Lc
    ListNode* Lc = getDifference(La, Lb);

    // 4. 打印结果
    printList("链表Lc:", Lc);

    // 5. 释放动态分配的内存 (展现扎实的工程素养)
    destroyList(La);
    destroyList(Lb);
    destroyList(Lc);

    return 0;
}