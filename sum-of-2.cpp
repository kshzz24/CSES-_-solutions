#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
     ll n, m;
     cin >> n >> m;
     
     int ans = 0;
     vll a(n);
     for(auto &it: a) cin >> it;

     map<int, int> mp;
     
     for(int i =0 ; i<n; i++){
          if(mp.find(m-a[i])!= mp.end()){
             cout <<  mp[m-a[i]]+1  << " " << i+1 ;
             return 0;
          }
          else{
            mp[a[i]] = i;
          }
     }

   cout << "IMPOSSIBLE" << endl;
}