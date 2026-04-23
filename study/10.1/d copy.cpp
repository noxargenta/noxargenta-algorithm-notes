#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k; // 最小修改 1：添加对 N 和 K 的读取
    
    char name[100][11];
    char temp[11];
    char dummy[11]; // 用于丢弃 N-K 个昵称

    // 最小修改 2：只读取前 K 个昵称
    for (int i = 0; i < k; i++){
        cin >> name[i];
    }
    
    // 最小修改 3：丢弃（读取但不存储）剩下的 N-K 个昵称
    for (int i = k; i < n; i++){
        cin >> dummy;
    }
    
    // 最小修改 4：排序循环的范围改为 K，且增加交换逻辑
    for (int i = 0; i < k; i++){
        int min_i = i;
        // 只在 [i, K-1] 范围内寻找最小元素
        for (int j = i + 1; j < k; j++) { 
            if (strcmp(name[j], name[min_i]) < 0){
                min_i = j;
            }
        }
        
        // 增加：交换逻辑
        if (min_i != i) {
            strcpy(temp, name[i]);
            strcpy(name[i], name[min_i]);
            strcpy(name[min_i], temp);
        }
    }
    
    // 最小修改 5：打印前 K 个昵称
    for (int i = 0; i < k; i++) {
        cout << name[i] << "\n";
    }
    
    return 0; // 增加程序结束标志
}