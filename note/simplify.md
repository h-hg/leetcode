# vector's output
```cpp
std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```
## index
```cpp
for(int i = 0;i < v.size();++i)
	std::cout << v[i] << ' ';
```
## iterator
```cpp
for(auto iter = v.begin();iter != v.end();++iter)
	std::cout << (*iter) << ' ';
```
## for_each
```cpp
for(auto val:v)
	std::cout << v << ' ';
```
## std::copy
```cpp
	std::copy(
		v.begin(),
		v.end(), 
		std::ostream_iterator<int>(std::cout, ", ")//ostream_iterator (ostream_type& s, const char_type* delimiter);
	);
```