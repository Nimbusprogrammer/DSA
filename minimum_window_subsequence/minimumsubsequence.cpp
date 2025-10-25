#include <bits/stdc++.h>
using namespace std;
string minWindow(string S, string T) {
    int n = S.size(), m = T.size();
    int minLen = INT_MAX, start = -1;

    // Step 1: Go through every character in S
    for (int i = 0; i < n; i++) {

        // Only start checking when S[i] == first char of T
        if (S[i] == T[0]) {
            int s = i;   // pointer in S
            int t = 0;   // pointer in T

            // Step 2: Move forward to find a full subsequence
            while (s < n && t < m) {
                if (S[s] == T[t]) t++;
                s++;
            }

            // Step 3: If full T found in S
            if (t == m) {
                int end = s - 1; // mark where subsequence ends
                t = m - 1;
                s = end;

                // Step 4: Move backward to shrink window
                while (s >= i && t >= 0) {
                    if (S[s] == T[t]) t--;
                    s--;
                }

                s++; // adjust since loop overshoots one step

                int len = end - s + 1;

                // Step 5: Update minimum window if smaller
                if (len < minLen) {
                    minLen = len;
                    start = s;
                }
            }
        }
    }

    // Step 6: Returnk result
    if (start == -1) return "";
    return S.substr(start, minLen);
}