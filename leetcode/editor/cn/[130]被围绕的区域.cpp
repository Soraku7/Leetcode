//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//。
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
//输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O",
//"X","X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// 
//
// 示例 2： 
//
// 
//输入：board = [["X"]]
//输出：[["X"]]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] 为 'X' 或 'O' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1041 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n , m;
    int dx[4] = {0 , 1 , 0 , -1};
    int dy[4] = {1 , 0 , -1 , 0};
    void solve(vector<vector<char>>& board) {
        m = board.size() , n = board[0].size();
        
        for(int i = 0 ; i < m ; i ++){
            if(board[i][0] == 'O') dfs(board , i , 0);
            if(board[i][n - 1] == 'O') dfs(board , i , n - 1);
        }
        
        for(int i = 0 ; i < n ; i ++){
            if(board[0][i] == 'O') dfs(board , 0 , i);
            if(board[m - 1][i] == 'O') dfs(board , m - 1 , i);
        }
        
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else{
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board , int x , int y){
        board[x][y] = '#';
        
        for(int i = 0 ; i < 4 ; i ++){
            int nx = x + dx[i] , ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >=0 && ny < n && board[nx][ny] == 'O'){
                dfs(board , nx , ny);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
