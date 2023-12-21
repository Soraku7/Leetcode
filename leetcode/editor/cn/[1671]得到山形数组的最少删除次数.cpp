//我们定义 arr 是 山形数组 当且仅当它满足： 
//
// 
// arr.length >= 3 
// 存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且： 
// 
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 
// 
// 
//
// 给你整数数组 nums ，请你返回将 nums 变成 山形状数组 的 最少 删除次数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,1]
//输出：0
//解释：数组本身就是山形数组，所以我们不需要删除任何元素。
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,1,1,5,6,2,3,1]
//输出：3
//解释：一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 1000 
// 1 <= nums[i] <= 10⁹ 
// 题目保证 nums 删除一些元素后一定能得到山形数组。 
// 
//
// Related Topics 贪心 数组 二分查找 动态规划 👍 58 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        nums.insert(nums.begin() , 0);
        int n = nums.size();
        vector<int> f(n + 1 , 0);
        vector<int> g(n + 1 , 0);
        
        int res = 0;
        for(int i = 1 ; i <= n - 1; i ++){
            f[i] = 1;
            for(int j = 1 ; j < i ; j ++){
                if(nums[j] < nums[i]){
                    f[i] = max(f[i] , f[j] + 1);
                }
            }
        }
        
        for(int i = n - 1; i > 0 ; i --){
            g[i] = 1;
            for(int j = n - 1; j > i ; j --){
                if(nums[j] < nums[i]){
                    g[i] = max(g[i] , g[j] + 1);
                }
            }
        }
        
        
        for(int i = 1 ; i <= n ; i ++)
            if(f[i] != 1 && g[i] != 1)
                res = max(res , g[i] + f[i] - 1);
        
        return n - 1 - res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
