### 0. 函数简介

#### 0.1 函数定义

```
[function] funname [()]
{
    action;
    [return int;]
}
# 注释： 一般function可以省略
# rturn 用来返回参数，如果不加，将会返回最后一条语句的结果
```



### 1. 无参数无返回值的函数

```sh
function sayHello(){
	echo "Hello"
}
echo "函数开始执行"
sayHello
echo $?
echo "函数执行完毕"
# result
# 函数开始执行
# Hello
# 0
# 函数执行完毕
```

### 2. 无参数有返回值的函数

```sh
funWithReturn(){
    echo "这个函数会对输入的两个数字进行相加运算..."
    echo "输入第一个数字: "
    read aNum
    echo "输入第二个数字: "
    read anotherNum
    echo "两个数字分别为 $aNum 和 $anotherNum !"
    return $(($aNum+$anotherNum))
}
funWithReturn
echo "输入的两个数字之和为 $? !"

# 这个函数会对输入的两个数字进行相加运算...
# 输入第一个数字: 
# 1
# 输入第二个数字: 
# 2
# 两个数字分别为 1 和 2 !
# 输入的两个数字之和为 3 !
```

### 3. 接收函数参数

```sh
funWithParam(){
    echo "第一个参数为 $1 !"
    echo "第二个参数为 $2 !"
    echo "第十个参数为 $10 !"
    echo "第十个参数为 ${10} !"
    echo "第十一个参数为 ${11} !"
    echo "参数总数有 $# 个!"
    echo "作为一个字符串输出所有参数 $* !"
    echo "作为多个字符串输出所有参数 "$@" !"
}
funWithParam 1 2 3 4 5 6 7 8 9 34 73

# result
# 第一个参数为 1 !
# 第二个参数为 2 !
# 第十个参数为 10 !
# 第十个参数为 34 !
# 第十一个参数为 73 !
# 参数总数有 11 个!
# 作为一个字符串输出所有参数 1 2 3 4 5 6 7 8 9 34 73 !
# 作为多个字符串输出所有参数 1 2 3 4 5 6 7 8 9 34 73 !

```

