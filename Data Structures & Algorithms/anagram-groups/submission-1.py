class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        w = defaultdict(list)

        for word in strs:
            sortedWord = ''.join(sorted(word))
            w[sortedWord].append(word)
        
        return list(w.values())