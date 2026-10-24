class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s1 = " ".join(sorted(s))
        s2 = " ".join(sorted(t))

        if len(s1) != len(s2):
            return False

        if s1 == s2:
            return True
        return False
