// Acwing

// 设有N堆石子排成一排，其编号为1，2，3，…，N。

// 每堆石子有一定的质量，可以用一个整数来描述，现在要将这N堆石子合并成为一堆。

// 每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。

// 例如有4堆石子分别为 1 3 5 2， 我们可以先合并1、2堆，代价为4，得到4 5 2， 又合并 1，2堆，代价为9，得到9 2 ，再合并得到11，总代价为4+9+11=24；

// 如果第二步是先合并2，3堆，则代价为7，得到4 7，最后一次合并代价为11，总代价为4+7+11=22。

// 问题是：找出一种合理的方法，使总的代价最小，输出最小代价。

// 输入格式
// 第一行一个数N表示石子的堆数N。

// 第二行N个数，表示每堆石子的质量(均不超过1000)。

// 输出格式
// 输出一个整数，表示最小代价。

// 数据范围
// 1≤N≤300
// 输入样例：
// 4
// 1 3 5 2
// 输出样例：
// 22

#include<bits/stdc++.h>
using namespace std;
const int N=305,INF=0x3f3f3f3f;
int f[N][N],w[N],s[N];
int main(){
    int n;
    cin>>n;
    memset(f,INF,sizeof(f)); // boundary also the recursive base
    for(int i=1;i<=n;i++){ 
        cin>>w[i];
        s[i]=s[i-1]+w[i];
        f[i][i]=0;// recursive base
    }
    for(int len=2;len<=n;len++){ // interval-based traversal, Diagonal traversal
        for(int i=1;i<=n-len+1;i++){ // all i,j
            int j=i+len-1;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);// k+1>i
            }
        }
    }
    cout<<f[1][n]<<endl;
    
}

//debug:
/*
0 4 13 24 
1061109567 0 8 18 
1061109567 1061109567 0 7 
1061109567 1061109567 1061109567 0 

1:2:1:4  1:3:1:1061109576 1:3:2:13  1:4:1:1061109578 1:4:2:1061109582 1:4:3:24  
2:3:2:8  2:4:2:1061109577 2:4:3:18  
3:4:3:7
  

0 4 13 22 
1061109567 0 8 17 [2,4]
1061109567 1061109567 0 7 
1061109567 1061109567 1061109567 0 

1:2:1:4  2:3:2:8  3:4:3:7  
1:3:1:17 1:3:2:13  2:4:2:17 2:4:3:18  
1:4:1:28 1:4:2:22 1:4:3:24  
0 4 13 22



#include<bits/stdc++.h>
using namespace std;
const int N=305,INF=0x3f;
int f[N][N],w[N],s[N];
int main(){
    int n;
    cin>>n;
    memset(f,INF,sizeof(f)); // boundary also the recursive base
    for(int i=1;i<=n;i++){
        cin>>w[i];
        s[i]=s[i-1]+w[i];
        f[i][i]=0;// recursive base
    }
    // for(int len=2;len<=n;len++){
    //     for(int i=1;i<=n-len+1;i++){ // all i,j
    //         int j=i+len-1;
    //         for(int k=i;k<j;k++){
    //             cout<<i<<':'<<j<<':'<<k<<':'<<f[i][k]+f[k+1][j]+s[j]-s[i-1]<<' ';
    //             f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
    //         }
    //         cout<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){ // all i,j
            for(int k=i;k<j;k++){
                cout<<i<<':'<<j<<':'<<k<<':'<<f[i][k]+f[k+1][j]+s[j]-s[i-1]<<' ';
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
            cout<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<f[1][n]<<endl;
    
}
// 先枚举区间的原因是，可以确保迭代计算的时候，前面的表格中数据已经被填写过了
*/