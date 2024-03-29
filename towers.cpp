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
    
    vll x;
    for(int i = 0 ; i<n; i++){
        int index = upper_bound(all(x), a[i])-x.begin();
        if(index < x.size()){
            x[index] = a[i];
        }
        else {
             x.pb(a[i]);
        }
    }

    cout << (int)x.size() << endl;

    
}
