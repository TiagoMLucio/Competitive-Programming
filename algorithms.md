## Number Theory

### Chicken McNugget Theorem

For any two relatively prime positive integers $m,n$, the greatest integer that cannot be written in the form $am + bn$ for nonnegative integers $a, b$ is $mn-m-n$. 

## String

### Manacher Algorithm

Find all palindromes of a string in O(n)

### Knuth–Morris–Pratt algorithm

Searches for occurrences of a word in a string in O(n) 

### [Z-Function](https://cp-algorithms.com/string/z-function.html)

$z[i]$ is the length of the longest string that is, at the same time, a prefix of  $s$  and a prefix of the suffix of $s$ starting at $i$.

```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
```