#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
   
    ll n,sum;
    cin >> n >> sum;

    vector<pair<int, int>> a;
    for(int i = 0; i<n; i++){
         ll x;
         cin >> x;
         a.push_back({x, i+1});
    }

    sort(all(a));
    
    for(int i=0 ; i<n-2; i++){
         int j = i+1;
         int k = n-1;
         while(j<k){
            int t = a[i].first+a[j].first+a[k].first;
            if(t == sum){
                cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
                return 0;
            }
            else if(t<sum){
                j++;
            }
            else k--;

         }
    }

  cout << "IMPOSSIBLE\n" << endl;

    
}
