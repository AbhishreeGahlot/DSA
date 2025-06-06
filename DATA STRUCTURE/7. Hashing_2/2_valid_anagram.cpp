// Check whether the given strings are valid anagrams or not 
//  Complexity : tc : O(n) , sc: O(n)
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

bool valid_anagram(string s , string t)
{
    if(s.size() != t.size()) // quick check 
    {
        return false;
    }
    unordered_map<char,int> map; // string char , freq for first string s

    for(int i = 0 ; i<s.size() ;i++) //1st step make map of first string 
    {
        if(map.count(s[i]) ) // already in map 
        {
            map[s[i]]++; // increase the freq count 
        }
        else{//if not in map then add it 
            map[s[i]] = 1 ;  }
    }
    //2nd step : look for t string's char in map
    for(int i = 0 ; i<t.size() ;i++)
    {
        if(map.count(t[i]) ) // t exist in map or not 
        {
            map[t[i]]--; // then reduce the freq 
            if(map[t[i]]==0) //after reducing , if it is 0 then remove it from the map
            {
                map.erase(t[i]);
            }
        }
        else{
            //if not exist return false 
            return false; } }
    //3rd step : check m.size is 0 or not 
    return map.size()==0;  //return true if 0
}
int main()
{   
    string s = "tuple";
    string t = "care";
    cout<<valid_anagram(s,t);
    return 0;
}