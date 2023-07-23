# 单例模式

## 一、 单线程中的单例模式

![5](https://s1.ax1x.com/2023/05/15/p9gNPpQ.png)

```java
public class OneThreadSingleton {
    private static OneThreadSingleton singleton;

    private OneThreadSingleton(){
        System.out.println("实例化一个OneThreadSingleton");
    }

    public static OneThreadSingleton getSingleton(){
        if(null==singleton){
            singleton=new OneThreadSingleton();
        }
        return singleton;
    }

    public void doSomething(){
        System.out.println("Something is done");
    }

}
```

> 1. 构造方法私有化
> 2. 提供静态获取实例的方法
> 3. 没有并发下安全

## 二、 同步锁单例模式

```java
public class MultiThreadSingleton {
    private static MultiThreadSingleton singleton;

    private MultiThreadSingleton() {
        System.out.println("实例化一个MultiThreadSingleton");
    }

    public static synchronized MultiThreadSingleton getSingleton() {
        if (null == singleton) {
            singleton = new MultiThreadSingleton();
        }
        return singleton;
    }

    // 或者
    /*
    public static MultiThreadSingleton getSingleton(){
        synchronized(MultiThreadSingleton.class){
        	if(null==singleton) singleton=new MultiThreadSingleton();
        } 
        return singleton;
    }
     */
    public void doSomething() {
        System.out.println("Something is done");
    }
    
}

```

> 缺点：
>
> - 性能差，同步锁只在创建时启用，然而获取时也要获取锁，导致性能差

## 三、 拥有双重校验锁机制的同步单例模式

```java
public static DoubleTestMultiThreadSingleton getSingleton() {
        if (null == singleton)
            synchronized (DoubleTestMultiThreadSingleton.class) {
                if (null == singleton)
                    singleton = new DoubleTestMultiThreadSingleton();
            }
        return singleton;
    }
```

> 这个比较好

## 四、 无锁的线程安全单例模式

```java
public class LockFreeSingleton {
    private static final LockFreeSingleton singleton = new LockFreeSingleton();
    private LockFreeSingleton(){
        System.out.println("实例化 LockFreeSingleton");
    };
    public static LockFreeSingleton getSingleton(){
        return singleton;
    }
    public void doSomething(){
        System.out.println("Something is done");
    }
}
```

## 五、 提前加载和延迟加载

> - 提前加载：在应用开始时创建，一般可以使用Singleton.getSingleton()实现提前加载
> - 延迟加载：调用getSingleton()加载