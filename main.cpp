
/* Tries data structure for dictionary
 *  finds meaning of word wrt to certain word stored in tries
 *  implemented by umer zia
 * importing essential libraries */

#include <iostream>
#include <unordered_map> // for storing char in  tries . Each value is in key value form

using namespace std;

// Structure for Trie
struct Trie {
    bool end; // for making record if node is leaf node . If it is -> searching stops
    unordered_map<char, Trie*> map;
    // For each char (key) in tries there is a value of meaning (string)
    string meaning; // meaning for words in dictionary
};

// Function to create a new Trie node
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->end = false;
    return node;
}

// Function to insert a word with its meaning
// in the dictionary built using a Trie
void insert(Trie*& root, const string& str,
            const string& meaning)
{

    // If root is null
    if (root == NULL)
        root = getNewTrieNode();

    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];

        // Make a new node if there is no path
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();

        temp = temp->map[x];
    }
    // Iterates through each letter of input word . If letter already not in tree then it makes new node
    // else if word already exists it searches down the tries till whole word is completed.

    // Mark end of word and store the meaning
    temp->end = true;
    temp->meaning = meaning; // storing input meaning in the leaf node
}

// Function to search a word in the Trie
// and return its meaning if the word exists
string getMeaning(Trie* root, const string& word)
{

    // If root is null i.e. the dictionary is empty
    if (root == NULL)
        return "";

    Trie* temp = root;

    // Search a word in the Trie
    for (int i = 0; i < word.length(); i++) {
        temp = temp->map[word[i]];
        if (temp == NULL) // if word not found return empty string
            return "";
    }

    // If it is the end of a valid word stored
    // before then return its meaning
    if (temp->end)
        return temp->meaning;
    return "";
}

// to be used in our main class for inserting and searching meaning.
int main()
{
    Trie* root = NULL;

    // inserting word in dictionary
    insert(root, "computer", "A computer is a machine that can be instructed to carry out sequences of arithmetic computations");

    // searching meaning for saved word in dictionary
    string input = "computer";
    cout << getMeaning(root, input);

    return 0;
}
