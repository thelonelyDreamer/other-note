### 1. 配置文件

```yml
# docker-compose.yml
version: '3.1'
services:
  master:
    image: registry.cn-hangzhou.aliyuncs.com/helowin/oracle_11g
    container_name: oracle
    privileged: true
    ports:
      - 1521:1521
```

### 2. 启动

```sh
docker-compose up -d
docker exec -it oracle bash
```



# 3. 初始配置

```
cd /home/oracle                                           # 进入到 oracle 用户目录
source .bash_profile                                      # 加载 oracle 环境变量
$PATH                                                     # 查看 oracle 环境变量是否生效
sqlplus / as sysdba                                       # 连接 oracle 数据库
alter user system identified by oracle;                   # 修改 DBA 账号的密码
alter user sys identified by oracle;                      # 修改 DBA 账号的密码
alter profile default limit password_life_time unlimited; # 设置密码为永不过期
create user test identified by oracle;                    # 创建一个 test 用户，密码 oracle
select * from dba_users t where t.username = 'TEST';      # 查询用户是否创建成功
grant connect, resource to test;                          # 给用户授予连接和数据权限
```

