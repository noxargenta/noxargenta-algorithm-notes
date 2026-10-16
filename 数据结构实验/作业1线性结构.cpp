#include <iostream>
using namespace std;

#define maxsize 100
#define null 0
typedef int elemtype;

typedef struct
{
    elemtype elem[maxsize];
    int length;
} seqlist;

typedef struct node
{
    elemtype data;
    struct node *next;
} linklist;

// 链表带头结点，按从小到大的顺序插入
void insert(linklist *head, elemtype x)
{
    linklist *p = head;
    while (p->next != null && p->next->data < x)
        p = p->next;

    linklist *s = new linklist;
    s->data = x;
    s->next = p->next;
    p->next = s;
}

// 删除顺序表中所有值为 x 的元素
void del(seqlist &L, elemtype x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] != x)
        {
            L.elem[k] = L.elem[i];
            k++;
        }
    }
    L.length = k;
}

int main()
{
    int n;
    elemtype x;

    linklist *head = new linklist;
    head->next = null;
    linklist *tail = head;

    cout << "输入链表长度：";
    cin >> n;

    cout << "按从小到大的顺序输入链表元素：";
    for (int i = 0; i < n; i++)
    {
        linklist *s = new linklist;
        cin >> s->data;
        s->next = null;
        tail->next = s;
        tail = s;
    }

    cout << "输入要插入的数：";
    cin >> x;
    insert(head, x);

    cout << "插入后的链表：";
    for (linklist *p = head->next; p != null; p = p->next)
        cout << p->data << " ";
    cout << endl;

    seqlist L;
    cout << "输入顺序表长度（0~100）：";
    cin >> L.length;

    if (L.length < 0 || L.length > maxsize)
    {
        cout << "长度不合法" << endl;
    }
    else
    {
        cout << "输入顺序表元素：";
        for (int i = 0; i < L.length; i++)
            cin >> L.elem[i];

        cout << "输入要删除的数：";
        cin >> x;
        del(L, x);

        cout << "删除后的顺序表：";
        for (int i = 0; i < L.length; i++)
            cout << L.elem[i] << " ";
        cout << endl;
    }

    while (head != null)
    {
        linklist *p = head;
        head = head->next;
        delete p;
    }

    return 0;
}