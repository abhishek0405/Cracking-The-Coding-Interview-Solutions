//https://www.codingninjas.com/codestudio/problems/search-in-a-row-wise-and-column-wise-sorted-matrix_839811?topList=cracking-the-coding-interview-questions
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    int i,j;
    int n = matrix[0].size();
    i = 0;
    j = n-1;
    while(i<n && j>=0){
        if(matrix[i][j]==x){
            return make_pair(i,j);
        }
        else if(matrix[i][j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    return make_pair(-1,-1);
    
}
