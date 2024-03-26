#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
    ll n,x;
    cin >> n >> x;

    vll a(n);
    for(auto &it: a) cin >> it;

    sort(all(a));
    int ans = 0;
    int i = 0, j = n-1;
    while(i<j){
        if(a[i]+a[j] <= x){
            ans++;
            i++;
            j--;
        }
        else if(a[i]+a[j]> x){
            ans++;
            j--;
        }
    }

    if(i == j){
        ans++;
    }

    cout << ans << endl;




    
}
