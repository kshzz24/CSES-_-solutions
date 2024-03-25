#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for(auto &it: a) cin >> it;
    for(auto &it: b) cin >> it;

    sort(all(a));
    sort(all(b));

    ll ans = 0;
    int i = 0; 
    int j = 0;

   while(i<n and j<m){
        if(abs(a[i]-b[j])<=k){
            i++;
            j++;
           ans++;
        }
        else if(a[i]-b[j]>k) {
            j++;
        }
        else{
            i++;
        }
   }
    
    cout << ans << endl;
}
