//https://www.codingninjas.com/codestudio/problems/find-all-occurrences-of-multiple-patterns_1229504?topList=cracking-the-coding-interview-questions
/*
cc aa bb

aabbccaa
01234567


eeee
abcdeeeeeeee

eaab
abcdeaabhfeaabfeaageaababc


*/
vector<vector<int>> findOccurrences(string &s,vector<string> &arr)
{
    // Write your code here.
    int i,j,k,n;
    vector<vector<int>>ans;
    vector<int>temp;
    n = arr.size();
    string word;
    
    for(i=0;i<n;i++){
        //clear the vector
        temp = {};
        word = arr[i];
        //find all occurences of word in s
        int wordIndex = 0;
        int sIndex = 0;
        int wordLen = word.length();
        int sLen = s.length();
        int swapIndex;
        bool flag;
        //cout<<word<<endl;
        while(sIndex < sLen){
            if(flag == 0 && s[sIndex] == word[0]){
                swapIndex = wordIndex;
                flag = 1;
            }
            if(s[sIndex]==word[wordIndex]){
                sIndex++;
                wordIndex++;
            }
            else{
                sIndex++;
                wordIndex = 0;
            }
            //found a word
            if(wordIndex == wordLen){
                flag = 0;
                int startIndex = sIndex - wordLen;
                temp.push_back(startIndex);
                wordIndex = 0;
                //now take sIndex to first occurence of first character after curr sIndex
                startIndex = swapIndex;
            }
            
        }
        ans.push_back(temp);
    }
    
    return ans;
  
    
    
}
