# 1.
### a)
let $j$ represent the block of text the character is in. For the $i$th character in block $j$, the encryption formula is:
$$Enc(m) = mod_{26}(m+k_i+j)$$
we can use this to determine the decryption function:
$$Dec(c)=mod_{26}(c-k_i-j)$$
### b)
To find key length using index of coincidence:
for the $i$th character of each block $j$, find the probability of that character. We can then use those probabilities to find the index of coincidence with the equation $\sum_{i=0}^{25}p_i^2$. Take the average of the CI's for each $i$ sets of characters, and we have the CI for a block length.
Repeat this process for multiple blocks lengths, and choose the smallest length that gives a value of $\approx0.065$.

