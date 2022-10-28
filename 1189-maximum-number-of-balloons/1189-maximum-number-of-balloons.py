class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        chars = {}
        for i in text:
            if i not in chars.keys():
                chars[i] = 1
            else:
                chars[i] += 1
        
        word = {"b" : 1,
               "a" : 1,
               "l" : 2,
               "o" : 2,
               "n" : 1}
        
        minV = math.inf
        for i in word.keys():
            if i in chars.keys():
                minV = min(minV, chars[i] // word[i])
            else:
                minV = 0
                break
            
        return minV
        