//https://www.codingninjas.com/codestudio/problems/swap-number-without-temporary-variable_893054?topList=cracking-the-coding-interview-questions
/*
x = 10
y = 3

x = x + y (x+y)
y = x - y (x)
x = x - y ( x + y - x = y)


*/

vector<int> swapNumber(int x, int y) {
    // Write your code here.
    x = x+y;
    y = x-y;
    x = x-y;
    vector<int>ans;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
    
}
