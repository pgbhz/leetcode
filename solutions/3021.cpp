/*
Alice and Bob playing flower game?
That's greedy, for sure. Think twice.
Double-checking: there isn't a true notion of space. Just the 2 lanes, but we
can consider each lane as like a honeypot. We have to run some sort of
simulation here. Alternating turns. Ok, I've got the general gist of it.

    - alice plays first
    - whoever picks the last flower of a lane, wins.
        - or better, if there is only one flower in lane x or y, the person wins

We are given (n, m)
We want the number of possible pairs (x, y) such that alice wins with:
    x flowers in the first lane where x in [1, n]
    y flowers in the first lane where x in [1, m]
But, of course, we will always have like (1, y) or (x, 1). Why?
Because the winning condition is to be able to pick the last flower of a lane.
Cool. I think we're able to simulate this now.
Remeber that we need to return the number of possible pairs. The number. The
cardinality. I think there is some component of DP here. Maybe. Read the test
cases. You wasted like 15 minutes. 18. Apparently, the idea of the problem is
some sort of symmetry inferring thing. Ok. We know then that (i, j) is a winning
game iff xor(i,j) is odd. Cool. But a nested loop won't pass. Why? A typical CPU
can perform around 10^8 operations per second. Therefore, 10^10 operations would
take approximately 10^10 / 10^8 = 100 seconds. This is significantly longer than
the typical time limit for competitive programming problems, which is usually
1-2 seconds. Dude, seriously. Take a look at the function signature. It is
returning a long long. Why would you then return an INT????????
*/

class Solution {
public:
    long long flowerGame(int n, int m) {
        // my ant-brain solution
        // long long total_winning_scenarios = 0;

        // long long odds_in_n = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
        // long long odds_in_m = (m % 2 == 0) ? (m / 2) : (m / 2 + 1);

        // total_winning_scenarios += odds_in_n * (m / 2);
        // total_winning_scenarios += (n / 2) * odds_in_m;

        // return total_winning_scenarios;
        
        return (long long)m*n/2;    // thank you, herr Deng
    }
};
