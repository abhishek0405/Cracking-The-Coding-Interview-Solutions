//https://www.codingninjas.com/codestudio/problems/phone-code_1230549?topList=cracking-the-coding-interview-questions
/*
2633

a

used code ride tree boed
 solve(index,letters,set,ans,len);
*/
#include<unordered_set>

class Node{
    public:
    Node* links[26];
    //tells whether end of word
    bool flag;
    
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        flag = false;
    }
    
  	bool isPresent(char ch){
      return links[ch-'a'] != NULL;
    }
    
    void addChar(char ch,Node* newNode){
        links[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    
    bool getFlag(){
        return flag;
    }
    
    void setFlag(bool val){
        flag = val;
    }
    
};


class Trie {
    
    Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
		root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
		for(int i=0;i<word.length();i++){
            //if letter not present,add it
            if(!curr->isPresent(word[i])){
                curr->addChar(word[i],new Node());
            }
            
            curr = curr->getNext(word[i]);
            
        }
        
        //word ended
        curr->setFlag(true);
        
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		 Node *curr = root;
		for(int i=0;i<word.length();i++){
            
            if(!curr->isPresent(word[i])){
                return false;
            }
            
            curr = curr->getNext(word[i]);
            
        }
        //if word present, then flag true
        //if word like substring, then flag will be false
        return curr->getFlag();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
	    Node *curr = root;
		for(int i=0;i<prefix.length();i++){
            
            if(!curr->isPresent(prefix[i])){
                return false;
            }
            
            curr = curr->getNext(prefix[i]);
            
        }
        // if we reach here,means start prefix always there
        return true;
        
    }
    
};

void getWords(int index,vector<string>&letters,Trie &trie,vector<string>&ans,int len,string curr,string &seq){
    //base cases
    
    if(index==len){
        
        //check if word valid
        
        if(trie.search(curr)){
            ans.push_back(curr);
        }
        return;
    }
    //pick a letter from current number
    int i;
    int currIndex = seq[index] - '0';
    string currLetters = letters[currIndex];
   
    int currLetterLen = currLetters.length();
    
    for(i=0;i<currLetterLen;i++){
        curr.push_back(currLetters[i]);
        //check if any word possible
        if(trie.startsWith(curr)){
            getWords(index+1,letters,trie,ans,len,curr,seq);
        }
       
        curr.pop_back();
    }
    
}
vector<string> phoneCode(vector<string> Words , string & Sequence , int W)
{
	//Write Your Code Here.
    vector<string> letters = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    int index = 0;
    int len = Sequence.length();
    int i,j,k;
  	vector<string>answer;
    for(i=0;i<W;i++){
        string currWord = Words[i];
        if(currWord.length() == len){
           j = 0;
           bool valid = true;
           while(j<len){
               char currLetter = currWord[j];
               int letterIndex = Sequence[j] - '0';
               string letterList = letters[letterIndex];
               bool flag = false;
               //check if currLetter in letter List
               for(k=0;k<letterList.length();k++){
                   if(letterList[k] == currLetter){
                       flag = true;
                   }
               }
               valid = valid && flag;
               j++;
               
           }
            if(valid){
                answer.push_back(currWord);
            }
            
            
        }
       
    }
    return answer;
    
}
