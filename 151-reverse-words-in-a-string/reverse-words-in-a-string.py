class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split()
        # print(words)
        reversed_w = words[::-1]

        return ' '.join(reversed_w)