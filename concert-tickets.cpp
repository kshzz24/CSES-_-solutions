#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
     
     ll n,m;
     cin >> n >> m;
     vll nums(n);
     for(auto &it: nums) cin >> it;
     vll b(m);
     for(auto &it: b) cin >> it;
     set<pair<ll,ll>> st;
     for(int i = 0; i<n; i++){
        st.insert({nums[i], i});
     }
     
     
     for(int i = 0; i<m; i++){
         auto it = st.lower_bound({b[i]+1, 0});
         if(it == st.begin()){
            cout << "-1\n";
         }
         else{
             --it;
             cout << (*it).first << "\n";
             st.erase(it);
         }

     }


    
}
