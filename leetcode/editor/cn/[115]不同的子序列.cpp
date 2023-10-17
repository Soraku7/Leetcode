//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。 
//
// 题目数据保证答案符合 32 位带符号整数范围。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//rabbbit
//rabbbit
//rabbbit 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 1058 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j]) dp[i][j] = (0LL + dp[i][j] + dp[i - 1][j - 1]) % INT_MAX;
            }
        }
        return dp[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
