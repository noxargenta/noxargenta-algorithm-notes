#define maxsize 100

typedef int elemtype;

typedef struct

{

   elemtype elem[maxsize];

   int length;

}seqlist;
#define null 0

typedef int elemtype;

typedef struct node

{

   elemtype data;

   struct node *next;

}linklist;



#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
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