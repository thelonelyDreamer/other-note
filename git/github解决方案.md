### 1. 保证git操作会成功

#### 1.1 gs.sh

```shell
# 最大次数
max=10
git_success(){
	array=${@:1:$(($#-1))}
	times=${@:$#}
	echo $times begin
    if [ $times -gt $max ];then
		echo -e "\033[31mfatal:failed\033[0m"
        return
    fi
	echo $array
    eval $array
    if [ $? -ne 0 ];then 
        git_success $array $[$times+1]
    fi
}

git_success $* 1
```

```shell
./gs.sh git push
```

### 2.  git_clone

#### 2.1 git_clone.sh

```sh
git_clone(){
    echo $1
    if [ $2 -eq 15 ];then
        return
    fi
    git clone $1
    if [ $? -ne 0 ];then 
        git_clone $1 $[$2+1]
    fi
}

git_clone $1 0
```

### 3. push_all

```sh
# 保证提交成功
git_push(){
    echo -e "\033[31m `pwd` push $1 times  \033[0m"
    git push
    if [ $? -eq 0 ]; then
        echo -e "succeed\n"
        return 1
    else
        if [ $1 -lt 15 ]; then
            git_push $[$1+1]
            return
        else
            echo `pwd` >> ~/auto-git-err.log
            echo -e '\r\n' >> ~/auto-git-err.log
            return 100;
        fi
    fi  
}

# 自动提交,提交成功返回1 ，不成功返回100
auto_commit(){
    git add .
    git commit -m auto
    git_push 1
}

# 定义一个根目录数组
root_arr=("gitee" "github")

# 进入一个目录，如果是仓库目录，则提交，如果不是，则遍历子目录，遍历完成退出
push_dir(){
    cd $1
    if [ -d .git ]; then
        auto_commit
    else
        for file in `ls .`
        do 
            if [ -d $file ]; then
                push_dir $file
            fi
        done
    fi 
    cd ..
}

if [ -f ~/auto-git-err.log ]; then
    cat ~/auto-git-err.log
    exit -1
fi 


for root_dir in ${root_arr[@]}
do
    push_dir $root_dir
    
    echo `date` > update-time.txt
done
```

### 4. git_push

```sh
git add .
git commit -m auto

git_push(){
    git push
    if [ $? -eq 0 ]; then
        echo "succeed"
    else
        git_push
    fi  
}
git_push

```

