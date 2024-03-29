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
     vll prefix(n,0);
     prefix[0] = a[0];
     for(int i  = 1; i<n; i++){
        prefix[i] = prefix[i-1]+a[i];
     }
     vll suffix(n,0);
     suffix[n-1] = a[n-1];
     for(int i = n-2; i>=0; i--){
        suffix[i] = suffix[i+1]+ a[i];
     }
    
    ll ans = 1e18;
    for(int i = 0; i<n; i++){
         ll curr = a[i];
         ll pre  = (i+1)*a[i] - prefix[i];
         ll suff  = suffix[i] - (n-i)*a[i];
         ans = min(ans, pre+suff);
    }
  cout << ans << endl;


    
}
