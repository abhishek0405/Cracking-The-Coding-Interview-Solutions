https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?topList=cracking-the-coding-interview-questions
/*
1 1 2 3 5
0 1 2 3 4 5 6 

n=4
2,1
n=3
3,2
n=2
5,3
n=1
8 5

f(n)     [1 1]  f(n-1)
f(n-1)   [1 0]  f(n-2)

f(n)    [1 1]^n-1   f(1)=1
f(n-1)  [1 0]       f(0)=1

[1 1]^n-1
[1 0]

a b   1
c d   1

pow,n-1

1 1 2 3 4 5 


a b  1 2 
c d  3 4
*/
#define MOD 1000000007

void multiply(long long matrix1[2][2],long long matrix2[2][2]){
    
    long long a = ((matrix1[0][0]%MOD)*(matrix2[0][0]%MOD))%MOD 
           + (matrix1[0][1]%MOD )* (matrix2[1][0]%MOD)%MOD ;
              
    long long b = ((matrix1[0][0]%MOD)*(matrix2[0][1]%MOD))%MOD 
            + (matrix1[0][1]%MOD )* (matrix2[1][1]%MOD)%MOD ;
               
    long long c = ((matrix1[1][0]%MOD)*(matrix2[0][0]%MOD))%MOD 
            + (matrix1[1][1]%MOD )* (matrix2[1][0]%MOD)%MOD ;
               
    long long d = ((matrix1[1][0]%MOD)*(matrix2[0][1]%MOD))%MOD 
             + (matrix1[1][1]%MOD )* (matrix2[1][1]%MOD)%MOD ;
                
    matrix1[0][0] = a%MOD;
    matrix1[0][1] = b%MOD;
    matrix1[1][0] = c%MOD;             
    matrix1[1][1] = d%MOD;
    
}

void power(long long matrix[2][2],long long n){
    //base cases
    if(n==0 || n==1){
        return;
    }
    long long base[2][2] = {{1,1},
                        {1,0}};
    power(matrix,n/2);
    multiply(matrix,matrix);
    if(n%2!=0){
        multiply(matrix,base);
    }
    
}

int countDistinctWayToClimbStair(long long nStairs)
{
    //  Write your code here.
    long long matrix[2][2] = {{1,1},
                        {1,0}};
    if(nStairs==0 ||nStairs==1){
        return 1;
    }
    power(matrix,nStairs-1);
    return (matrix[0][0]%MOD + matrix[0][1]%MOD)%MOD;
}
