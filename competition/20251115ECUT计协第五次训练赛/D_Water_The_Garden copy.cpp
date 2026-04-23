#include<bits/stdc++.h>
using namespace std;
int n, k, m, x[550], maxx, lef;
int main()
{
	cin >> m;//样例组数
	while (m--)//另一种循环写法
	{
        cin >> n >> k >> x[1];
        maxx = x[1];//开头（这里其实是maxx = max(maxx, lef);但可以简化
        for (int i = 2;i <= k;i++)
        {
            cin >> x[i];
            maxx = max(maxx, (x[i] - x[i - 1]) / 2 + 1);//除开头结尾情况
        }
        maxx = max(maxx, n - x[k] + 1);//结尾
        cout << maxx << endl;
	}
	return 0;
}
