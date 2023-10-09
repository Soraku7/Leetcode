//按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> 
//s1 -> s2 -> ... -> sk 这样的单词序列，并满足： 
//
// 
// 
// 
// 每对相邻的单词之间仅有单个字母不同。 
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单
//词。 
// sk == endWord 
// 
// 
// 
//
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的
// 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log","cog"]
//输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//解释：存在 2 种最短的转换序列：
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log"]
//输出：[]
//解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 5 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 500 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有单词 互不相同 
// 
//
// Related Topics 广度优先搜索 哈希表 字符串 回溯 👍 665 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin() , wordList.end());
        
        if(!dict.count(endWord)) return {};
        
        dict.erase(beginWord);
        dict.erase(endWord);
        
        unordered_map<string , int>steps{{beginWord , 1}};
        unordered_map<string , vector<string>> parents;
        
        queue<string> q;
        q.push(beginWord);
        
        vector<vector<string>> ans;
        
        const int l = beginWord.length();
        int step = 0;
        bool found = false;
        
        while(!q.empty() && !found){
            step ++;
            for(int size = q.size() ; size > 0 ; size --){
                const string p = q.front() ;
                q.pop();
                
                string w = p;
                
                for(int i = 0 ; i < l ; i ++){
                    const char ch = w[i];
                    for(int j = 'a' ; j <= 'z' ; j ++){
                        if(j == ch){
                            continue;
                        }
                        w[i] = j;
                        
                        if(w == endWord){
                            parents[w].push_back(p);
                            found = true;
                        }
                        else{
                            //该单词出现过 且路径步数少于之前步数
                            if(steps.count(w) && step < steps.at(w)){
                                parents[w].push_back(p);
                            }
                        }
                        
                        if(!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        steps[w] = steps.at(p) + 1;
                        parents[w].push_back(p);
                    }
                    
                    w[i] = ch;
                }
            }
        }
        
        if(found){
            vector<string> cur{endWord};
            
            getPath(endWord , beginWord , parents , cur , ans);
        }
        
        return ans;
    }
    
    void getPath(const string& word,
                 const string& beginWord ,
                 const unordered_map<string , vector<string>>& parents ,
                 vector<string>& cur ,
                 vector<vector<string>>& ans){
        if(word == beginWord){
            ans.push_back(vector<string>(cur.rbegin() , cur.rend()));
            return;
        }
        
        for(const string& p: parents.at(word)){
            cur.push_back(p);
            getPath(p , beginWord , parents , cur , ans);
            cur.pop_back();
        }
    }
    
};

