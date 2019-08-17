#include <string>
#include <vector>、
//method 1 : using id of digit(in Engilsh)
/*
number - Englighs word : id(Gaussian Elimination)
	0 - zero : z
	1 - one  : o(except o in zero and four)
	2 - two  : w
	3 - three: r(except r in four)
	4 - four : u
	5 - five : f(except f in four)
	6 - six  : x
	7 - seven: s(except s in six)
	8 - eight: g
	9 - nine : i(except n in six and eight)
identifying order:
	0, 2, 4, 6, 8, 1, 3, 5, 7, 9
*/
class Solution {
public:
    string originalDigits(std::string &s) {
        std::vector<int> val2cnt(128,0);
        for(auto c:s)
        	++val2cnt[c];
        std::vector<int> digitCnt(10,0);//digit val2cnt
        //val2cnt digist
        int cnt;
        //0
        cnt = digitCnt[0] = val2cnt['z'];
        val2cnt['z'] -= cnt;
        val2cnt['e'] -= cnt;
        val2cnt['r'] -= cnt;
        val2cnt['o'] -= cnt;
        //2
        cnt = digitCnt[2] = val2cnt['w'];
        val2cnt['t'] -= cnt;
        val2cnt['w'] -= cnt;
        val2cnt['o'] -= cnt;
        //4
		cnt = digitCnt[4] = val2cnt['u'];
        val2cnt['f'] -= cnt;
        val2cnt['o'] -= cnt;
        val2cnt['u'] -= cnt;
        val2cnt['r'] -= cnt;
        //6
        cnt = digitCnt[6] = val2cnt['x'];
        val2cnt['s'] -= cnt;
        val2cnt['i'] -= cnt;
        val2cnt['x'] -= cnt;
        //8
        cnt = digitCnt[8]= val2cnt['g'];
        val2cnt['e'] -= cnt;
        val2cnt['i'] -= cnt;
        val2cnt['g'] -= cnt;
        val2cnt['h'] -= cnt;
        val2cnt['t'] -= cnt;
        //1
        cnt = digitCnt[1] = val2cnt['o'];
        val2cnt['o'] -=cnt;
        val2cnt['n'] -=cnt;
        val2cnt['e'] -=cnt;
        //3
        cnt = digitCnt[3] = val2cnt['r'];
        val2cnt['t'] -= cnt;
        val2cnt['h'] -= cnt;
        val2cnt['r'] -= cnt;
        val2cnt['e'] -= 2 * cnt;
        //5
        cnt = digitCnt[5] = val2cnt['f'];
        val2cnt['f'] -= cnt;
        val2cnt['i'] -= cnt;
        val2cnt['v'] -= cnt;
        val2cnt['e'] -= cnt;
        //7
        cnt = digitCnt[7] = val2cnt['s'];
        val2cnt['s'] -= cnt;
        val2cnt['e'] -= 2 * cnt;
        val2cnt['v'] -= cnt;
        val2cnt['n'] -= cnt;
        //9
		cnt = digitCnt[9] = val2cnt['i'];
        val2cnt['n'] -= 2 * cnt;
        val2cnt['i'] -= cnt;
        val2cnt['e'] -= cnt;

        //generate answer
        std::string ans;
        for(int i = 0;i < digitCnt.size();++i)
        	ans.append(digitCnt[i],i+'0');
        return ans;
    }
};

//method 2:similar to Gaussian Elimination
/*
hint:
The number 0-9 is a variable which is the number of iterselgt. Eg. 0 is a variable which stands for the number of digit 0
The alpha a-z is a variable which is the number of iterselft. Eg. z is a variable which stands for the number of alpha z

e = 0 + 1 + 3 + 5 + 7 + 8 + 9
f = 4 + 5
g = 8 +
h = 3 + 8
i = 5 + 6 + 8 + 9
n = 1 + 7 + 9
o = 0 + 1 + 2 + 4
r = 0 + 3 + 4
s = 6 + 7
t = 2 + 3 + 8
u = 4
v = 5 + 7
w = 2
x = 6
z = 0
*/
class Solution {
public:
	std::string originalDigits(std::string &s) {
	    std::vector<int> val2cnt(128, 0); 
	    for (auto c: s)
	        ++val2cnt[c];	
	    std::vector<int> num(10, 0);
	  
	    num[0] = val2cnt['z'];
	    num[2] = val2cnt['w'];
	    num[4] = val2cnt['u'];
	    num[8] = val2cnt['g'];
	    num[5] = val2cnt['f'] - num[4];
	    num[7] = val2cnt['v'] - num[5];
	    num[3] = val2cnt['t'] - num[2] - num[8];
	    
	    num[6] = val2cnt['s'] - num[7];
	    num[1] = val2cnt['o'] - num[0] - num[2] - num[4];
	    num[9] = val2cnt['i'] - num[5] - num[6] - num[8];
	    std::string ans;
	    for (int i = 0; i < 10; i ++)
	        ans.append(num[i], '0' + i);
	    return ans;
	 }
};
