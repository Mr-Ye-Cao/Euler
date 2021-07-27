// This program can also be implemented using Hashtable instead of Trie, which is even faster
// The concept is the same to utilize memorization of portions of the string and try to find a match
// But I found the this one using Trie particularly smart

// originally from https://www.geeksforgeeks.org/palindrome-pair-in-an-array-of-words-or-strings/

// C++ program to check if there is a pair that
// of above method using Trie

/***
 * The construction of Trie is backward and [np]
 * the leaf nodes store the id of the word
 * the searching of pair is forward         [np](p)
 * searching: if parsing a word forward and traversing
 * the Trie step by step ends at a node leave with different id
 * it means a palindrom can be formed [np](p)[np]
 * Another possiblity is that [np][np]
 **/

#include<bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    vector<int> pos; // To store palindromic
                    // positions in str
    int id;

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new Trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isLeaf = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

    return pNode;
}

// Utility function to check if a string is a
// palindrome
bool isPalindrome(string str, int i, int len)
{
    // compare each character from starting
    // with its corresponding character from last
    while (i < len)
    {
        if (str[i] != str[len])
            return false;
        i++, len--;
    }

    return true;
}

// If not present, inserts reverse of key into Trie. If
// the key is prefix of a Trie node, just mark leaf node
void insert(struct TrieNode* root, string key, int id)
{
    struct TrieNode *pCrawl = root;

    // Start traversing word from the last
    for (int level = key.length()-1; level >=0; level--)
    {
        // If it is not available in Trie, then
        // store it
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        // If current word is palindrome till this
        // level, store index of current word.
        if (isPalindrome(key, 0, level))
            (pCrawl->pos).push_back(id);

        pCrawl = pCrawl->children[index];
    }
    pCrawl->id = id;
    pCrawl->pos.push_back(id);

    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// Returns true if key presents in Trie, else false
void search(struct TrieNode *root, string key,
            int id, vector<vector<int> > &result)
{
    struct TrieNode *pCrawl = root;
    for (int level = 0; level < key.length(); level++)
    {
        int index = CHAR_TO_INDEX(key[level]);

    /***
     * The construction of Trie is backward and [np]
     * the leaf nodes store the id of the word
     * the searching of pair is forward         [np](p)
     * searching: if parsing a word forward and traversing
     * the Trie step by step ends at a node leave with different id
     * it means a palindrom can be formed [np](p)[np]
    **/

        // If it is present also check upto which index
        // it is palindrome
        if (pCrawl->id >= 0 && pCrawl->id != id &&
            isPalindrome(key, level, key.size()-1))
            result.push_back({id, pCrawl->id});

        // If not present then return
        if (!pCrawl->children[index])
            return;

        pCrawl = pCrawl->children[index];
    }

    //  Another possiblity is that [np][np]

    for (int i: pCrawl->pos)
    {
        if (i == id)
            continue;
        result.push_back({id, i});
    }
}

// Function to check if a palindrome pair exists
bool checkPalindromePair(vector <string> vect)
{
    // Construct trie
    struct TrieNode *root = getNode();
    for (int i = 0; i < vect.size(); i++)
        insert(root, vect[i], i);

    // Search for different keys
    vector<vector<int> > result;
    for (int i=0; i<vect.size(); i++)
    {
        search(root, vect[i], i, result);
        if (result.size() > 0)
        return true;
    }

    return false;
}

// Driver code
int main()
{
    vector <string> vect = {"geekf", "geeks", "or",
                            "keeg", "abc", "bc"};


    checkPalindromePair(vect)? cout << "Yes" :
                            cout << "No";
    return 0;
}
