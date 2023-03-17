class Trie {
public:
 unordered_map<string,int>wordcount; // to store the count of words
 unordered_map<char,vector<string>>words; // to store strings
    Trie() {
        unordered_map<char,vector<string>>input;
        words=input;
    }
    
    void insert(string word) {
        words[word[0]].push_back(word); // pushing back starting letter of the word and entire word
        wordcount[word]++; // count 
    }
    
    bool search(string word) {
        if(wordcount[word]>0){ // checks if the string is present
            return true;
        }
        return false;
    }

       bool startsWith(string prefix) {
        for (auto str : words[prefix[0]]) { // iterates over the string which starts with first letter of the prefix
            if (str.find(prefix) == 0) { // checks if the words has the prefix.
                return true;
            }
        }
        return false;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */