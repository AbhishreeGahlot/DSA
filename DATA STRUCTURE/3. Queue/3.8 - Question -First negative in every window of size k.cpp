First negative in every window of size k
Difficulty: MediumAccuracy: 48.61%Submissions: 168K+Points: 4
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.
Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
code :
class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        deque<int>dq;
        vector<int>ans;
        
        //process first window of k size
        for(int i =0;i<k;i++)
        {
            if(arr[i]<0)
            {
                dq.push_back(i);
            }
            
        }
        //store ans of first k sized window
        if(dq.size()>0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        //process for remaining element
        for(int i=k;i<arr.size();i++)
        {//removal
            if(!dq.empty()&&i-dq.front()>=k)
            {
                dq.pop_front();
           }
        
        
        //add element
        if(arr[i]<0)
        {
            dq.push_back(i);
        }
        if(dq.size()>0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }}
        return ans;
    }};


    explaination 
    Let’s perform a **dry run** of the code for the input:

### **Input:**
```cpp
arr = [12, -1, -7, 8, -15, 30, 16, 28];
k = 3;
```

---

### **Initial Setup:**
- `dq` (deque): `[]` (empty initially)
- `ans` (result): `[]` (empty initially)

---

### **Process the First Window** (\( i = 0 \) to \( i = 2 \)):

#### \( i = 0 \):
- `arr[0] = 12`, not negative → Do nothing.
- `dq`: `[]`

#### \( i = 1 \):
- `arr[1] = -1`, negative → Add index \( 1 \) to `dq`.
- `dq`: `[1]`

#### \( i = 2 \):
- `arr[2] = -7`, negative → Add index \( 2 \) to `dq`.
- `dq`: `[1, 2]`

#### After processing the first window:
- The first negative integer is at index `dq.front() = 1` → Add `arr[1] = -1` to `ans`.
- `ans`: `[-1]`

---

### **Process Remaining Elements** (\( i = 3 \) to \( i = 7 \)):

#### **Window 2: \( i = 3 \)**
- **Remove out-of-window indices:**
  - \( dq.front() = 1 \), still in the window → Do nothing.
- **Add current element:**
  - `arr[3] = 8`, not negative → Do nothing.
- **Result for this window:**
  - First negative integer is at index `dq.front() = 1` → Add `arr[1] = -1` to `ans`.
- `ans`: `[-1, -1]`

---

#### **Window 3: \( i = 4 \)**
- **Remove out-of-window indices:**
  - \( dq.front() = 1 \), now out of the window → Remove index \( 1 \) from `dq`.
  - `dq`: `[2]`
- **Add current element:**
  - `arr[4] = -15`, negative → Add index \( 4 \) to `dq`.
  - `dq`: `[2, 4]`
- **Result for this window:**
  - First negative integer is at index `dq.front() = 2` → Add `arr[2] = -7` to `ans`.
- `ans`: `[-1, -1, -7]`

---

#### **Window 4: \( i = 5 \)**
- **Remove out-of-window indices:**
  - \( dq.front() = 2 \), now out of the window → Remove index \( 2 \) from `dq`.
  - `dq`: `[4]`
- **Add current element:**
  - `arr[5] = 30`, not negative → Do nothing.
- **Result for this window:**
  - First negative integer is at index `dq.front() = 4` → Add `arr[4] = -15` to `ans`.
- `ans`: `[-1, -1, -7, -15]`

---

#### **Window 5: \( i = 6 \)**
- **Remove out-of-window indices:**
  - \( dq.front() = 4 \), still in the window → Do nothing.
- **Add current element:**
  - `arr[6] = 16`, not negative → Do nothing.
- **Result for this window:**
  - First negative integer is at index `dq.front() = 4` → Add `arr[4] = -15` to `ans`.
- `ans`: `[-1, -1, -7, -15, -15]`

---

#### **Window 6: \( i = 7 \)**
- **Remove out-of-window indices:**
  - \( dq.front() = 4 \), now out of the window → Remove index \( 4 \) from `dq`.
  - `dq`: `[]`
- **Add current element:**
  - `arr[7] = 28`, not negative → Do nothing.
- **Result for this window:**
  - `dq` is empty → Add `0` to `ans`.
- `ans`: `[-1, -1, -7, -15, -15, 0]`

---

### **Final Output:**
The result is:
```cpp
ans = [-1, -1, -7, -15, -15, 0];
```

---

### **Key Observations:**
- The deque efficiently keeps track of relevant indices for each window.
- Each element is processed only once, ensuring \( O(n) \) time complexity.
