"""

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
which is then converted into a different digit string.
To determine how you "say" a digit string, 
split it into the minimal number of substrings such that each substring contains exactly one unique digit.
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

Examples:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

example create by me '-
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
countAndSay(5) = say "1211" = one 1 + one 2 + dois 1 = 11 + 12 + 21 = "111221" 

"""


class Solution:

    def count(self,entrada: str) -> str:
        count_list = []
        previous = ""
        index = -1

        for num in entrada:
            if num == previous:
                count_list[index][0] += 1
            else: 
                count_list.append([1,num])
                index += 1
            previous = count_list[index][1]
        
        list_str = [' '.join(map(str,lista)) for lista in count_list]

        result = "".join(list_str).replace(" ","")
        return result
        

    def countAndSay(self, n: int) -> str:
        
        if n == 1:
            return "1"
        
        output = self.countAndSay(n-1)
        return self.count(output)

    

        



