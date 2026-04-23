#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    char name[100][11];
    char temp[11];
    char diuqi[11];
    for (int i=0; i<k;i++){
        cin >> name[i];
    }
    for (int i=k; i<k;i++){
        cin >> diuqi;
    }
    for (int i=0;i<k;i++){
        int min_i=i;
        for (int j=i+1;j<k;j++) {
            if (strcmp(name[j], name[min_i])<0){
                min_i =j;
            }
        }
        if (min_i !=i){
            strcpy(temp,name[i]);
            strcpy(name[i],name[min_i]);
            strcpy(name[min_i],temp);
        }
    }
    for (int i=0;i<k;i++){
        cout <<name[i] << endl;
    }
    return 0;
}