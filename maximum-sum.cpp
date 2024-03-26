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
    ll ans = -1e18;
    ll msf = -1e18;
    for(int  i =0; i< n; i++){
        msf = max(nums[i], nums[i]+msf);
        ans = max(ans, msf);
    }

    cout << ans << endl;

}