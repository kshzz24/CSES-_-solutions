#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
    ll n;
    cin >> n;

    vll a(n);
    for(auto &it: a) cin >> it;
    
    sort(all(a));
        
        ll ans = 1LL;
        for(int i = 0; i<n; i++){
             if(a[i]> ans){
                cout << ans << endl;
                return 0;
             }

             ans += a[i];
        }
    
  cout << ans << endl;

    
}
