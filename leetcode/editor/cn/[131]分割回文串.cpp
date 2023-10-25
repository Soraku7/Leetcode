//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1663 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    vector<vector<bool>> f;
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        n = s.length();
        
        f = vector<vector<bool>>(n , vector<bool>(n));
        
        for(int j = 0 ; j < n ; j ++){
            for(int i = 0 ; i <= j ; i ++){
                if(i == j) f[i][j] = true;
                else f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
            }
        }
        
        dfs(s , 0);
        return ans;
    }
    
    void dfs(string &s , int idx){
        if(idx == n){
            ans.push_back(path);
            return;
        }
        
        for(int i = idx ; i < n ; i ++){
            if(!f[idx][i]) continue;
            
            path.push_back(s.substr(idx , i - idx + 1));
            dfs(s , i + 1);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
