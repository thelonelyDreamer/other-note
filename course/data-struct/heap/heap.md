### 1. 判断数组是否是堆
```c
/**
 * @return -2 长度错误
 * @return -1 空数组或者空指针
 * @return 0 不是堆
 * @return 1 是堆
 */
int isHeap(int arr[],int length,int (*compare)(int,int)){
	if(length<0){
		return -2;
	}
	if(0==length||NULL==arr){
		return -1;
	}
	int index=length/2-1;
    if(compare(arr[index],arr[2*index+1])<=0){
        return 0;
    }
    if(index*2+2<length){
        if(compare(arr[index],arr[2*index+2])<=0){
        return 0;
    }
    }
    for(index=index-1;index>=0;index--){
        if(compare(arr[index],arr[2*index+1])<=0)return 0;
        if(compare(arr[index],arr[2*index+2])<=0)return 0;
    }
    return 1;
} 
```