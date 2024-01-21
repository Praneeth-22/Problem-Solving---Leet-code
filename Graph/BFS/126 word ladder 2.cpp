//126. Word Ladder II
//Hard
//Topics
//Companies
//A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//
//Every adjacent pair of words differs by a single letter.
//Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
//
// 
//
//Example 1:
//
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//Explanation: There are 2 shortest transformation sequences:
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
//Example 2:
//
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//Output: []
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedInLvl;
        int lvl = 0;
        usedInLvl.push_back(beginWord);
        vector<vector<string>> ans;
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            if (vec.size() > lvl) {
                lvl++;
                for (auto it : usedInLvl) {
                    s.erase(it);
                }
                usedInLvl.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()) ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); i++) {
                char org = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(s.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedInLvl.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = org;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    // Print the result
    cout << "Word Ladders from " << beginWord << " to " << endWord << " are:\n";
    for (const auto& ladder : result) {
        for (const string& word : ladder) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}
