#include <bits/stdc++.h>//组长喜欢我的四层循环吗


using namespace std;


using i64 = long long;


void solve() {
    vector<vector<int>> gongge(9, vector<int>(9));
    for (int h = 0; h < 9; h++) {
        for (int l = 0; l < 9; l++) {
            cin >> gongge[h][l];
        }
    }
    for (int h = 0; h < 9; h++) {
        int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0;
        for (int l = 0; l < 9; l++) {
            switch (gongge[h][l]) {
                case 1: num1++; break;
                case 2: num2++; break;
                case 3: num3++; break;
                case 4: num4++; break;
                case 5: num5++; break;
                case 6: num6++; break;
                case 7: num7++; break;
                case 8: num8++; break;
                case 9: num9++; break;
            }
        }
        if (num1 != 1 || num2 != 1 || num3 != 1 || num4 != 1 || num5 != 1 || num6 != 1 || num7 != 1 || num8 != 1 || num9 != 1) {
            cout << "No" << endl;
            return;
        }
    }
    for (int l = 0; l < 9; l++) {
        int num1=0, num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0;
        for (int h = 0; h < 9; h++) {
            switch (gongge[h][l]) {
                case 1: num1++; break;
                case 2: num2++; break;
                case 3: num3++; break;
                case 4: num4++; break;
                case 5: num5++; break;
                case 6: num6++; break;
                case 7: num7++; break;
                case 8: num8++; break;
                case 9: num9++; break;
            }
        }
        if (num1 != 1 || num2 != 1 || num3 != 1 || num4 != 1 || num5 != 1 || num6 != 1 || num7 != 1 || num8 != 1 || num9 != 1) {
            cout << "No" << endl;
            return;
        }
    }
    for (int xiaogonggeqsh =0; xiaogonggeqsh <9; xiaogonggeqsh+= 3) {
        for (int xiaogonggeqsl =0; xiaogonggeqsl <9; xiaogonggeqsl +=3) {
            int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0, num7=0,num8=0,num9=0;
            for (int h = xiaogonggeqsh; h < xiaogonggeqsh +3; h++) {
                for (int l = xiaogonggeqsl;l < xiaogonggeqsl+3;l++) {
                    switch (gongge[h][l]) {
                        case 1: num1++; break;
                        case 2: num2++; break;
                        case 3: num3++; break;
                        case 4: num4++; break;
                        case 5: num5++; break;
                        case 6: num6++; break;
                        case 7: num7++; break;
                        case 8: num8++; break;
                        case 9: num9++; break;
                    }
                }
            }
            if (num1 != 1 || num2 != 1 || num3 != 1 || num4 != 1 || num5 != 1 || num6 != 1 || num7 != 1 || num8 != 1 || num9 != 1) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}