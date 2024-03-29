#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
    ll n,m;
    cin >> n >> m;

    vector<ll> arr(n+1);
    vll pos(n+1);
     
     for(int i = 1; i<=n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    
    

      int ans  = 1;
      for(int i = 1; i<n; i++){
         ans += (pos[i] > pos[i+1]) ;
      }
       set<pair<int, int>> st;
      while(m--){
        int l, r;
        cin >> l >> r;
        if(arr[l]+1<=n){
            st.insert({arr[l], arr[l]+1});
        }
        if(arr[l]-1>=1) st.insert({arr[l]-1, arr[l]});
        if(arr[r]-1>=1) st.insert({arr[r]-1, arr[r]});
        if(arr[r]+1<=n) st.insert({arr[r], arr[r]+1});

        for(auto &it: st){
            ans -= (pos[it.first] > pos[it.second]);
        }
        swap(arr[l], arr[r]);
        pos[arr[l]] = l;
        pos[arr[r]] = r;

         for(auto &it: st){
            ans += (pos[it.first] > pos[it.second]);
        }
        cout << ans << endl;
        st.clear();
      }
    
}
