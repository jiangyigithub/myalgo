非类型模板参数的作用相当于为函数模板或者类模板预定义了一些常量，在生成模板实例时，也要求必须以常量即编译器已知的值为非可选模板参数赋值。

相对于常量，非类型模板参数的灵活之处在于：

    模板中声明的常量，在模板的所有实例中都具有相同的值，
    非类型模板参数则对于在不同的模板实例中可以拥有不同的值来满足不同的需求。

template <
   vfc::uint8_t MaxNumVirtualLanes,
   vfc::uint8_t MaxNumVirtualLaneSegments,
   class InfoProviderType,
   class ObjectType>
class Behavior


https://r00tk1ts.github.io/2018/12/03/C++%20Primer%20-%20%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/

https://blog.csdn.net/zhizhengguan/article/details/115869685?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-3.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-3.pc_relevant_aa&utm_relevant_index=6