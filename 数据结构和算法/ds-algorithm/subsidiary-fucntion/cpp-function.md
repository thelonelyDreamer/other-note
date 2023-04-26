### 1. 数组

#### 1.1 交换数组里面的两个值

```c++
/*
    交换数组的两个元素
*/
template<typeclass T>
void swap(T[] arr ,int i,int j){
    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
/*
备注：考虑到大多数情况下，是需要交换的，这里不用先比较i==j.
如果数组越界，就会抛出异常
*/
```

