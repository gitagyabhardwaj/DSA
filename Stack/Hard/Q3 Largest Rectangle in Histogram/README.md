# Q3. Largest Rectangle in Histogram

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | November 20, 2026 |
| **Tags** | Array, Stack, Monotonic Stack, Range Minimum/Maximum Query |
| **Link** | [View Problem](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| **Runtime** | 26 ms |
| **Memory** | 81.3 MB |

## Problem Description

<p>Given an array of integers <code>heights</code> representing the histogram's bar height where the width of each bar is <code>1</code>, return <em>the area of the largest rectangle in the histogram</em>.</p>

<p>&nbsp;</p>
<p><span class="float-right -my-0.5 ml-2 inline-flex select-none items-center" data-example-lang-controls=""><span role="group" class="inline-flex h-6 items-center rounded-sd-md bg-sd-muted p-0.5" data-example-lang-toggle=""><button type="button" aria-pressed="false" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-transparent text-sd-muted-foreground hover:text-sd-foreground">Original</button><button type="button" aria-pressed="true" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-sd-border bg-sd-background text-sd-foreground">C++</button></span></span><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg" style="width: 522px; height: 242px;">
<pre><strong>Input:</strong><span class="group relative my-1 flex min-w-0 flex-col rounded-sd-md bg-sd-muted px-3 py-1.5 transition-opacity" data-example-lang-cards=""><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">vector&lt;int&gt; heights = {2, 1, 5, 6, 2, 3};</span><button type="button" aria-label="Copy" title="Copy" class="absolute flex h-[22px] w-[22px] items-center justify-center rounded-[4px] border right-1.5 top-1.5 border-border-quaternary dark:border-border-quaternary bg-layer-02 dark:bg-layer-02 hover:bg-fill-tertiary dark:hover:bg-fill-tertiary focus-visible:opacity-100 [@media(hover:hover)]:opacity-0 [@media(hover:hover)]:group-hover:opacity-100"><div class="relative text-[12px] leading-[normal] p-[1px] before:block before:h-3 before:w-3 h-3.5 w-3.5 text-text-primary dark:text-text-primary"><svg aria-hidden="true" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512" height="1em" width="1em" class="svg-inline--fa fa-clone absolute h-[1em] -translate-x-1/2 -translate-y-1/2 align-[-0.125em] left-1/2 top-1/2"><path fill="currentColor" d="M64 464H288c8.8 0 16-7.2 16-16V384h48v64c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h64v48H64c-8.8 0-16 7.2-16 16V448c0 8.8 7.2 16 16 16zM224 304H448c8.8 0 16-7.2 16-16V64c0-8.8-7.2-16-16-16H224c-8.8 0-16 7.2-16 16V288c0 8.8 7.2 16 16 16zm-64-16V64c0-35.3 28.7-64 64-64H448c35.3 0 64 28.7 64 64V288c0 35.3-28.7 64-64 64H224c-35.3 0-64-28.7-64-64z"></path></svg></div></button></span><strong>Output:</strong> 10
<strong>Explanation:</strong> The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg" style="width: 202px; height: 362px;">
<pre><strong>Input:</strong><span class="group relative my-1 flex min-w-0 flex-col rounded-sd-md bg-sd-muted px-3 py-1.5 transition-opacity" data-example-lang-cards=""><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">vector&lt;int&gt; heights = {2, 4};</span><button type="button" aria-label="Copy" title="Copy" class="absolute flex h-[22px] w-[22px] items-center justify-center rounded-[4px] border right-1.5 top-1.5 border-border-quaternary dark:border-border-quaternary bg-layer-02 dark:bg-layer-02 hover:bg-fill-tertiary dark:hover:bg-fill-tertiary focus-visible:opacity-100 [@media(hover:hover)]:opacity-0 [@media(hover:hover)]:group-hover:opacity-100"><div class="relative text-[12px] leading-[normal] p-[1px] before:block before:h-3 before:w-3 h-3.5 w-3.5 text-text-primary dark:text-text-primary"><svg aria-hidden="true" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512" height="1em" width="1em" class="svg-inline--fa fa-clone absolute h-[1em] -translate-x-1/2 -translate-y-1/2 align-[-0.125em] left-1/2 top-1/2"><path fill="currentColor" d="M64 464H288c8.8 0 16-7.2 16-16V384h48v64c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h64v48H64c-8.8 0-16 7.2-16 16V448c0 8.8 7.2 16 16 16zM224 304H448c8.8 0 16-7.2 16-16V64c0-8.8-7.2-16-16-16H224c-8.8 0-16 7.2-16 16V288c0 8.8 7.2 16 16 16zm-64-16V64c0-35.3 28.7-64 64-64H448c35.3 0 64 28.7 64 64V288c0 35.3-28.7 64-64 64H224c-35.3 0-64-28.7-64-64z"></path></svg></div></button></span><strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= heights[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Segment tree solution, just another idea, O(N*logN) Solution
**Author**: [@xiaohui5319](https://leetcode.com/xiaohui5319/)
**Upvotes**: 187 👍
**Link**: [View Original Post](https://leetcode.com/problems/largest-rectangle-in-histogram/solutions/28941/)

---

Inspired by this solution:
http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/

Just wanna to provide another idea of how to solve this question in O(N*logN) theoretically, 40 ms solution:

    // Largest Rectangle in Histogram
    // Stack solution, O(NlogN) solution
    
    class SegTreeNode {
    public:
      int start;
      int end;
      int min;
      SegTreeNode *left;
      SegTreeNode *right;
      SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
      }
    };
    
    class Solution {
    public:
      int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        // first build a segment tree
        SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);
        // next calculate the maximum area recursively
        return calculateMax(heights, root, 0, heights.size() - 1);
      }
      
      int calculateMax(vector<int>& heights, SegTreeNode* root, int start, int end) {
        if (start > end) {
          return -1;
        }
        if (start == end) {
          return heights[start];
        }
        int minIndex = query(root, heights, start, end);
        int leftMax = calculateMax(heights, root, start, minIndex - 1);
        int rightMax = calculateMax(heights, root, minIndex + 1, end);
        int minMax = heights[minIndex] * (end - start + 1);
        return max( max(leftMax, rightMax), minMax );
      }
      
      SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
        if (start > end) return NULL;
        SegTreeNode *root = new SegTreeNode(start, end);
        if (start == end) {
            root->min = start;
          return root;
        } else {
          int middle = (start + end) / 2;
          root->left = buildSegmentTree(heights, start, middle);
          root->right = buildSegmentTree(heights, middle + 1, end);
          root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
          return root;
        }
      }
      
      int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
        if (root == NULL || end < root->start || start > root->end) return -1;
        if (start <= root->start && end >= root->end) {
          return root->min;
        }
        int leftMin = query(root->left, heights, start, end);
        int rightMin = query(root->right, heights, start, end);
        if (leftMin == -1) return rightMin;
        if (rightMin == -1) return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
      }
    };

</details>
