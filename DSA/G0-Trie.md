# TRIE TREE
---
Trie tree is a digital search tree where each node can contain `m` pointers. It is generally used to store strings
- If used to store numbers, a key can have  10 pointers (digits 0 to 9)
- If used to store words, a key can have 26 pointers
- Trie is derived from reTRIEval
- Can perform storing and retrieval faster than a hash table
- Can be used for prefix based searching

### Advantages
-  We can efficiently do **prefix search** (or auto-complete) with Trie.
-  We can easily print all words in alphabetical order which is not easily possible with hashing.
-  There is no overhead of Hash functions in a Trie data structure.
-  Searching for a String even in the large collection of strings in a Trie data structure can be done in **O(L)** Time complexity, Where L is the number of words in the query string. This searching time could be even less than O(L) if the query string does not exist in the trie.

### Properties
-  There is one root node in each Trie.
-  Each node of a Trie represents a string and each edge represents a character.
-  Every node consists of hashmaps or **an array of pointers**, with each index representing a character and a flag to indicate if any string ends at the current node.
-  Trie data structure can contain any number of characters including **alphabets**, **numbers**, and **special characters**.  For a lowercase alphabet set, the **0th** index represents **‘a’** and the **25th** index represents **‘z’** characters.
-  Each path from the root to any node represents a word or string.


