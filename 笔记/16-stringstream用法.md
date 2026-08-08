# stringstream 用法

来源：[D_Mail_Institution_Codes.cpp](../competition/niukemanyschool7/D_Mail_Institution_Codes.cpp) — 2025牛客多校第七场 D

## 核心用法：按空格分词

`stringstream` 用流运算符 `>>` 提取，自动以**空白字符（空格 / Tab / 换行）**为分隔符切词。这是处理"一行里不知道有几个数"的利器。

```cpp
#include <sstream>   // 或直接 <bits/stdc++.h>

string line;
getline(cin, line);          // 读入一整行

stringstream ss(line);       // 从字符串构造流
string word;
while (ss >> word) {         // 逐个提取，直到流为空
    // 处理 word（以空白为分隔的每个单词）
}
```

## 例题：D_Mail_Institution_Codes

### 场景

每行是一串 **由空格分隔的单词**（行内单词个数不定，行数 n 已知），需要把每个单词分别存下来。用 stringstream 逐行分词即可。

```cpp
void solve() {
    ll n;
    cin >> n;

    vector<vector<string>> a(n);       // a[i] 存第 i 行的所有单词
    for (ll i = 0; i < n; i++) {
        string line;
        getline(cin, line);            // 读一整行
        stringstream ss(line);         // 构造流
        string word;
        while (ss >> word) {           // 按空格切词
            a[i].push_back(word);
        }
    }

    // 后续比较每个单词的首字母，做压缩输出……
}
```

### 常见坑

- `cin >> n` 之后直接 `getline` 会先读到那一行的换行，得到空串。**要么先 `getline` 消费掉残留换行，要么把 `cin` 换成整行读取再解析**
- 上面代码中处理方式是：`getline(cin, s); s = "";` 先吞掉残留换行，再开始循环读取

## 其他常用操作

```cpp
stringstream ss;

// 1. 数字 → 字符串
int x = 123;
stringstream s1; s1 << x;
string str = s1.str();               // "123"

// 2. 字符串 → 数字（可处理多数字混合）
stringstream s2("456 789");
int a, b; s2 >> a >> b;              // a=456, b=789

// 3. 逐个字符 / 按自定义分隔符
// stringstream 默认按空白切，自定义分隔符需配合 getline(ss, tok, ',')
stringstream s3("a,b,c");
string tok;
while (getline(s3, tok, ',')) {      // 按逗号切
    // tok = "a" → "b" → "c"
}
```

## 注意事项

- `stringstream` 头文件 `<sstream>`（竞赛常用 `<bits/stdc++.h>` 已包含）
- `ss >> x` 会跳过前导空白，读到 EOF 或失败时返回 false，可用于 while 循环
- `ss.clear()` 与 `ss.str("")` 用于复用同一个流对象清空（每次构造新流更简单）
- 比 `getline` + 手写 split 更简洁，比 `strtok` 更安全（`strtok` 是 C 风格，会破坏原字符串、非线程安全）
- 性能：数据量极大时（如 1e6+ 行）stringstream 比手写扫描稍慢，但绝大多数场景够用
