//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。 
//
// 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。 
//
// 
// 
// 
// 
// 
//
// 示例 1 ： 
//
// 
//输入：nums = [2,2,1]
//输出：1
// 
//
// 示例 2 ： 
//
// 
//输入：nums = [4,1,2,1,2]
//输出：4
// 
//
// 示例 3 ： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// -3 * 10⁴ <= nums[i] <= 3 * 10⁴ 
// 除了某个元素只出现一次以外，其余每个元素均出现两次。 
// 
//
// Related Topics 位运算 数组 👍 3050 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
lass Solution {
        public:
        int candy(vector<int>& ratings) {
            vector<int> sup(ratings.size() , 1);
            
            for(int i = 1 ; i < ratings.size() ; i ++){
                if(ratings[i] > ratings[i - 1]) sup[i] = sup[i - 1] + 1;
            }
            
            for(int i = ratings.size() - 2 ; i >= 0 ; i --){
                if(ratings[i] > ratings[i + 1])
                    sup[i] = max(sup[i + 1] + 1, sup[i]);
            }
            int ans = 0;
            for(int i : sup){
                ans += i;
            }
            
            return ans;
        }
};
//leetcode submit region end(Prohibit modification and deletion)
