//https://www.codingninjas.com/codestudio/problems/boyer-moore-for-pattern-searching_1229066?topList=cracking-the-coding-interview-questions
/*
aba,baa,aaa,bb

aba
baa
aba



aba,baa,ab,ba,aa

1->a,b,c  
2->ab,bc
3->abc,def
4->abcd,efha


abcd,efha   ea,fb,hc,ad,ab,bc

efha
abcd

abcd
abcd

ab
ba
aa


ab ac abc

abc
aba
cab

abc,adc,aaa,afg
0.   1.   2.  3

abc
adc
aaa
afg

aa
*/

#include<unordered_map>

bool check(vector<string>&rectangle,vector<string> &wordList1,unordered_map<string,int>&wordList2Map,int index,int w,int l,int count){
    //base cases
    if(count==w){
        //check if valid rectangle
        //word along each column should be there in list2
        
        for(int i=0;i<rectangle[0].size();i++){
            string temp="";
            for(int j=0;j<rectangle.size();j++){
                temp+=rectangle[j][i];
            }
            //cout<<temp<<endl;
            //check if temp im list2
            bool present = false;
            if(wordList2Map.find(temp)!=wordList2Map.end()){
                present = true;
            }
            
            if(present==false){
                return false;
            }
        
        }
        
        //if reached here means valid
        return true;
        
    }
    if(index>=wordList1.size()){
        return false;
    }
    //add current word
   
    rectangle.push_back(wordList1[index]);
    bool inc = check(rectangle,wordList1,wordList2Map,index,w,l,count+1);
    //skip curr word
    rectangle.pop_back();
    bool exc = check(rectangle,wordList1,wordList2Map,index+1,w,l,count);
    
    return inc||exc;
}

bool isValidRectangle(int l,int w,vector<string> &wordList1,vector<string> &wordList2){
    int nLen = wordList1.size();
    int nWid = wordList2.size();
    //choose w words from list1
    vector<string>rectangle;
	unordered_map<string,int>wordList2Map;
    
    for(auto &word:wordList2){
        wordList2Map[word] = 1;
    }
    
    return check(rectangle,wordList1,wordList2Map,0,w,l,0);
	
}
int wordRectangle(vector<string> &words)
{
	// Write your code here.
    int i,j,n,k,minLen,maxLen;
    
    //length to words of that length
    unordered_map<int,vector<string>>lenMap;
    minLen = words[0].length();
    maxLen = words[0].length();
    
    for(auto &word:words){
        int len = word.length();
        minLen = min(minLen,len);
        maxLen = max(maxLen,len);
        lenMap[len].push_back(word);
    }
    int maxArea = 0;
    
    for(i=maxLen;i>=minLen;i--){
        for(j=maxLen;j>=minLen;j--){
            //check if rectangle possible
            if(lenMap[i].size()==0 || lenMap[j].size()==0){
                continue;
            }
            
            if(i*j>maxArea){
                //rectangle with length i,width j
               // bool isValid = true;
               bool isValid = isValidRectangle(i,j,lenMap[i],lenMap[j]);
                if(isValid){
                    maxArea = i*j;
                }
            }
            
            
        }
    }
    
    return maxArea;
    
    
    
}
