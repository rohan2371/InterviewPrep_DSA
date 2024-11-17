/*
Leetcode Link : https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/
*/

// java code
// t.c : o(log(N))
//s.c : o(n)
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());
        // by default min heap is implemented 
        // if u want max elements to top element -> Collections.reverseOrder()
        for(int i=0;i<nums.length;i++){
            pq.add(nums[i]);
        }

        long ans = 0;
        while(k > 0 ){
            ans+= pq.peek();
            int ceilValue = (int)Math.ceil(pq.poll() / 3.0);
            pq.add(ceilValue);
            k--;
        }

        return ans;

    }
}

// cpp code
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer>pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<nums.length;i++){
            pq.add(nums[i]);
        }

        long ans = 0;
        while(k > 0 ){
            ans+= pq.peek();
            int ceilValue = (int)Math.ceil(pq.poll() / 3.0);
            pq.add(ceilValue);
            k--;
        }

        return ans;

    }
}

