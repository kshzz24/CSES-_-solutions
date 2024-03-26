#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
     ll n;
     cin >> n;
     
   vector<vector<int>> arr(n, vector<int>(2, 0));
   for(int i = 0 ;i<n; i++){
      cin >> arr[i][1] >> arr[i][0];
   }

   sort(all(arr));

   int last = 0;
   int ans =0 ;
   for(int i  =0 ; i<n ; i++){
      if(arr[i][1] >= last){
        ans++;
        last = arr[i][0];
      }
   }

   cout << ans << endl;
}