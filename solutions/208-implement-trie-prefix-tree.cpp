#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
  char ch;
  shared_ptr<TrieNode> children[26];
  TrieNode() : ch(0) {}

 public:
  shared_ptr<TrieNode> next(char ch) { return children[ch - 'a']; }
};

class Trie {
 private:
  shared_ptr<TrieNode> root;

 public:
  /** Initialize your data structure here. */
  Trie() : root(make_shared<TrieNode>()) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    auto p = root;
    auto it = word.begin();
    while (it != word.end() && p->children[*it - 'a']) {
      p = p->next(*it++);
    }
    while (it != word.end()) {
      p->children[*it - 'a'] = make_shared<TrieNode>();
      p = p->next(*it++);
    }
    p->ch = *(it - 1);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto p = root;
    auto it = word.begin();
    while (it != word.end() && p->children[*it - 'a']) {
      p = p->next(*it++);
    }
    if (it == word.end() && p->ch) {
      return true;
    }
    return false;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto p = root;
    auto it = prefix.begin();
    while (it != prefix.end() && p->children[*it - 'a']) {
      p = p->next(*it++);
    }
    if (it == prefix.end()) {
      return true;
    }
    return false;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie trie;
  trie.insert("apple");
  cout << trie.search("app") << endl;
  cout << trie.startsWith("app") << endl;
  cout << trie.startsWith("apple") << endl;
  cout << trie.search("b") << endl;
  trie.insert("b");
  cout << trie.startsWith("b") << endl;
  cout << trie.search("b") << endl;
}
