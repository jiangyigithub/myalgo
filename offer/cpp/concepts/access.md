## 只读权限
`const` 只读、写权限

读写权限，一个类中的成员变量能否通过成员函数来改写。
定义set成员函数为非const，定义get成员函数为const，若定义一个const的常量对象，则只能调用get成员函数，保证成员变量不会被改写。

## 复制权限
delete  copy ctor      

## 移动权限

## 可访问权限
1. 类自己内部
2. 父类与子类
3. 友元
4. 类与类之间
成员变量和成员函数的权限（类与类之间）
`private` `public` `friend` `protected`(oriented object)