from string import ascii_lowercase

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word)<3:
            return False
        f = [0]*2
        for c in word:
            if c.isalpha():
                f[c.lower() in "aeiou"] = 1
            elif not c.isdigit():
                return False
        return sum(f) == 2
        
        # if len(word)<3:
        #     return False
        # word = word.lower()
        # is_vowel, is_consonant = False, False
        # digits = ascii_lowercase+"0123456789"
        # vowels = "aeiou"
        # for c in word:
        #     if c not in digits:
        #         return False
        #     if c in vowels:
        #         is_vowel = True
        #     if c not in vowels and c in ascii_lowercase:
        #         is_consonant = True
        # return is_vowel and is_consonant

if __name__ == "__main__":
    s = Solution()
    word = "234Adas"
    print(s.isValid(word))
