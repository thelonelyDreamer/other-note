### 1. next数组的计算
```c
void generate(char* arr,int* next,int n){
    int i=0;
    int j=-1;
    next[0]=-1;
    while (i<n)
    {
        if(-1==j||arr[i]==arr[j]){
            i++;
            j++;
            if(arr[i]!=arr[j]){
                next[i]=j;
            }else{
                next[i]=next[j];
            }
        }else{
            j=next[j];
        }
    }   
}
```