//https://www.codingninjas.com/codestudio/problems/compress-the-string_893402?topList=cracking-the-coding-interview-questions
/*
abaabbddccc
a 1
b 1
a

*/

string compressTheString(string &s)
{
	// Write your code here
    string ans = "";
    char currChar = s[0];
    int currCount = 1;
    for(int i=1;i<s.length();i++){
        if(s[i]==currChar){
            currCount++;
        }
        else{
            ans+=currChar;
            if(currCount!=1){
              ans+=to_string(currCount);
            }
            currChar = s[i];
            currCount = 1;
            
        }
    }
    //last character might have been excluded
    ans+=currChar;
    if(currCount!=1){
        ans+=to_string(currCount);
    }
    
    return ans;
}
