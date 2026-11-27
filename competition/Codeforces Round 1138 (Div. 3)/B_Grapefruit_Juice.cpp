#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,k,p;//葡萄柚的数量、每杯果汁所需的水果数量，以及一杯果汁带来的愉悦点数。
    cin >> n >> k >> p;
    ll ans = 0;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    vector<ll> pre(n+1,0);
    for(ll i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    ll last = 0;
    ll ok=0;
    for(ll i=k;i<=n;i+=k){
        if(i+last>=k && pre[i] - pre[last] <= p){
            ans+=p;
            last = i;
        }
    }
    for(ll i=last;i<=n;i++){
        ans+=a[i];
    }
    cout  <<  ans << endl;

}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
/*B. Grapefruit Juice

time limit per test: 2 seconds

memory limit per test: 256 megabytes

input: standard input

output: standard output

After making the sweet toast, Sunny and Aubrey turned their attention to the grapefruits that Sunny had brought for their picnic.

They have $n$ grapefruits in total. The $i$\-th grapefruit has a taste value of $a_i$.

They can enjoy the grapefruits in two ways:

-   eat the $i$\-th grapefruit fresh and gain $a_i$ joy points;
-   make a glass of juice from any $k$ grapefruits and drink it to gain $p$ joy points.

Each grapefruit can be used only once: either eaten fresh or used to make a glass of juice. They can make any number of glasses of juice.

What is the maximum total number of joy points they can gain?

**Input**

Each test consists of multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers $n$, $k$, and $p$ ($1 \le n \le 2 \cdot 10^5$, $1 \le k \le n$, $1 \le p \le 10^9$) — the number of grapefruits, the number of fruits per glass of juice, and the joy points for a glass of juice.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the taste ratings of the grapefruits.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

**Output**

For each test case, print a single integer — the maximum possible total joy.

The answer may not fit into a 32-bit signed integer.

**Example**

Input

```


7

4 2 10

3 1 4 2

3 3 100

10 20 30

3 1 5

2 3 1

4 2 5

3 1 1 1

3 2 10

9 1 2

2 2 4

8 7

4 2 5

1 1 9 9

```

Output

```


20

100

15

10

19

15

23

```

**Note**

In the second test case, one glass gives $100$ points. Eating all three fruits fresh gives $10+20+30=60$ points.

In the fifth test case, the friends can squeeze the fruits rated $1$ and $2$ and eat the fruit rated $9$ fresh. This gives $10+9=19$ points. Eating all three fresh would give $12$ points.

In the seventh test case, using the two fruits rated $1$ for one glass gives $5+9+9=23$ points. Making no juice gives $20$ points, and making two glasses gives $10$.*/