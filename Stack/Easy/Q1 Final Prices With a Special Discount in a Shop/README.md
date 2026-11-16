# Q1. Final Prices With a Special Discount in a Shop

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | November 16, 2026 |
| **Tags** | Array, Stack, Monotonic Stack |
| **Link** | [View Problem](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/) |
| **Runtime** | 0 ms |
| **Memory** | 14.1 MB |

## Problem Description

<p>You are given an integer array <code>prices</code> where <code>prices[i]</code> is the price of the <code>i<sup>th</sup></code> item in a shop.</p>

<p>There is a special discount for items in the shop. If you buy the <code>i<sup>th</sup></code> item, then you will receive a discount equivalent to <code>prices[j]</code> where <code>j</code> is the minimum index such that <code>j &gt; i</code> and <code>prices[j] &lt;= prices[i]</code>. Otherwise, you will not receive any discount at all.</p>

<p>Return an integer array <code>answer</code> where <code>answer[i]</code> is the final price you will pay for the <code>i<sup>th</sup></code> item of the shop, considering the special discount.</p>

<p>&nbsp;</p>
<p><span class="float-right -my-0.5 ml-2 inline-flex select-none items-center" data-example-lang-controls=""><span role="group" class="inline-flex h-6 items-center rounded-sd-md bg-sd-muted p-0.5" data-example-lang-toggle=""><button type="button" aria-pressed="true" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-sd-border bg-sd-background text-sd-foreground">Original</button><button type="button" aria-pressed="false" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-transparent text-sd-muted-foreground hover:text-sd-foreground">C++</button></span></span><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> prices = [8,4,6,2,3]
<strong>Output:</strong> [4,2,4,2,3]
<strong>Explanation:</strong> 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> prices = [1,2,3,4,5]
<strong>Output:</strong> [1,2,3,4,5]
<strong>Explanation:</strong> In this case, for all items, you will not receive any discount at all.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> prices = [10,1,1,6]
<strong>Output:</strong> [9,0,1,6]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 500</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 1000</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: explained my c++ solution. Beats 100% in both space and time complexity
**Author**: [@being_bing](https://leetcode.com/being_bing/)
**Upvotes**: 55 👍
**Link**: [View Original Post](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/solutions/691977/)

---

problem is very well documented, at first glance it looks very easy and straightforward, but few minutes into the problem you will realize that, the problem maybe straightforward but solution is not. So first let\'s break down the problem and understand which data-structure to go with for a more clear vision of what\'s happening.

As we can clearly see, the problem is asking us the most recent element on right hand side of the current element which is smaller than or equal to the current element. The problems emphasis is not on the position of the element which we would be using as discount, but rather on it\'s value and the fact that how recently the element is introduced in our process.

So, when an elements recentness (i don\'t know if it is an actual word) make it more eligible, the best data-structure we have for this kind of scenarios is stack. So let\'s go with the stack and try to formulate an algorithm.

Algorithm -
* iterate from right-to-left on the given \'prices\' array.
	->  if stack is empty. No discount on current item (discount = 0). Just push current_item to stack.
	-> if stack is NOT empty. check top of stack.
	.........=> if top <= curr_item, then top is our discount, record it, then push current_item to stack.
	.........=> if top > curr_item, keep popping stack until we get a top which is <= current_item. if stack becomes empty, then no discount on current_item.
	-> we have our discount value for each item in \'prices\' array ready.
* create an selling_price array such that, selling_price[i] = prices[i] - discount[i].
* selling_price is our answer.

```
vector<int> finalPrices(vector<int>& prices) {
        stack<int> minStk;
        int n = prices.size();
        vector<int> discount(n, 0);
        for (int i{n-1}; i>=0; i--) {
            if (!minStk.empty())
                if (minStk.top() <= prices[i])
                    discount[i] = minStk.top();
                else {
                    while (!minStk.empty() && (minStk.top() > prices[i])) minStk.pop();
                    if (!minStk.empty()) discount[i] = minStk.top();
                }
            minStk.push(prices[i]);
        }
        vector<int> selling_price(n);
        for (int i{0}; i<n; i++)
            selling_price[i] = prices[i] - discount[i];
        return selling_price;
    }
```

if you think that i missed something, or want me to explain it even further using other possible approaches then comment down below and i will do that.

</details>
