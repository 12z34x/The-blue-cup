#include<iostream>
#include<cstring>
using namespace std;

int f[10000], b[10000];
int lis(int n) {
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {//��i֮ǰ��
            if (b[j] < b[i]) {
                 int max=0;
              for(int k=0;k<=j;k++)
              {
                  if(f[k]>max) max=f[k];
              }
              f[i]=max+1;//���j֮ǰ�����ֵ
            }
        }
        res = max(res, f[i]);//ȷ�����ճ���
    }
    return res+1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    printf("%d\n", lis(n));
    return 0;
}
