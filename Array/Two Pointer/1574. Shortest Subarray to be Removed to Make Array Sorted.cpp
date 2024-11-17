/*
Leetcode Link : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        // step 1 - find the jth pointer from right side
        int j = n-1;
        while(j > 0 && arr[j]>=arr[j-1]){
            j--;
        }
        int  i=0;
        int result = j ;// we are remomving all elements left to index j because j to n-1 sorted 

        // step 2 - start finding correct i and j ,find deleted elements = j-i-1;

        while(i<j && (i==0 || arr[i]>=arr[i-1])){ // increasing order from element i 

                // arr[j] < arr[i]
                while(j < n && arr[i]>arr[j]){
                    j++;
                }

                // we have found correct jth element such that arr[i] <= arr[j]
                result = min(result,j-i-1);
                i++;

        } 
        return result;
    }
};