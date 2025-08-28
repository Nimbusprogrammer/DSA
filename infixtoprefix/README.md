You are given an infix expression in the form of a string s, consisting of:

Lowercase alphabetical operands (a to z).
Standard arithmetic operators: +, -, *, /, ^.
Optional parentheses for grouping.


Your task is to convert this infix expression into its equivalent prefix expression and return it as a string.

Examples:

Input: s = "a*b+c/d"
Output: +*ab/cd 
Explaination: In prefix notation, operators come before their operands a*b → *ab, c/d → /cd
Since * and / have higher precedence than +, we evaluate them first, then apply +, So the final prefix expression is: +*ab/cd
Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl
Explaination: Convert inner divisions first : b/c → /bc , a/k → /ak
Handle subtractions next: a-b/c → -a/bc, a/k-l → -/akl
Finally, apply multiplication:
(a-b/c) * (a/k-l) → *-a/bc-/akl
Constraints:
1 ≤ s.size() ≤ 105