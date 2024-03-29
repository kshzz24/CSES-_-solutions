#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
     ll n;
     cin >> n;
     vll nums(n);
     for(auto &it: nums) cin >> it;
      int start = 0;
      int end = 0;
      int ans = 0;
      map<int, int> mp;
      while(end<n){
         mp[nums[end]]++;
         while(mp[nums[end]]>1){
             mp[nums[start++]]--;
         }
         ans = max(ans, end-start+1);
         end++;
      }
      cout << ans << endl;
}
