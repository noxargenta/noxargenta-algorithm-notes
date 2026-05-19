#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码

  int n;
  cin >> n;
  int sum=0;
  int maxx=0;
  int minn=100;
  for(int i=1;i<=n;i++){
      int x;
      cin >> x;
      sum+=x;
      maxx=max(maxx,x);
      minn=min(x,minn);
  }
  double y=sum*1.0/n;
  cout << maxx << endl << minn << endl;
  cout << fixed << setprecision(2) << y << endl; 
  return 0;
}