# cast
## std::vector
Take `std::array` as example, `std::ddeque`, `std::list`, `std::forward_list` and `set`(including `std::set`, `std::multiset`, `std::unorder_set` and `std::unorder_multiset`) is similar to it.
```cpp
std::array<int,6> a = {0,1,2,3,4,5};

//construct
std::vector<int> v(a.begin(),a.end());

//append
v.insert(v.end(), a.begin(),a.end());
v.insert(std::end(v), a.begin(),a.end());
std::copy(a.begin(), a.end(), std::back_inserter(v));
```
As for `map`(including `std::map`, `std::multimap`, `std::unorder_map` and `std::unorder_multimap`), remember the element in it is `std::pair<key,value>`
```cpp
std::map<int,int> a = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };

//construct
std::vector<std::pair<int,int>> v(a.begin(),a.end());

//append
v.insert(v.end(), a.begin(),a.end());
v.insert(std::end(v), a.begin(),a.end());
std::copy(a.begin(), a.end(), std::back_inserter(v));
```
As for `std::stack` and `queue`(including `std::queue` and `std::priority_queue`), need to process one by one.