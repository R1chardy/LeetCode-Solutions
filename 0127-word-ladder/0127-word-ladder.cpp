class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Create a set for efficient lookup of words in wordList
    unordered_set<string> dict(wordList.begin(), wordList.end());

    // If endWord is not in the dictionary, there is no transformation sequence
    if (!dict.count(endWord)) {
        return 0;
    }

    // Use a queue to perform breadth-first search
    queue<string> q{{beginWord}};
    int steps = 0;
    while (!q.empty()) {
        // Increase the number of steps taken
        ++steps;

        // Process all words in the current layer of the search tree
        for (int size = q.size(); size > 0; --size) {
            string word = q.front();
            q.pop();

            // Check if the current word is the endWord
            if (word == endWord) {
                return steps;
            }

            // Generate all possible transformations of the current word
            for (int i = 0; i < word.size(); ++i) {
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == word[i]) continue;
                    string newWord = word;
                    newWord[i] = ch;
                    if (dict.count(newWord)) {
                        // Add the transformed word to the queue
                        q.emplace(newWord);
                        // Remove the transformed word from the dictionary to avoid visiting it again
                        dict.erase(newWord);
                    }
                }
            }
        }
    }
    return 0;
}


};