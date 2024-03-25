#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;

    set<ll> st;
    for(int i = 1; i<=n;i++){
        ll x;
        cin >> x;
        st.insert(x);
    }

    cout << (ll)st.size() << endl;
}
