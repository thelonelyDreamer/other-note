### 1. 变量相关操作 

```sh
# 定义变量
username=shine
# 读取变量
echo ${username}
# 只读变量
myurl="http://www.baidu.com"
readonly myurl
# 更改就会报错
# 删除变量，不能删除只读变量
unset username
# echo $username 这句话讲不会有任何输出
```

### 2. 变量命名规则

```sh
# 变量的命名规则
# 命名只能使用字母、数字和下划线，并且收个字符不能以数字开头
# 中间不能有空格，可以使用下滑线
# 不能使用标点符号
# 不能使用shell里面的冠军字
```

