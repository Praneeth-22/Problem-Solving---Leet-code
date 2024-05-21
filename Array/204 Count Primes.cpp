//204. Count Primes
//Medium
//Topics
//Companies
//Hint
//Given an integer n, return the number of prime numbers that are strictly less than n.
//
// 
//
//Example 1:
//
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//Example 2:
//
//Input: n = 0
//Output: 0
//Example 3:
//
//Input: n = 1
//Output: 0
// 
//
//Constraints:
//
//0 <= n <= 5 * 106
class Solution {
public:
    int countPrimes(int n) {
        // divisible by  1 and itself
//        if(n <=2) return 0;
//        int res=0;
//        for(int i =2;i<n;i++){
//            int cnt=0;
//            for(int j=2;j<=i;j++){
//                if(i%j ==0) cnt++;
//            }
//            if(cnt == 1) res++;
//            cnt=0;
//        }
//        return res;



        //  Sieve of Eratosthenes algorithm.
  vector<int> isprime(n,0);
        isprime[0] = 1;
        isprime[1] = 1;
        for(int i=2;i<=sqrt(n);i++){
            if(isprime[i] == 0){
                for(int j = i*i;j<n;j+=i){
                    isprime[j] = 1;
                }
            }
        }
        int cnt=0;
        for(auto i:isprime) if(i == 0) cnt++;
        return cnt;
    }
};
