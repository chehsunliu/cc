class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        counts = {}
        for c in magazine:
            if c not in counts:
                counts[c] = 0
            counts[c] += 1
        
        for c in ransomNote:
            if c not in counts or counts[c] == 0:
                return False
            
            counts[c] -= 1
            
        return True