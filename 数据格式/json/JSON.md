# 一、JSON

## 1. 简介

- JavaScript Obeject Notation, JS 对象表示法
- 是一种轻量级的数据交换格式
- 类似于XML,更小、更快、更易解析
- 最早用于JavaScript中，容易解析，最后推广到全语言
- 尽管使用JavaScript语法，但是独立于编程语言

​			

## 2. 实例

JSON对象的解析与生成：https://www.sojson.com/

(1) JSON对象

```JSON
{"name":"shine","age":"24"}
```

(2)JSON数组

```json
[{"name":"shine","age":"24"},{"name":"zhangsan","age":"20"}]
```

## 3. java处理JSON

- org.json:JSON官方推荐的解析类
  - 简单易用，通用性强
  - 复杂功能欠缺
- GSON: Google出品
  - 基于反射，可以实现JSON对象、JSON字符串和Java对象的互转
- Jackson: 号称最快的JSON处理器
  - 简单易用，社区更新和发布速度比较快

## 4. JSON主要用途

• JSON生成

 • JSON解析 • JSON校验

 • 和Java Bean对象进行互解析

 	–具有一个无参的构造函数

​	 –可以包括多个属性，所有属性都是private 

​	–每个属性都有相应的Getter/Setter方法 

​	–Java Bean用于封装数据，又可称为POJO(Plain Old Java Object)