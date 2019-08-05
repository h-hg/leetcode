# `std::upper_bound` and `std::lower_bound`
## define
```cpp
template <class ForwardIterator, class T>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                               const T& val);

template <class ForwardIterator, class T, class Compare>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);
```
`lower_bound` is similar to it.

## introduce
upper_bound: find the first position whose value is greater than val
lower_bound: find the first position whose value is greater or equal to val
```cpp
int main() {
	int a[] = {0,1,3,3,4,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	auto up = upper_bound(a,a+n,3) - a;
	auto low = lower_bound(a,a+n,3) - a;
	cout << "3:\n";
	cout << "up[" << up <<"] = " << a[up] << endl; 
	cout << "low[" << low <<"] = " << a[low] << endl; 
	cout << "\n2:\n";
	up = upper_bound(a,a+n,2) - a;
	low = lower_bound(a,a+n,2) - a;
	cout << "up[" << up <<"] = " << a[up] << endl; 
	cout << "low[" << low <<"] = " << a[low] << endl; 
		
	return 0;
}
```
```
3:
up[4] = 4
low[2] = 3

2:
up[2] = 3
low[2] = 3
```