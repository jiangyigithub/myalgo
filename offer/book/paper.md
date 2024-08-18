1 Introduction
Not all programming languages can be ‘‘object oriented’’. Yet claims have been made to the effect that
APL, Ada, Clu, C++, LOOPS, and Smalltalk are object-oriented programming languages. I have heard dis-
cussions of object-oriented design in C, Pascal, Modula-2, and CHILL. Could there somewhere be propo-
nents of object-oriented Fortran and Cobol programming? I think there must be. ‘‘Object-oriented’’ has in
many circles become a high-tech synonym for ‘‘good’’, and when you examine discussions in the trade
press, you can find arguments that appear to boil down to syllogisms like:
不是所以的程序都支持面向对象，
Object-oriented programming is a technique for programming – a paradigm for writing ‘‘good’’ pro-
grams for a set of problems. If the term ‘‘object-oriented programming language’’ means anything it must
mean a programming language that provides mechanisms that support the object-oriented style of program-
ming well.

面向对象编程是一中可以解决各种问题的编程泛式。
面向对象编程意思是这个编程语言提供各种机制去支持这种编译泛式。
There is an important distinction here. A language is said to support a style of programming if it pro-
vides facilities that makes it convenient (reasonably easy, safe, and efficient) to use that style. A language
does not support a technique if it takes exceptional effort or exceptional skill to write such programs; it
merely enables the technique to be used. For example, you can write structured programs in Fortran, write
type-secure programs in C, and use data abstraction in Modula-2, but it is unnecessarily hard to do because
these languages do not support those techniques.
这里有一个重大的区别。如果一个语言会提供方便的方法去使用这种泛式，这个语言就支持这种编程泛式，而不是仅仅让这个技术可用。如果需要很复杂的能力和精力才能实现这种范式，则这个语言不支持某种泛式。
举个例子，你可以通过Fortran写结构化的程序，可以通过C写类型安全的程序，通过Modula-2写数据抽象的程序，但由于这些语言本身不支持这些技术，带到会带来不必要的困难。


Support for a paradigm comes not only in the obvious form of language facilities that allow direct use
of the paradigm, but also in the more subtle form of compile-time and/or run-time checks against uninten-
tional deviation from the paradigm. Type checking is the most obvious example of this; ambiguity detec-
tion and run-time checks can be used to extend linguistic support for paradigms. Extra-linguistic facilities
such as standard libraries and programming environments can also provide significant support for para-
digms.

支持某种编译范式，不仅仅是为这种范式提供很明显的语法支持，还在编译期和运行器确保不会偏离这种编程范式。类型检查则是说明这个的明显例子。
模糊检查和运行期检测可以被用于拓展对编程范式的语法支持，而像标准库和编程环境这些非语法的设施也可以为编程范式提供重要的支持。

A language is not necessarily better than another because it possesses a feature the other does not.
There are many example to the contrary. The important issue is not so much what features a language pos-
sesses but that the features it does possess are sufficient to support the desired programming styles in the
desired application areas:
不会因为一个语言拥有一个特性而另一个没有，这个语言就一定比另一个好。
重要的不是一个语言拥有某个feature，而是这个语言拥有的feature足以支持所期望的应用场景中所需要的编程范式。
