### 1. 键值对
```json
{
    "name": "shine",
    "age": 18
}
```
```toml
name=shine
age=18
```

### 2. 对象
```json
{
    "owner":{
        "name": "Tom Preston-Werner",
        "organization": "GitHub",
        "bio": "GitHub Cofounder & CEO\nLikes tater tots and beer.",
        "dob": "1979-05-27T07:32:00Z" 
    },
    "database":{
        "server": "192.168.1.1",
        "ports": [ 8001, 8001, 8002 ],
        "connection_max":5000,
        "enabled":true
    }
}
```
```toml
[owner]
name = "Tom Preston-Werner"
organization = "GitHub"
bio = "GitHub Cofounder & CEO\nLikes tater tots and beer."
dob = 1979-05-27T07:32:00Z # 日期时间是一等公民。为什么不呢？
 
[database]
server = "192.168.1.1"
ports = [ 8001, 8001, 8002 ]
connection_max = 5000
enabled = true
```

### 3. 对象数组
```json
{
  "products": [
    { "name": "Hammer", "sku": 738594937 },
    { },
    { "name": "Nail", "sku": 284758393, "color": "gray" }
  ]
}
```
```toml
[[products]]
name = "Hammer"
sku = 738594937
 
[[products]]
 
[[products]]
name = "Nail"
sku = 284758393
color = "gray"
```

### 4. 注释
```
# 注释
name='shine' #注释
```