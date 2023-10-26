//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。 
//
// 返回符合要求的 最少分割次数 。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：s = "ab"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 720 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> g(n , vector<bool>(n));
        
        for(int j = 0 ; j < n ; j ++){
            for(int i = 0 ; i <= j ; i ++){
                if(i == j) g[i][j] = true;
                else g[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || g[i + 1][j - 1]);
            }
        }
        
        vector<int> f(n , INT_MAX);
        //f[1,r]回文
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j <= i ; j ++){
                if(!g[j][i]) continue;
                if(j == 0) f[i] = 0;
                else f[i] = min(f[i] , f[j - 1] + 1);
            }
        }
        
        return f[n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
