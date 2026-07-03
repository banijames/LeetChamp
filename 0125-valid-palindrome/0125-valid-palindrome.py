class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        result="".join(ch for ch in s if ch.isalnum())
        if result[::-1]==result:
            return True
        else :
            return False