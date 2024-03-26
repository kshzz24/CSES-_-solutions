    #include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;


int main(){
     ll n;
     cin >> n;
     map<int, int> line;
     for(int i =1 ;i<=n; i++){
        int a, b;
        cin  >> a >> b;
        line[a]++;
        line[b+1]--;

     }

 
   int ans = 0;
   int curr = 0;
   for(auto &it: line){
     curr += it.second;
     if(curr > ans){
        ans = curr;
     }
   }
    

    cout << ans << endl;
    
}