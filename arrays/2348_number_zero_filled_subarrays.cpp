/*
Do we see some fancy pattern here?
Can we grow the array of 0s and try to find them inside the nums array?
    That's one approach, but how bad is it?
    It is at least quadratic.
Is there something better?
    Does backtracking apply here? How would that be? Dynamic programming? Not really, no. At least doesn't look like it.
    Any useful data structure?
    This feels like a sliding window problem. Prefix array? Not quite.
    If I were to guess, sliding window would be that guess.
    What is sliding window but a fancy name for two pointers?
    Ok, I've got the gist of it.
    We iterate through the array.
    For each position, we try to increase a 0-array starting there.
    What's the complexity of that? Well, subquadratic, I would say.
    That is apparently not enough. TLE.
    Feels like previous explorations to the right should be scavanged.
    Suppose we see 0 0 0.
    We then know, starting from the first 0, that there are 3 arrays ([0], [0, 0], [0, 0, 0]).
    Is there some mathematical formulation that, given a consecutive array of 0's, gives us the number of
    subarrays? Yes, the power set formula. 2^(n-1) if I'm not wrong.

    [1,3,0,0,2,0,0,4]
         2 3 4

    [0,0,0,2,0,0]   size = 6
     0 1 2 3
     a b c                      -> a b c a,b b,c a,b,c
             4 5 6
     count += 2^3 - 1 = 7
     count += 2^2 - 1 = 3

    a 
    b
    c
    a,b
    b,c
    a,c <-------- ok, here's our problem. How de compensate for that?
    a,b,c


    0 0 0 <- 1, the extremities
    0 0 0 0 <- 1
    0 0 0 0 0 <- 2
    0 0 0 0 0 0 <- 2 ? What about inner extremities ? God help me.

    If you have a sequence of n zeros, how many contiguous subarrays can you form?

    n subarrays of length 1
    n-1 of 2
    n-2 of 3
    n-(n+1) of n -> 1 of n
    Is this the gaussian sum?
    n (n + 1) / 2 -> 3(3+1)/2 = 6

    n2 / 2 + n / 2
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long count = 0;
        int i = 0;
        while (i < nums.size()) {
            int j = i;
            while (j < nums.size() && nums[j] == 0) {
                j++;
            }
            if (j != i) {
                long n = (j - i);
                count += n * (n + 1) / 2;
            }
            i = j+1;
        }
        return count;
    }
};
