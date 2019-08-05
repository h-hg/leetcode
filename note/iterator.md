# `iterator` and `reverse_iterator`
take `std::string::iterator` and `std::string::reverse_iterator` as example, more information, please see [了解如何通过reverse_iterator的base得到iterator](https://www.cnblogs.com/lihaozy/archive/2012/12/15/2819702.html)

remember : iterator + 1 = iterator_reverse
## iterator_reverse -> iterator
```cpp
std::string s = "123";
auto riter = s.rbegin();
auto iter = riter.base() - 1;
std::cout << (*riter) << " " << (*iter) << std::endl;
```
## iterator -> iterator_reverse
```cpp
std::string s = "123";
auto iter = s.begin();
std::string::reverse_iterator riter(iter+1);

```

# ramdon iterator: `index` and `iterator`
1. index -> iterator
```cpp
std::vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
int index = 2;
auto iter = a.begin() + index;
```
2. iterator -> index
```cpp
std::vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
auto iter = a.begin() + 2;
int index = iter - a.begin();
```

# iterator point to the same address
```cpp
&*iter1 == &*iter2
```