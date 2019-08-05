//use a tmp array
class Solution {
public:
    void rotate( vector<int>& nums, int k ) {
        int n = nums.size();
        if(n < 2)
            return;
        k %= n;
        if(k == 0)
            return;
        std::vector<int> tmp( nums.begin(), nums.end() );
        for( int i=0; i < n; i++ )
            nums[i] = tmp[ ( n - k  + i ) % n ];
    }
};

//one pass, space O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return;
        k %= n;
        if(k == 0)
            return;
        for(int start = 0, cnt = 0; cnt < n; ++start)
        {
            int dest_idx = start, src_val = nums[start], dest_val;
            do{
                dest_idx = (dest_idx + k) % n;
                dest_val = nums[dest_idx];
                //move
                nums[dest_idx] = src_val;
                ++cnt; //cnt is the number of element moved
                //update src_val
                src_val = dest_val;
            }while(dest_idx != start);//0 is first element moved, when k = 2 is error
        }
        
    }
};

//reverse
class Solution {
public:
    void rotate( vector<int>& nums, int k ) {
        int n = nums.size();
        if(n < 2)
            return;
        k %= n;
        if(k == 0)
            return;
        std::reverse( nums.begin(), nums.end() );
        std::reverse( nums.begin(), nums.begin() + k );
        std::reverse( nums.begin() + k, nums.end() );

    }
};

