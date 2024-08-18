# pointer
```c++
  int a = 0;
  int* ap=&a;
  int** app=&ap;
  auto ap11=std::addressof(a);
  auto app11=std::addressof(ap);
  cout<<"ap apple addr: "<<ap<<endl;
  cout<<"ap11 banana addr: "<<ap11<<endl;
  cout<<"app the apple of apple addr: "<<app<<endl;
  cout<<"app11 the banana of banana addr: "<<app11<<endl;
```

```c++
  int *p = (int*)0x1234;
  cout<<"assign int addr: "<<p<<endl;
```

