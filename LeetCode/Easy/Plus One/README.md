# Plus One

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 11, 2026 |
| **Tags** | Array, Math |
| **Link** | [View Problem](https://leetcode.com/problems/plus-one/) |
| **Runtime** | 0 ms |
| **Memory** | 11.7 MB |

## Problem Description

<p>You are given a <strong>large integer</strong> represented as an integer array <code>digits</code>, where each <code>digits[i]</code> is the <code>i<sup>th</sup></code> digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading <code>0</code>'s.</p>

<p>Increment the large integer by one and return <em>the resulting array of digits</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> digits = [1,2,3]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong> The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> digits = [4,3,2,1]
<strong>Output:</strong> [4,3,2,2]
<strong>Explanation:</strong> The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> digits = [9]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li><code>digits</code> does not contain any leading <code>0</code>'s.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ Simple [C++] solution with good explanation.
**Author**: [@AbdalrahmanShaban](https://leetcode.com/AbdalrahmanShaban/)
**Upvotes**: 1008 👍
**Link**: [View Original Post](https://leetcode.com/problems/plus-one/solutions/3054321/)

---

# Intuition
If we thought that all elements of the vector is a number we need to increase it by 1. The input can be 100 digits so we must handle that through digits.

# Approach
First we increment the first digit (last element) by 1, if it becomes 10 we make it 0 ans add 1 to the second digit.. until the last digit (first element), if it becoms 10 we make it 1 and push_back a leading zero.

# Complexity
- Time complexity:
O(n)


# Code
```
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};
```

Don\'t forget please :\')

![UPVOTE.jpg](https://assets.leetcode.com/users/images/a6b046f8-0b13-4de1-95f9-78327b0dccba_1673782056.4431267.jpeg)


</details>
