/*
    Time Complexity : O(M * log(N))
    Space Complexity : O(N)

    Where 'M' and 'N' are size of 'large' and 'small' array.
*/

#include <map>

int shortestSupersequence(vector < int > & large, vector < int > & small, int m, int n) {
    
    // Initializing a hash map to store count of elements in 'small' array.
    map < int, int > count;

    // Set values of 'small' array as keys of 'count'.
    for (int i = 0; i < n; i++) {
        count[small[i]] = 0;
    }

    /*
        Variable to store count of elements required to find to complete super
        sequence.
    */
    int toFind = n;

    // Index to start and end of supersequence.
    int left = 0, right = 0;

    // Stores the result.
    int res = INT_MAX;

    while (left <= right && right < m) {
        
        // Incrementing right until toFind>0 and right<M.
        while (toFind > 0 && right < m) {
            /*
                If element of 'small' array is found i.e if
                element is present in count hashmap.
            */
            if (count.find(large[right]) != count.end()) {
                // Decrementing 'toFind' if count of current element is '0'.
                if (count[large[right]] == 0) {
                    toFind--;
                }

                // Incrementing count.
                count[large[right]]++;
            }

            // Incrementing right.
            right++;
        }

        // Break the loop if toFind > 0.
        if (toFind != 0) {
            break;
        }

        // Incrementing left until toFind =0 and left<right.
        while (toFind == 0 && left < right) {
            // Update res.
            res = min(res, right - left);

            if (count.find(large[left]) != count.end()) {
                { // Decrementing count .
                    count[large[left]]--;
                }

                // If count becomes '0', increment 'toFind'.
                if (count[large[left]] == 0) {
                    toFind++;
                }
            }

            // Increment left.
            left++;
        }
    }

    // Return res.
    if (res != INT_MAX) {
        return res;
    }

    // If no supersequence found, return -1.
    else {
        return -1;
    }
}
