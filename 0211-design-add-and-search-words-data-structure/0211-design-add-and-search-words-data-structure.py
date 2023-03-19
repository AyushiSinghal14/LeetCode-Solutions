class WordDictionary:

    def __init__(self):
        self.root = dict()
        self.EOW = "EOW"
        

    def addWord(self, word: str) -> None:
        cur_dict = self.root
        for c in word:
            if c not in cur_dict:
                cur_dict[c] = dict()
            cur_dict = cur_dict[c]
        cur_dict[self.EOW] = True
        

    def search(self, word: str) -> bool:
        return self.dfsMatch(word, 0, self.root)
    
    def dfsMatch(self, wd, idx, cur_dict):
        if idx == len(wd):
            return self.EOW in cur_dict
        
        if wd[idx] == '.':
            for nc in cur_dict:
                if nc != self.EOW:
                    found = self.dfsMatch(wd, idx + 1, cur_dict[nc])
                    if found:
                        return True
        else:
            if wd[idx] in cur_dict:
                return self.dfsMatch(wd, idx + 1, cur_dict[wd[idx]])
            
        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)