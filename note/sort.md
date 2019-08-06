# definition
```cpp
template <class RandomAccessIterator>
  void sort (RandomAccessIterator first, RandomAccessIterator last);
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```
# base type
## asc
```cpp
int a[] = {1,9,5,2,7,3};
int n = sizeof(a)/sizeof(a[0]);

std::vector<int> v = {1,9,5,2,7,3};

std::sort(a,a + n); // <=> std::sort(a,a+n,std::less<int>());
std::sort(v.begin(),v.end());
```
## desc
```cpp
int a[] = {1,9,5,2,7,3};
int n = sizeof(a)/sizeof(a[0]);

std::vector<int> v = {1,9,5,2,7,3};

std::sort(a, a+n, std::greater<int>());
std::sort(v.begin(), v.end(), std::greater<int>());
std::sort(v.rbegin(),v.rend());//using reverse_iterator
```
# customize type
## with compare operation
### asc
```cpp
class CustomizeWithCompare
{
private:
	int _val;
public:
	CustomizeWithCompare(int val):_val(val){}
	bool operator<(const CustomizeWithCompare &b)const{
		return _val < b._val;
	} 
};

std::vector<CustomizeWithCompare> v_cwc = {1, 9, 5, 2, 7, 3};

std::sort(v_cwc.begin(), v_cwc.end());

```
### desc
```cpp
class CustomizeWithCompare
{
private:
	int _val;
public:
	CustomizeWithCompare(int val):_val(val){}
	bool operator>(const CustomizeWithCompare &b)const{
		return _val > b._val;
	} 
};

std::vector<CustomizeWithCompare> v_cwc = {1, 9, 5, 2, 7, 3};

std::sort(v_cwc.begin(), v_cwc.end(), std::greater<CustomizeWithCompare>());
```
## without compare operation
### method 1 - function
```cpp
struct Customize
{
	int _val;
};

std::vector<Customize> v = { {1}, {9}, {5}, {2}, {7}, {3} };
bool cmp(const Customize &a, const Customize &b)//asc
{
	return a._val < b._val;
}

std::sort(v.begin(), v.end(),cmp);
```
### method 2 - functional class
```cpp
struct Customize
{
    int _val;
};

std::vector<Customize> v = { {1}, {9}, {5}, {2}, {7}, {3} };
class cmp{
public:
    bool operator()(const Customize &a, const Customize &b)//asc
    {
        return a._val < b._val;
    }
};

std::sort(v.begin(), v.end(),cmp());
```
### method 3 - lambda
```cpp
struct Customize
{
	int _val;
};

std::vector<Customize> v = { {1}, {9}, {5}, {2}, {7}, {3} };

std::sort(
	v.begin(),
	v.end(),
	[](const Customize&a,const Customize &b)->bool{
		return a._val < b._val;
	}
);
```