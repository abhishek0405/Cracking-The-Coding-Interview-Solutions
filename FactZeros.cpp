/*
0->1
1->1
2->2
3->6
4->24
5->120
6->720
7-> 1 
8->1
9->1
10! ->2

11*12*13*14*15
*/
int trailingZerosInFactorial(int n)
{
	// Write your code here.
    int ans = 0;
    int t = 5;
    while(t<=n){
        ans+=n/t;
        t*=5;
    }
    return ans;
}
