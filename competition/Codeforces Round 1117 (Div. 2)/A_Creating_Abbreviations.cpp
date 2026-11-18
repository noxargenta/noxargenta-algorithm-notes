#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n,m;
    cin >> n  >> m;
    map<char,ll> cnt;
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        cnt[s[0]]++;
        if(s[0]>='a'  && s[0]<='z') cnt[s[0]+('A'-'a')]++ ;
        
    }
    for(ll i=0;i<m;i++){
        string s;
        cin >> s;
        for(ll j=0;j<s.size();j++){
            if(cnt[s[j]]==0){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
/*A. Creating Abbreviations
time limit per test1 second
memory limit per test256 megabytes






The Beaver was given a set of words S
, which initially contained n
 words. Then he performed the following operation m
 times:

The Beaver forms a sequence of one or more words from the set S
. The same word may appear in the sequence several times. An abbreviation∗
 is formed from the resulting phrase.
Then the Beaver adds the resulting abbreviation to S
 and can now use it in subsequent operations as an ordinary word.
You are given the n
 initial words that were in the set S
, and the set of abbreviations that the Beaver formed. Determine whether the Beaver made a mistake and whether all these abbreviations could have appeared as a result of the operation described above. Note that the abbreviations did not necessarily appear in the same order in which they are given to you.

∗
The abbreviation of a sequence is the word produced by the first letters of the words in the sequence. For example, the sequence birch OAK birch redwood produces the abbreviation BOBR.

AI 翻译






海狸得到了一个单词集合 S
，该集合最初包含 n
 个单词。然后他执行了以下操作 m
 次：

海狸从集合 S
 中选取一个或多个单词构成一个序列。同一个单词可以在该序列中出现多次。由所得短语形成缩写∗
。
然后海狸将得到的缩写加入 S
，并且现在可以在后续操作中将其作为普通单词使用。
给定集合 S
 中初始的 n
 个单词，以及海狸形成的缩写集合。判断海狸是否犯了错误，以及所有这些缩写是否都可能作为上述操作的结果出现。注意，这些缩写不一定按照输入中给出的顺序出现。

∗
一个序列的缩写是由该序列中各单词的首字母所构成的单词。例如，序列 birch OAK birch redwood 产生的缩写为 BOBR。







Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 — the number of ordinary words and the number of abbreviations, respectively (1≤n,m≤100
).

Each of the next n
 lines contains one string wi
 — an ordinary word (1≤|wi|≤20
).

Each of the next m
 lines contains one string ai
 — an abbreviation formed by Bobr (1≤|ai|≤20
).

All ordinary words consist of lowercase English letters, and all abbreviations consist of uppercase English letters. In each test case, all strings w1,w2,…,wn,a1,a2,…,am
 are pairwise distinct.

The total length of all strings over all test cases does not exceed 50000
.

AI 翻译






输入

每个测试包含多组测试用例。第一行包含测试用例数 t
（1≤t≤500
）。测试用例描述如下。

每组测试用例的第一行包含两个整数 n
 和 m
 —— 分别表示普通单词的数量和缩写的数量（1≤n,m≤100
）。

接下来的 n
 行中，每行包含一个字符串 wi
 —— 一个普通单词（1≤|wi|≤20
）。

接下来的 m
 行中，每行包含一个字符串 ai
 —— 一个由 Bobr 形成的缩写（1≤|ai|≤20
）。

所有普通单词均由小写英文字母组成，所有缩写均由大写英文字母组成。在每组测试用例中，所有字符串 w1,w2,…,wn,a1,a2,…,am
 两两不同。

所有测试用例中所有字符串的总长度不超过 50000
。







Output
For each test case, print "YES" if there exists a suitable order in which the given abbreviations could have appeared, and "NO" otherwise.

You may print each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

AI 翻译






输出

对于每个测试用例，如果存在一种合适的顺序使得给定的缩写能够出现，则输出 "YES"，否则输出 "NO"。

你可以以任意大小写形式输出每个字母（小写或大写）。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都将被接受为肯定答案。

Example
InputCopy
4
6 4
apple
grand
banana
great
cherry
good
AG
BG
CG
ABC
1 1
apple
AA
1 2
apple
A
AA
2 2
apple
avocado
B
BA
OutputCopy
YES
YES
YES
NO






Note
In the first test case, the order AG, BG, CG, ABC is suitable. The first three abbreviations can be created using the pairs of words apple and grand, banana and great, and cherry and good, respectively. After that, the abbreviation ABC can be created using the already created abbreviations AG, BG, and CG.

In the second test case, one can create AA using apple twice.

In the third test case, one can first create A using apple, and then create AA using apple and the already created abbreviation A.

In the fourth test case, it can be shown that the required order of creating the abbreviations does not exist.

AI 翻译






注意

在第一个测试用例中，顺序 AG、BG、CG、ABC 是合适的。前三个缩写可以分别使用单词对 apple 和 grand、banana 和 great、cherry 和 good 来创建。之后，缩写 ABC 可以使用已经创建的缩写 AG、BG 和 CG 来创建。

在第二个测试用例中，可以使用两次 apple 来创建 AA。

在第三个测试用例中，可以先使用 apple 创建 A，然后使用 apple 和已经创建的缩写 A 来创建 AA。

在第四个测试用例中，可以证明不存在所需的创建缩写顺序。*/