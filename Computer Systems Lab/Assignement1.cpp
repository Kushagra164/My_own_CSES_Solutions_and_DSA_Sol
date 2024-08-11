#include <bits/stdc++.h>
using namespace std;

// 

class TrieNode{
public:
    char ch;
    TrieNode* sibling;
    TrieNode* child;
    bool isWord;
};

class Trie{
    TrieNode* root;
public:
    set<string> st;
    
    Trie(){
        root = new TrieNode();
    }
    void insertIntoTrie(string word){
        st.insert(word);
        int n = word.size();
        TrieNode* curr = root;
        for (int i=0;i<n;i++){
            // cout << word[i] << "\n";
            if (curr->child == NULL){
                TrieNode* temp = new TrieNode();
                temp->ch = word[i];
                curr->child = temp;
                curr = temp;
            }
            else{
                if (curr->child->ch == word[i]){
                    curr = curr->child;
                    continue;
                }
                else{
                    TrieNode* temp = curr->child;
                    TrieNode* prev = NULL;
                    while(temp && temp->ch < word[i]) {
                        prev = temp;
                        temp = temp->sibling;
                    }
                    if (temp && temp->ch == word[i]){
                        curr=temp;
                        continue;
                    }
                    if (temp == NULL){
                        temp = new TrieNode();
                        temp -> ch = word[i];
                        prev->sibling = temp;
                        curr = temp;
                        continue;
                    }
                    if (prev == NULL){
                        prev = new TrieNode();
                        prev -> ch = word[i];
                        prev -> sibling = temp;
                        curr->child = prev;
                        curr = prev;
                        continue;
                    }
                    TrieNode* between = new TrieNode();
                    between -> ch = word[i];
                    between -> sibling = temp;
                    prev->sibling = between;
                    curr = between;
                }
            }
        }
        curr->isWord = true;
        
        return ;
    }
    
    bool searchInTrie(string word){
        int n = word.size();
        TrieNode* curr = root;
        for (int i=0;i<n;i++){
            TrieNode* temp = curr->child;
            while(temp && temp->ch != word[i]) temp = temp->sibling;
            if (!temp) return false;
            curr = temp;
        }
        if (curr->isWord) return true;
        return false;
    }
    
};

int main() {
    
    Trie tr;
    vector<string> test  = {"A","DOG","ANT","CAT","ANALYTIC","AN","ANALOGY","CATALYST","DOGMATIC","DOT","DOLL"};
    for (string s: test) {
        tr.insertIntoTrie(s);
    }
    cout << tr.searchInTrie("DOG") << "\n";
    cout << tr.searchInTrie("CATALYST") << "\n";
    cout << tr.searchInTrie("ANTY") << "\n";
    
    cout << "Sorted Order is: \n";
    for (auto s:tr.st) cout << s << "\n";
    
    return 0;
}