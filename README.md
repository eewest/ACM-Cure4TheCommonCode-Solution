# Cure for the Common Code
The code to the solution to the ACM programming challenge titled Cure for the common code. The problem number is 6876. This is my own solution ot the problem written in C. This prints out the actual string though rather than output the length of the string.

# External Link to the ACM-ICP Archive 
https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4888

# 6875 Cure for the Common Code Problem Description
You’ve been tasked with relaying coded messages to your fellow resistance fighters. Each coded message
is a sequence of lower-case letters that you furtively scrawl on monuments in the dead of night.
Since you’re writing these messages by hand, the longer the message, the greater the likelihood of
being caught by the evil empire while writing. Because of this you decide it would be worthwhile to
come up with a simple encoding that might allow for shorter messages. After thinking about it for a
while, you decide to use integers and parentheses to indicate repetition of substrings when doing so
shortens the number of characters you need to write. For example, the 10 character string ‘abcbcbcbca’
could be more briefly written as the 7 character string ‘a4(bc)a’
If a single letter is being repeated, parentheses are not needed. Also, repetitions may themselves be
repeated, so you can write the 20 character string ‘abbbcdcdcdabbbcdcdcd’ as the 11 character string
‘2(a3b3(cd))’ and so forth
