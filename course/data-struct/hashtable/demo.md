### 1. question
**description**
>   Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from[1,10^4]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.
> 
**输入格式**
>   Each input file contains one test case. Each case contains a line which begins with a positive integer N(<=10^5) and then followed by N bets. The numbers are separated by a space.
>
**输出格式**
>   For each test case, print the winning number in a line. If there is no winner, print "None" instead.
>
**输入样例1**
```
7 5 31 5 88 67 88 17
```
**输出样例1**
```
31
```
**输入样例2**
```
5 888 666 666 888 888
```
***输出样例2*
```
None
```
### 2. analysis


### 3. solution
```c
#include<stdio.h>

int data[100001]; // 输入的原始数据
int hash[10001]={0}; //哈希表
int main(){
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&data[i]);
        hash[data[i]]+=1;
    }
    int ans =-1;
    for(int i=1;i<n;i++){
        if(1==hash[data[i]]{
            ans=data[i];
        })
    }
    if(-1==ans){
        printf("None\n");
    }else{
        print("%d",ans);
    }

    return 0;
}

```