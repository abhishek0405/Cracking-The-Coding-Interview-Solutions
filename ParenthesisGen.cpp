//https://www.codingninjas.com/codestudio/problems/generate-all-parenthesis_920445?topList=cracking-the-coding-interview-questions
/*
()()
(())
((((     ))))

_ _ _ _ _ _ _ _
()()()
(())()
((()))
()(())

(
if o<=c => opening bracket only
else -either opening or closing

()
*/

void solve(vector<string>&ans,string s,int index,int o,int c,int n){
    //base cases
    if(index==2*n){
        ans.push_back(s);
        return;
    }
    
    if(o<=c){
        s[index] = '(';
        solve(ans,s,index+1,o+1,c,n);
    }
    else{
        if(o<n){
            s[index]='(';
            solve(ans,s,index+1,o+1,c,n);
        }
        s[index] = ')';
        solve(ans,s,index+1,o,c+1,n);
    }
    
    
}

vector<string> validParenthesis(int n){
    // Write your code here.
    int o,c;
    o = c = 0;
    vector<string> ans;
    string s(2*n,'a');
    solve(ans,s,0,o,c,n);
    return ans;
}
