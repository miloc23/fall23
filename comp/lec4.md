A language is a set of strings of symbols that are constrained by rules


Syntax
    - to describe what its programs look like
    - specified using regular expressions and context-free grammars
Semantics
    - to describe what its programs mean
    - specified using axiomatic semantics, operational semantics, or denotational semantics

Regular expressions
- a unified representation for a set of strings
- a regular expression is constructed from one or more
    - a character
    - the empty string (epsilon)
    - two or more regular expressions concatenated .
    - two ore more regular expressions seperated by |
    - a regular expression followed by th eKleene star (concat of 0 or more)

- additional symbols
    - + one or more
    - [] simplified or, and slects any one of the characters in the brackets
    - []+ represents a subcomponenet with 1 or emore instances of any internal characters concatednated together
    - - (hyphen) defines a range

Define Regular Expressions
    - match strings only consisting of 'a', 'b', 'c' characters
    - match only the strings "Buy more milk", "Buy more bread", or "Buy more juice"
    - match identifies which contain letters and digits starting with a letter

    - a+|b+|c+
    - Buy more "milk"|"bread"|"juice"
    - [a-zA-Z][a-zA-Z0-9]*

Lexeme
    - a sequence of characters in the source program with the lowest level of syntactic meanings
    - e.g. sum, +, -

Token
    - a category of lexemes
    - a lexeme is an instance of token
    - the basic building blocks of programs

Context-free grammars
- grammar defined by a set of rules that are independent of the context they are called in.
- using the notation Backus-Naur Form (BNF)
- A context free grammar consists of
    - a set of terminals T
    - a set of non-terminals N
    - a start symbol S
    - a set of productions P

Example of BNF
G = {T, N, S, P}
S = <if_stmt>
T = {if, then, else}
N = {<if_stmt>, <logic_expr>, <stmt>}
P{
<if_stmt> => if <logic_expr> then <stmt>
           | if <logic_expr> then <stmt> else <stmt>
}

derivation
- a derivation is a repeated application of rules, starting with the
