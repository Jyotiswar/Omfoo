public class Solution {

    public int lowerBound(int[] arr, int n, int x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            
            if (x <= arr[m])
                r = m;
            else
                l = m + 1;
        }
            
        return l;
    }

    public int upperBound(int[] arr, int n, int x) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (x >= arr[m])
                l = m + 1;
            else
                r = m;
        }
        
        if (l < n && arr[l] <= x)
            l++;
            
        return l;
    }
    
    public int count(int[] arr, int n, int x) {
        int start = lowerBound(arr, n, x);
        if (arr[start] != x)
            return 0;
           
        int last = upperBound(arr, n, x);
        
        return last - start;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] arr = {1, 2, 2, 2, 3, 4, 4, 5};
        int n = arr.length;
        int x = 2;
        
        int count = solution.count(arr, n, x);
        System.out.println("Count of " + x + " in the array: " + count);
    }
}
