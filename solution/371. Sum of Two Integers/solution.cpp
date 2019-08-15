class Solution {
public:
    int getSum(int a, int b) {
    	if(b == 0)//没有进位，直接返回a
    		return a;
    	//a^b: 取得没有进位的值
    	//a&b：取得进位的值，因为是进位，所以进行左移一位
    	return getSum(a^b,(unsigned int)(a&b)<<1);//avoid overflow
    }
};

class Solution {
public:
    int getSum(int a, int b) {
    	int tmp;
    	while(b) {
    		tmp = a ^ b;
    		b = (unsigned int)(a&b)<<1;
    		a = tmp;
    	}
    	return a;
    }
};
