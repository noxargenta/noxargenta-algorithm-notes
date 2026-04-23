#include <iostream>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    char default1[101];
    for (int i=0;i<n;i++){
        cin >> default1[i];
    }
    default1[n] = '\0';
    int i2=0;
    int temp=0;
    int i=0;
    for (i = 0; i < k;) {
        if (default1[i2] == 'o'){
            i++;
            i2++;
        } else {
            i2++;
        }
        temp=i2;
    }

    for (int i = temp ; i <n;){
        if (default1[i] == 'o'){
            default1[i] = 'x';
            i++;
        }
        else {
            default1[i] = 'x';
            i++;
        }
    }
    
    cout << default1;
    return 0;
}