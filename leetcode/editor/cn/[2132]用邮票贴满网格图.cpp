//给你一个 m x n 的二进制矩阵 grid ，每个格子要么为 0 （空）要么为 1 （被占据）。 
//
// 给你邮票的尺寸为 stampHeight x stampWidth 。我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ： 
//
// 
// 覆盖所有 空 格子。 
// 不覆盖任何 被占据 的格子。 
// 我们可以放入任意数目的邮票。 
// 邮票可以相互有 重叠 部分。 
// 邮票不允许 旋转 。 
// 邮票必须完全在矩阵 内 。 
// 
//
// 如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 
//4, stampWidth = 3
//输出：true
//解释：我们放入两个有重叠部分的邮票（图中标号为 1 和 2），它们能覆盖所有与空格子。
// 
//
// 示例 2： 
//
// 
//
// 输入：grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, 
//stampWidth = 2 
//输出：false 
//解释：没办法放入邮票覆盖所有的空格子，且邮票不超出网格图以外。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[r].length 
// 1 <= m, n <= 10⁵ 
// 1 <= m * n <= 2 * 10⁵ 
// grid[r][c] 要么是 0 ，要么是 1 。 
// 1 <= stampHeight, stampWidth <= 10⁵ 
// 
//
// Related Topics 贪心 数组 矩阵 前缀和 👍 102 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size() , m = grid[0].size();
        
        vector<vector<int>> pre(n + 1 , vector<int>(m + 1));
        vector<vector<int>> dif(n + 2 , vector<int>(m + 2));
        
        for(int i = 1; i <= n ; i ++){
            for(int j = 1 ; j <= m ; j ++){
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + grid[i - 1][j - 1] - pre[i - 1][j - 1];
            }
        }
        
        
        for(int i = 1; i + stampHeight - 1 <= n ; i ++){
            for(int j = 1 ; j + stampWidth - 1 <= m ; j ++){
                int x = i + stampHeight - 1;
                int y = j + stampWidth - 1;
                if(pre[x][y] - pre[x][j - 1] - pre[i - 1][y] + pre[i - 1][j - 1] == 0)
                {
                    dif[i][j] ++;
                    dif[i][y + 1] --;
                    dif[x + 1][j] --;
                    dif[x + 1][y + 1] ++;
                }
            }
        }
        
        for(int i =  1 ; i <= n ; i ++){
            for(int j = 1 ; j <= m ; j ++){
                dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
                if(dif[i][j] == 0 && grid[i - 1][j - 1] == 0){
                    return false;
                }
            }
        }
        
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
