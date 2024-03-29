/* I need a fucking genuine template */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define ss second
#define ff first
#define ll long long

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define mii map<int, int>
#define vpp vector<pair<long long, long long>>
#define si set<int>
#define sc set<char>


/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e;i>=s;i--)
#define pb push_back
#define eb emplace_back
// #define sz 200002
#define all(nums) nums.begin(), nums.end()
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef unsigned long long ull;
typedef long double lld;
typedef tree< 
    ll,                   
    null_type,              
    less<ll>,              
    rb_tree_tag,            
    tree_order_statistics_node_update> ordered_set;
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
#define mod 12345

ll sz(vll &a){
    return a.size();
}

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}




template<class T, class U>
// T -> node, U->update.
struct Lsegtree{
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;
    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n,identity_element);
        lazy.assign(4*n, identity_update);
    }
    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r);
        return ans;
    }
    void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
    {
        if(tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }
    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr-tl+1)*upd;
        return ans;
    }
    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = old_upd;
        ans=new_upd;
        return ans;
    }  
    void push_down(ll v, ll tl, ll tr)
    {
        if(lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if(2*v + 2 < 4*n)
        {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);            
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v,tl,tr);
        if(l > r)return identity_element;
        if(tr < l or tl > r)
        {
            return identity_element;
        }
        if(l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v+1,tl,tm,l,r), queryUtil(2*v+2,tm+1,tr,l,r));
    }
 
    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v,tl,tr); 
        if(tr < l or tl > r)return;
        if(tl >=l and tr <=r)
        {
            lazy[v] = combineUpdate(lazy[v],upd,tl,tr);
            push_down(v,tl,tr);
        }
        else
        {
            ll tm = (tl + tr)>>1;
            updateUtil(2*v+1,tl,tm,l,r,upd);
            updateUtil(2*v+2,tm+1,tr,l,r,upd);
            st[v] = combine(st[2*v + 1], st[2*v+2]);
        }
    }

    void build(vector<T>a)
    {
        assert(sz(a) == n);
        buildUtil(0,0,n-1,a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0,0,n-1,l,r);
    }
    void update(ll l,ll r, U upd)
    {
        updateUtil(0,0,n-1,l,r,upd);
    }
};


ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout <<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */

void input(vll & nums){
  
}

// Maths to remember
// x mod y <x/2 if x≥y and xmody == x if x<y
// short way to make series of no eq is not avg but median



void swap(ll &x, ll &y){
	ll temp = y;
	y = x;
	x = temp;
}

bool primenumberorwot(ll n){
    ll count = 0;
    for(ll i = 1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if(n/i!=i){
                count++;
            }
        }
    }
    
    return count==2;
} 

ll factorial(int num) {
 
    int i;
    ll fact = 1;

    for (i = 2; i <= num; i++)
        fact *= i;

 
    return fact;
}

 
ll ncr(ll n, ll r)
{
 
   ll p = 1, k = 1;

    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }

    return p;
}
 

ll npr(int n, int r) {
    // return fdfdfdfultult
    
    cout << n << " " << r << endl;
    return factorial(n) / factorial(n - r);
}

void print(vll& v){
    for(auto &x : v) cout << x << " ";
    cout << endl;
}



bool goodNotRequired(string s){
    int n = s.size();
  
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            return false;
        }
    }
    return true;
}


vector<ll> delRow = {1,0,-1, 0};
vector<ll> delCol = {0,1,0,-1};



int findUltParent(int node, vector<ll> parent){
     if (node == parent[node])
            return node;
     return parent[node] = findUltParent(parent[node], parent);
}


// 6 4 3 2 1
// 1 2 3 3 4 
// 1 7 6 1 2
// 7
// 


 vll findD(vll &nums, ll n){
          
     vll x;

     for(ll i = 1; i*1LL*i<=n; i++){
         if(n%i == 0){
            if(n/i != i){
                x.pb(n/i);
                x.pb(i);
            }
            else x.pb(i);
         }
     }
     return x;
 }
 
vll ggwp(ll &n){
    vll x;
    while(n){
        x.pb(n%10);
        n /= 10;
    }
    // reverse(all(x));
    return x;
}
  
set<ll> precompute(vll& nums, ll n){
    set<ll> st;
     ll sum = accumulate(all(nums), 0LL);
     for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
             st.insert((sum*2)-nums[i]-nums[j]);
        }
     }
}
 void bob(){
    cout << "Bob" << endl;
 }

  void alice(){
    cout << "Alice" << endl;
 }
 long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
 
    long long res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}

ll helper(ll start, ll end, string &s ,char c){
    ll rem = 0;
     for(int i = start; i<=end; i++){
        if(s[i]!=c){
            rem++;
        }
     }
     return rem;
}

ll fs(ll x, ll y){
    return abs(x-y);
}


void findss(bool flag, queue<int>&q ){
  if(flag==true && q.size()>0)
        {
           no();
        }
  else if(flag)  {
            yes();
}
}
 void solve(){
    ll n;
    cin >> n;
    string a,b;
    cin >> a >> b;
     

     vll x;
    for(int i =0 ; i<n; i++){
        if(a[i]!=b[i])
        x.pb(i);
    }

    ll m = x.size();
    if(m==1) {
         no();
     return;
    }
    
       queue<int> q;
        int curr=-1;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(a[i]=='b')
                {
                    curr=i;
                }
            }
            else if(a[i]=='a' && b[i]=='c')
            {
                q.push(i);
            }
            else if(a[i]=='c' && b[i]=='a')
            {
                if(q.size()!=0 && q.front()<curr)
                {
                    q.pop();
                }
                else
                {
                  no();
                  return;
                }

            }
            else
            {
              no();
              return;
            }
        }
        findss(flag, q);
      



 }
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    precompute();
    
    ll t = 1 ;
   cin >> t;
     
    while(t--){
      solve();
       
    }
    return 0;
}     



