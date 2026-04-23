import sys
from bisect import bisect_left

# 设置递归深度，虽然本题是递推，但这是写 Python 算法题的好习惯
sys.setrecursionlimit(2000)

MOD = 998244353

def main():
    # 快速读入所有数据（一次性读取并按空格/换行切分，比 input() 快很多）
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    
    segments = []
    raw_ls = []
    
    # 游标，用于遍历 input_data
    idx = 1 
    
    # ==========================================
    # 第一战区：读入数据与离散化 (坐标压缩)
    # ==========================================
    for _ in range(n):
        l = int(input_data[idx])
        r = int(input_data[idx+1])
        segments.append((l, r))
        raw_ls.append(l)
        raw_ls.append(r)
        idx += 2
        
    # 去重并排序 (Python 一行搞定 C++ 的 sort + unique)
    ls = sorted(list(set(raw_ls)))
    sz = len(ls)
    
    # 为了防止下标越界，我们把数组开得稍微大一点点
    # dp[层数][左端点][右端点]：记录某个区间内，刚好凑出某层数的方案数
    # pre[层数][左端点][右端点]：记录某个区间内，凑出的层数 <= 某层数的总方案数
    dp = [[[0 for _ in range(sz + 3)] for _ in range(sz + 3)] for _ in range(n + 2)]
    pre = [[[0 for _ in range(sz + 3)] for _ in range(sz + 3)] for _ in range(n + 2)]
    
    # e[l] 登记册，记录“所有从左端点 l 开始的线段，它们的右端点在哪里”
    e = [[] for _ in range(sz + 3)]
    
    for l_val, r_val in segments:
        # bisect_left 等价于 C++ 的 lower_bound，查找元素在列表里的索引
        # 因为我们的 dp 数组习惯从下标 1 开始，所以后面 + 1
        l_idx = bisect_left(ls, l_val) + 1
        r_idx = bisect_left(ls, r_val) + 1
        e[l_idx].append(r_idx)
        
    # ==========================================
    # 第二战区：打底子 (初始化 0 层状态)
    # ==========================================
    for i in range(sz + 2):
        for j in range(sz + 2):
            # “什么都不画”也是一种合法画法，最高层数为 0
            dp[0][i][j] = 1
            
    for k in range(n + 1):
        for l in range(sz + 2):
            for r in range(sz + 2):
                # 既然 0 层方案数是 1，那么初始状态下“<= k层”的方案数底薪就是 1
                pre[k][l][r] = 1

    # ==========================================
    # 第三战区 & 第四战区：区间 DP 核心推导
    # ==========================================
    for k in range(1, n + 1):                            # 枚举目标层数 k
        for length in range(1, sz + 1):                  # 枚举当前观察的直尺长度 length
            for l in range(1, sz - length + 2):          # 枚举直尺的左端点 l
                r = l + length - 1                       # 算出直尺的右端点 r
                
                # 基础选择：不在起点 l 画任何最外层线段
                dp[k][l][r] = (dp[k][l][r] + dp[k][l + 1][r]) % MOD
                
                # 复杂选择：选择画一条从 l 开始的线段
                # 遍历登记册里所有以 l 为起点的线段，p 是它的右端点
                for p in e[l]:
                    if p > r:
                        continue # 线段超出了当前观察的区间，不考虑
                        
                    if p == r:
                        # 特殊情况：线段完美覆盖了整个 [l, r] 区间
                        if k == 1:
                            # 只要凑1层，这条线段本身就是1层，内部什么都不准画(即1种空集画法)
                            dp[k][l][r] = (dp[k][l][r] + 1) % MOD
                        else:
                            # 要凑k层，外面这条线段占了1层，内部必须刚好凑齐 k-1 层
                            dp[k][l][r] = (dp[k][l][r] + dp[k - 1][l + 1][r - 1]) % MOD
                    else:
                        # 普遍情况：大线段是 [l, p]，它把世界分成了：
                        # 内部区域：[l+1, p-1]  外部区域：[p+1, r]
                        
                        # 套路 A：内部刚好凑 k-1 层 (用dp) × 外部随便只要不超 k 层 (用pre)
                        wayA = dp[k - 1][l + 1][p - 1] * pre[k][p + 1][r] % MOD
                        
                        # 套路 B：内部随便只要不超 k-1 层 (用pre) × 外部刚好凑 k 层 (用dp)
                        wayB = pre[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD
                        
                        # 去重：减去 (内部刚好 k-1 层 且 外部刚好 k 层) 的重复计算次数
                        overlap = dp[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD
                        
                        # 合并。注意：Python 的 % 运算符天生能处理负数（-1 % 3 = 2）
                        # 所以不需要像 C++ 那样写成 (x % MOD + MOD) % MOD
                        dp[k][l][r] = (dp[k][l][r] + wayA + wayB - overlap) % MOD
                
                # 当前区间 [l, r] 刚好 k 层的方案数算完后，更新辅助登记表 pre (<=k层)
                pre[k][l][r] = (pre[k - 1][l][r] + dp[k][l][r]) % MOD

    # ==========================================
    # 第五战区：结账算总得分
    # ==========================================
    ans = 0
    for k in range(1, n + 1):
        # dp[k][1][sz] 代表在整把尺子 [1, sz] 上，最高套娃刚好为 k 层的方案数
        # 产生总得分为：层数 k * 对应的方案数
        ans = (ans + k * dp[k][1][sz]) % MOD
        
    print(ans)

if __name__ == '__main__':
    main()