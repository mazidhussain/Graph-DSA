#include <bits/stdc++.h>
using namespace std;


vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k=p.length();
        unordered_map<char,int> m;
        for(int i=0;i<k;i++){
            m[p[i]]++;
        }
        int count=m.size();
        int i=0;
        int j=0;
        while(j<s.size()){
            if(m[s[j]]){
                m[s[j]]--;
            }
            else{
                m[s[j]]++;
                count++;
            }
            if(m[s[j]]==0){
                count--;
            }
            if(j+i+1<k){
                j++;
            }
            else if(j+i+1==k){
                if(count==0){
                    ans.push_back(i);
                }
                m[s[i]]++;
            }
        }
        return ans;
    }

int main(){
    vector<int > v=findAnagrams("cbaebabacd","abc");
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}