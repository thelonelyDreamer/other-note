I. 数组

### 1. 数组相关操作

```sh
# 定义数组
# 数组名=(值1 值2 值3··· 值n)
array1=(value0 value1 value2)
array2=(
value0
value1
value2
)
array[0]=value0
array[1]=value1
array[2]=value2
echo $array1
echo $array2
echo $array # value0

# 数组长度
echo ${#array[@]} # 3
echo ${#array[*]} # 3

# 获取单个数组元素
echo ${array[1]} # value1
# 获取全部数组元素
echo ${array[@]} # value0 value1 value2
# 获取单个数组元素的长度
echo ${#array[1]} # 6
```

