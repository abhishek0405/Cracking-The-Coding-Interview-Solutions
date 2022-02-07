//https://www.codingninjas.com/codestudio/problems/swap-adjacent-bit-pairs_1262378?topList=cracking-the-coding-interview-questions
/*

101101

 011110

get ith bit(even) and i+1 bit,swap them
make i as i+2
*/
int swapAdjacentBits(int n)
{ 
    // Write your code here
    int i;
    //swap 31,30 then 29,28 then 27,26 .... then 1,0
    for(i=31;i>=1;i-=2){
        //get ith bit
        int oddBit = (n>>i)&1;
        int evenBit = (n>>(i-1))&1;
        
        if(oddBit == 0 && evenBit == 1){
            //set oddBit ie ith as 1
            n = n | (1<<i);
            //set evenBit ie i-1 bit as 0
            n = n & ~(1<<(i-1));
                
        }
        
        else if(oddBit == 1 && evenBit == 0){
            //set oddBit as 0
            n = n & ~(1<<i);
            //set evenBit(i-1) as 1
            
            n = n | (1<<(i-1));
        }
    }
    
    return n;

}
