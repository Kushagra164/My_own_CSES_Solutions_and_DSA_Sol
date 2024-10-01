#include <bits/stdc++.h>
using namespace std;

// Name: Kushagra Khare
// Roll No. : 20CS02004

// Input : words.txt
// Options :
// • ‘i’ – InsertIntoTrie (“word”)
// • ‘f’ – SearchInTrie(“word”)
// • ‘s’ - Sort
// • ‘q’ – Quit


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
    Trie(){
        root = new TrieNode();
    }
    void insertIntoTrie(string word){
        int n = word.size();
        TrieNode* curr = root;
        for (int i=0;i<n;i++){
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

    void SortTrie(vector<string> &sortedOrder){
        string s = "";
        applyDFS(s,root->child,sortedOrder);
    }

    void applyDFS(string &s,TrieNode* curr,vector<string> &sortedOrder){
        if (curr == NULL) return ;
        s.push_back(curr->ch);
        if (curr->isWord) sortedOrder.push_back(s);
        // First Traverse child
        applyDFS(s,curr->child,sortedOrder);
        // Travel sibling
        s.pop_back();
        applyDFS(s,curr->sibling,sortedOrder);

        return ;
    }
    
};

int main() {
    
    Trie tr;

    ifstream file("../words.txt");
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        tr.insertIntoTrie(word);
    }
    file.close();

    char option;
    do {
        cout << "Choose an option:\n"
                  << "'i' - InsertIntoTrie\n"
                  << "'f' - SearchInTrie\n"
                  << "'s' - Sort\n"
                  << "'q' - Quit\n";
        cin >> option;

        if (option == 'i') {
            cout << "Enter word to insert: ";
            cin >> word;
            tr.insertIntoTrie(word);
            cout << word << " inserted into trie." << endl;
        } else if (option == 'f') {
            cout << "Enter word to search: ";
            cin >> word;
            if (tr.searchInTrie(word)) {
                cout << word << " found in trie." << endl;
            } else {
                cout << word << " not found in trie." << endl;
            }
        } else if (option == 's') {
            cout << "Words in sorted order:\n";
            vector<string> sortedOrder; 
            tr.SortTrie(sortedOrder);
            for (string s: sortedOrder) cout << s << "\n";
        } else if (option != 'q') {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 'q');

    cout << "Program exited." << endl;

    return 0;

}