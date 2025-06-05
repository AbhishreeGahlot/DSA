class solution
{
    public:
    unordered_map<int, int> m; // key: number, value: index

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (m.count(comp)) {  
                return {m[comp], i};
            }
            m[nums[i]] = i;
        }

        return {}; 
      
};