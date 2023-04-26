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

