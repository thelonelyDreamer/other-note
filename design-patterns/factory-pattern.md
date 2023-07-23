# 工厂模式

**简述**

> 设Vehicle 的子类为Car,Vehicle,Truck
>
> 继承的好处：同一段代码能为不同的对象实现相同的操作，使代码更加简介，方便扩展。例如新增子类Car

```java
Vehicle vehicle = new Car();
```

> - 耦合度高
> - 所在类违背单一职责原则，既要实例化Vehicle对象，又要完成自身的职责
> - 所在类违背开闭原则

## 一、 简单工厂模式

![工厂模式](https://s1.ax1x.com/2023/05/15/p9gUVvd.png)

### 1. 静态工厂模式

**简单静态工厂**

```java
public class VehicleFactory {
    public static Vehicle createVehicle(VehicleType type){
        if(type.equals(VehicleType.BIKE))
            return new Bike();
        if(type.equals(VehicleType.CAR))
            return new Car();
        if(type.equals(VehicleType.TRUCK))
            return new Truck();
        return null;
    }
}
public enum VehicleType {
    BIKE,CAR,TRUCK;
}

```

> 符合单一职责原则（只是用来实例化Vehicle类）
>
> 符合依赖导致原则（用户只需要调用createVehicle()就可以得到接口对象）
>
> 但是不符合开闭原则（只要新增一个功能，就要改代码）

### 2. 使用反射机制实现的简单工厂模式

```java
public class ReflectVehicleFactory {
    private static Map<String,Class> registeredVehicle = new HashMap<String,Class>();
    public void setRegisteredVehicle(String vehicleId,Class vehicleClass){
        registeredVehicle.put(vehicleId,vehicleClass);
    }
    public static Vehicle createVehicle(String vehicleId) throws IllegalAccessException, InstantiationException {
        return (Vehicle) registeredVehicle.get(vehicleId).newInstance();
    }
}
```

> 满足开闭原则
>
> 反射机制会降低程序的运行机制，在对性能要求很高的场景下应该避免使用这种机制。
>
> 反射机制需要运行时权限，在一些特定的环境中无法使用

### 3. newInstance()方法进行类注册的简单工厂模式

```java
public class FruitFactory {
    private Map<String, Fruit> fruitMap = new HashMap<>();
    public void registerFruit(String name ,Fruit fruit){
        fruitMap.put(name,fruit);
    }

    public Fruit getFruit(String name){
        return fruitMap.get(name).newInstance();
    }
}
public abstract class Fruit {
    abstract public Fruit newInstance();
}

```

> 这种方式将会导致内存中垃圾对象较多，针对每一个产品，都要保留一个无用对象

## 二、 工厂方法模式

![抽象工厂方法模式](https://s1.ax1x.com/2023/05/15/p9gUSD1.png)



```java
public abstract class AbstractMethodFactory {
    protected abstract Vehicle createVehicle(String type);
    public Vehicle orderVehicle(String type,String color){
        Vehicle vehicle = createVehicle(type);
        //对对象进一步处理
        vehicle.toString();
        return  vehicle;
    }
}
```

> 具体工程可以根据业务需求来实现，甚至可以在代码中构建匿名工厂

## 三、抽象工厂模式

> 抽象工厂模式是工厂模式的扩展版本。它不是创建单一类型的对象，而是创建一系列相关联的对象

![i抽象工厂.png](https://s1.ax1x.com/2023/05/15/p9gNX34.png)


> 可以有不同的实现类，
>
> 生产不同系列的产品