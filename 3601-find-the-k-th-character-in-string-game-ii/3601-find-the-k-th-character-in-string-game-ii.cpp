/*

Example Case : 
k = 14
operation = [0,1,0,1]

1 -> "a"
2 -> "aa"
3 -> "aa bb"
4 -> "aabb aabb"
5 -> "aabbaabb bbccbbcc"

how to solve ? 
we need to backtrack from current string to previous string (until k == 1 or initial position) and check whether the operation '1' or '0'
if the operation is equal to 1, that means the current position is shifted by 1 to right
- ex : a to b, b to c, etc.
if the operation is equal to 0, is simply copy the value

Step to solve :
1. find how many jump that we need to reach K, we can use log2(k) function, since every process the string length will be multiple by 2
2. to check the current operation we can use log2(k),if the current operation is equal to 1, that meant the current position is shifted by 1 to right, increase answer value
3. update k postiion to previous value
4. loop process 1 - 3 until k == 1

example : 
k = 14
operations : [0,1,0,1]
1 -> "a"
2 -> "aa"
3 -> "aa bb"
4 -> "aabb aabb"
5 -> "aabbaabb bbccbbcc"

process 1 : 
                   k
s(5) = "aabbaabb|bbccbbcc"
k = 14
jump = 3
prev = 8
new k value = 14 - 8 = 6
operation[jump] = operation[3] = 1 -> increase value
answer = 1

process 2 :
              k
s(4) = "aabb|aabb"
k = 6
jump = 2
prev = 4
new K value = 6 - 4 = 2
operations[jump] = opereations[2] = 0
answer = 1

process 3:
          k 
s(3) = "a|a"
jump = 1
- because k == 2 ^ jump, then we need to decreaes by 1, because the jump should be 0 in here
prev = 1
new k value = 1
operations[jump] = operations[1] = 1
answer = 2

final result : 
'a' + answer = 'c'

why we are using 'a' + answer, is because first step alwasy use 'a'.
*/


class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int answer = 0;

        while(k != 1) {
            long long jump = log2(k);

            // the reason behind of this, is because there is a case where k == 2 ^ log(k)
            // because of that we need to decrease jump value by 1, because our purpose here is to find
            // the previous position of current character
            if ((1LL << jump) == k) jump--;

            long long prev = pow(2, jump);
            k = k - prev;

            // that means we shift the current charater to + 1
            // example a to b, b to c, etc.
            if (operations[jump] == 1) {
                answer++;
            }
        }

        // there is a case when answer > 26, but we only have 26 character
        return 'a' + (answer % 26);
    }
};