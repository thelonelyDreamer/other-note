### 1. 分支结构

#### 1.1 if语句

```sh
# 不可以有空语句
if [ $(ps -ef | grep -c "ssh") -gt 1 ];then echo "true";fi
a=10
b=20
if [ $a == $b ]
then
   echo "a 等于 b"
elif [ $a -gt $b ]
then
   echo "a 大于 b"
elif [ $a -lt $b ]
then
   echo "a 小于 b"
else
   echo "没有符合的条件"
fi

```

#### 1.2 switch 语句

```sh
number="1"
case "$number" in
  "1") echo "one"
  ;;
  "2") echo "two"
  ;;
  *)
      eho "other"
  ;;
esac
```



### 2. 循环结构

#### 2.1 for 循环

```sh
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done

for str in 'This is a string' 'two'
do
    echo $str
done

# result
# The value is: 1
# The value is: 2
# The value is: 3
# The value is: 4
# The value is: 5
# This is a string
# two
```

#### 2.2 while循环

```sh
int=1
while(($int<=5))
do
  echo $int
  let "int ++"
done

# 1
# 2
# 3
# 4
# 5
```



### 3. 顺序结构