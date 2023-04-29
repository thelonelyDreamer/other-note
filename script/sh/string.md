### 1. 字符串定义

#### 1.1 单引号定义的的字符串

```sh
# 单引号的字符会原样输出，转义字符和变量是无效的
# 单引号里面不可以再出现单引号
name='shine'
string='this is a string.\n${name}'
echo $string # this is a string.\n${name}

#单引号拼接
echo 'hello,'$name'!' # hello,shine!
echo 'hello,'name'!' # hello,name!
```

#### 1.2 双引号定义的字符串

```sh
# 双引号可以出现转义字符和变量
name='shine'
str="Hello, I know you are \"$name\"! \n"
echo -e $str # Hello, I know you are "shine"!

#使用双引号拼接字符串
echo "hello,"name"!"  # hello,name!
echo "hello,${name}!" # hello,shine!
```

### 2. 字符串长度

```sh
string="HelloWorld"
echo ${#string}
sLen=`expr length string`
echo $sLen
```

### 3. 子串

```sh
${string:position}
从$string的位置$position抽取子串，如果$string是“*”或者“@”，则从位置参数抽取。
${string:position:length}，通过“$length”控制抽取子串的长度
```

```sh
string="0123456789"
echo ${string:2:4} # 2345
echo ${string:2} # 23456789
echo ${string:(-3)} # 789
echo ${string:(-3)(2)} #78
```

### 4. 字串删除

```
${string#substring}，从$string开头删掉最短匹配的子串$substring
${string##substring}，从$string开头删掉最长匹配的子串$substring
${string%substring}，从$string结尾删掉最短匹配的子串$substring
${string%%substring}，从$string结尾删掉最长匹配的子串$substring
```

```sh
string="abc|abc|abcd|abcd|abc"
substring="abc"
string="abc|abc|abcd|abcd|abc"
substring="abc"
echo ${string#$substring} # |abc|abcd|abcd|abc"
echo ${string%$substring} # abc|abc|abcd|abcd|
```

### 5. 字串串替换

```sh
string=abc123abc456
echo ${mystring//abc/ABC} # ABC123ABC456
echo $string # abc123abc456
```

