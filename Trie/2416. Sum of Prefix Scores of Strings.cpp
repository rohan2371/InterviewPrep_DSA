/*
Leetcode Link : https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
*/

// solution one using hashset
// getting memory limit exceeded
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto &it : words)
        {
            string prefix = "";
            for(auto &ch : it){
                prefix+=ch;
                mp[prefix]++;
            }
        }

        vector<int>ans(words.size(),0);

        for(int i=0;i<words.size();i++){
            int score = 0;
            string prefix = "";
            for(auto &ch : words[i]){
                prefix+=ch;
                score+=mp[prefix];
            }
            ans[i] = score;
        }

        return ans;
    }
};

// 2nd Solution using trie
// for understanding purposes create tree diagram for the solution


struct trieNode{
    int countP = 0;
    trieNode* children[26];
};

class Solution {
public:
    trieNode* getTrieNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        newNode->countP = 0;
        return newNode;
    }

    void insert(string &word,trieNode* root){
        trieNode* crawl = root;
        
        for(char &ch : word){
            int idx = ch-'a';

            if(!crawl->children[idx]){
                crawl->children[idx] = getTrieNode();
            }
            crawl->children[idx]->countP+=1;
            crawl = crawl->children[idx];
        }
    }

    int getScore(string &word ,trieNode* root){
        int score= 0;
        trieNode* crawl  = root; // "abc"
        for(char &ch : word){
            int idx = ch-'a';
            score+=crawl->children[idx]->countP;
            crawl=crawl->children[idx]; // now i am at "a" wala node;
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int size = words.size();
        trieNode* root = new trieNode();
        
        for(auto &word : words){
            insert(word,root);
        }


        vector<int>result(size,0);
        // result[i] = sum of scores of prefixes of words[i];
        for(int i=0;i<size;i++){

            result[i] = getScore(words[i],root);
        }

        return result;
    }
};