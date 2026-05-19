# 并查集 (DSU)

## 路径压缩（一行版）

```cpp
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
```

## 基础模板

```cpp
vector<int> f(N);
iota(f.begin(), f.end(), 0);   // 初始化 f[i] = i

void merge(int x, int y) {
    f[find(x)] = find(y);
}

bool same(int x, int y) {
    return find(x) == find(y);
}
```

## 扩展域并查集—敌人的敌人是朋友

从 [K_团伙](../competition/20251207ECUT9/K_团伙.cpp) 提炼：

```cpp
// 1~n 是自己的域，n+1~2n 是敌人的域
for (int i = 1; i <= 2 * n; i++) f[i] = i;

if (c == 'E') {            // 敌人关系
    merge(x + n, y);       // x 的敌人和 y 同类
    merge(y + n, x);       // y 的敌人和 x 同类
} else {                   // 朋友关系
    merge(x, y);
}
```

## 常见应用

| 场景 | 做法 |
|------|------|
| 判环（图中有没有多余边） | 合并前 find 相同 → 多余边 |
| 连通块数量 | 统计 `f[i] == i` 的个数 |
| 带权 DSU（到根距离） | `dis[x] += dis[f[x]]` 路径压缩时维护 |
| 可撤销 DSU | 按秩合并 + 栈记录操作 |
