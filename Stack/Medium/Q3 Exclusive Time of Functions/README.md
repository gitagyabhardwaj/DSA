# Q3. Exclusive Time of Functions

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | November 16, 2026 |
| **Tags** | Array, Stack |
| **Link** | [View Problem](https://leetcode.com/problems/exclusive-time-of-functions/) |
| **Runtime** | 18 ms |
| **Memory** | 23.1 MB |

## Approach

horrible time complexity

## Problem Description

<p>On a <strong>single-threaded</strong> CPU, we execute a program containing <code>n</code> functions. Each function has a unique ID between 0 and <code>n - 1</code>.</p>

<p>Function calls are <strong>stored in a <a href="https://en.wikipedia.org/wiki/Call_stack">call stack</a></strong>: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is <strong>the current function being executed</strong>. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.</p>

<p>You are given a list <code>logs</code>, where <code>logs[i]</code> represents the <code>i<sup>th</sup></code> log message formatted as a string <code>"{function_id}:{"start" | "end"}:{timestamp}"</code>. For example, <code>"0:start:3"</code> means a function call with function ID 0 <strong>started at the beginning</strong> of timestamp 3, and <code>"1:end:2"</code> means a function call with function ID 1 <strong>ended at the end</strong> of timestamp 2. Note that a function can be called <b>multiple times, possibly recursively</b>.</p>

<p>A function's <strong>exclusive time</strong> is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the <strong>exclusive time</strong> is <code>2 + 1 = 3</code>.</p>

<p>Return <em>the <strong>exclusive time</strong> of each function in an array, where the value at the </em><code>i<sup>th</sup></code><em> index represents the exclusive time for the function with ID </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><span class="float-right -my-0.5 ml-2 inline-flex select-none items-center" data-example-lang-controls=""><span role="group" class="inline-flex h-6 items-center rounded-sd-md bg-sd-muted p-0.5" data-example-lang-toggle=""><button type="button" aria-pressed="false" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-transparent text-sd-muted-foreground hover:text-sd-foreground">Original</button><button type="button" aria-pressed="true" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-sd-border bg-sd-background text-sd-foreground">C++</button></span></span><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/05/diag1b.png" style="width: 550px; height: 239px;">
<pre><strong>Input:</strong><span class="group relative my-1 flex min-w-0 flex-col rounded-sd-md bg-sd-muted px-3 py-1.5 transition-opacity" data-example-lang-cards=""><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">int n = 2;</span><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">vector&lt;string&gt; logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};</span><button type="button" aria-label="Copy" title="Copy" class="absolute flex h-[22px] w-[22px] items-center justify-center rounded-[4px] border right-1.5 top-1.5 border-border-quaternary dark:border-border-quaternary bg-layer-02 dark:bg-layer-02 hover:bg-fill-tertiary dark:hover:bg-fill-tertiary focus-visible:opacity-100 [@media(hover:hover)]:opacity-0 [@media(hover:hover)]:group-hover:opacity-100"><div class="relative text-[12px] leading-[normal] p-[1px] before:block before:h-3 before:w-3 h-3.5 w-3.5 text-text-primary dark:text-text-primary"><svg aria-hidden="true" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512" height="1em" width="1em" class="svg-inline--fa fa-clone absolute h-[1em] -translate-x-1/2 -translate-y-1/2 align-[-0.125em] left-1/2 top-1/2"><path fill="currentColor" d="M64 464H288c8.8 0 16-7.2 16-16V384h48v64c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h64v48H64c-8.8 0-16 7.2-16 16V448c0 8.8 7.2 16 16 16zM224 304H448c8.8 0 16-7.2 16-16V64c0-8.8-7.2-16-16-16H224c-8.8 0-16 7.2-16 16V288c0 8.8 7.2 16 16 16zm-64-16V64c0-35.3 28.7-64 64-64H448c35.3 0 64 28.7 64 64V288c0 35.3-28.7 64-64 64H224c-35.3 0-64-28.7-64-64z"></path></svg></div></button></span><strong>Output:</strong> [3,4]
<strong>Explanation:</strong>
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong><span class="group relative my-1 flex min-w-0 flex-col rounded-sd-md bg-sd-muted px-3 py-1.5 transition-opacity" data-example-lang-cards=""><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">int n = 1;</span><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">vector&lt;string&gt; logs = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};</span><button type="button" aria-label="Copy" title="Copy" class="absolute flex h-[22px] w-[22px] items-center justify-center rounded-[4px] border right-1.5 top-1.5 border-border-quaternary dark:border-border-quaternary bg-layer-02 dark:bg-layer-02 hover:bg-fill-tertiary dark:hover:bg-fill-tertiary focus-visible:opacity-100 [@media(hover:hover)]:opacity-0 [@media(hover:hover)]:group-hover:opacity-100"><div class="relative text-[12px] leading-[normal] p-[1px] before:block before:h-3 before:w-3 h-3.5 w-3.5 text-text-primary dark:text-text-primary"><svg aria-hidden="true" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512" height="1em" width="1em" class="svg-inline--fa fa-clone absolute h-[1em] -translate-x-1/2 -translate-y-1/2 align-[-0.125em] left-1/2 top-1/2"><path fill="currentColor" d="M64 464H288c8.8 0 16-7.2 16-16V384h48v64c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h64v48H64c-8.8 0-16 7.2-16 16V448c0 8.8 7.2 16 16 16zM224 304H448c8.8 0 16-7.2 16-16V64c0-8.8-7.2-16-16-16H224c-8.8 0-16 7.2-16 16V288c0 8.8 7.2 16 16 16zm-64-16V64c0-35.3 28.7-64 64-64H448c35.3 0 64 28.7 64 64V288c0 35.3-28.7 64-64 64H224c-35.3 0-64-28.7-64-64z"></path></svg></div></button></span><strong>Output:</strong> [8]
<strong>Explanation:</strong>
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at the beginning of time 6 and executes for 1 unit of time.
Function 0 (initial call) resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time executing.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong><span class="group relative my-1 flex min-w-0 flex-col rounded-sd-md bg-sd-muted px-3 py-1.5 transition-opacity" data-example-lang-cards=""><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">int n = 2;</span><span class="min-w-0 overflow-x-auto whitespace-pre py-0.5 pr-8 font-menlo text-xs font-normal leading-5 text-sd-foreground">vector&lt;string&gt; logs = {"0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"};</span><button type="button" aria-label="Copy" title="Copy" class="absolute flex h-[22px] w-[22px] items-center justify-center rounded-[4px] border right-1.5 top-1.5 border-border-quaternary dark:border-border-quaternary bg-layer-02 dark:bg-layer-02 hover:bg-fill-tertiary dark:hover:bg-fill-tertiary focus-visible:opacity-100 [@media(hover:hover)]:opacity-0 [@media(hover:hover)]:group-hover:opacity-100"><div class="relative text-[12px] leading-[normal] p-[1px] before:block before:h-3 before:w-3 h-3.5 w-3.5 text-text-primary dark:text-text-primary"><svg aria-hidden="true" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512" height="1em" width="1em" class="svg-inline--fa fa-clone absolute h-[1em] -translate-x-1/2 -translate-y-1/2 align-[-0.125em] left-1/2 top-1/2"><path fill="currentColor" d="M64 464H288c8.8 0 16-7.2 16-16V384h48v64c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V224c0-35.3 28.7-64 64-64h64v48H64c-8.8 0-16 7.2-16 16V448c0 8.8 7.2 16 16 16zM224 304H448c8.8 0 16-7.2 16-16V64c0-8.8-7.2-16-16-16H224c-8.8 0-16 7.2-16 16V288c0 8.8 7.2 16 16 16zm-64-16V64c0-35.3 28.7-64 64-64H448c35.3 0 64 28.7 64 64V288c0 35.3-28.7 64-64 64H224c-35.3 0-64-28.7-64-64z"></path></svg></div></button></span><strong>Output:</strong> [7,1]
<strong>Explanation:</strong>
Function 0 starts at the beginning of time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at the beginning of time 2 and executes for 4 units of time.
Function 0 (initial call) resumes execution then immediately calls function 1.
Function 1 starts at the beginning of time 6, executes 1 unit of time, and ends at the end of time 6.
Function 0 resumes execution at the beginning of time 7 and executes for 1 unit of time.
So function 0 spends 2 + 4 + 1 = 7 units of total time executing, and function 1 spends 1 unit of total time executing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>2 &lt;= logs.length &lt;= 500</code></li>
	<li><code>0 &lt;= function_id &lt; n</code></li>
	<li><code>0 &lt;= timestamp &lt;= 10<sup>9</sup></code></li>
	<li>No two start events will happen at the same timestamp.</li>
	<li>No two end events will happen at the same timestamp.</li>
	<li>Each function has an <code>"end"</code> log for each <code>"start"</code> log.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Solution in C++
**Author**: [@ashish_madhup](https://leetcode.com/ashish_madhup/)
**Upvotes**: 12 👍
**Link**: [View Original Post](https://leetcode.com/problems/exclusive-time-of-functions/solutions/3225725/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int,int>> cur;
        int prevTime = 0;
        for (auto& s : logs){
            int num = stoi(s.substr(0, s.find(\':\')));
            int time = stoi(s.substr(s.rfind(\':\') + 1));
            if (s.find(\'e\') != -1){
                ans[num] += time - prevTime + 1;
                cur.pop();
                prevTime = time + 1;
            }
            else{
                if (!cur.empty()) ans[cur.top().first] += time - prevTime ;
                cur.push({num, time});
                prevTime = time;
            }
        }
        return ans;
    }
};
```

</details>
