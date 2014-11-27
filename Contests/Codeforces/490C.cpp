// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

char S[1000000+5];
bool div_a[1000000+5], div_b[1000000+5];

int main(void)
{
	ll a, b;
	
	sfs(S);
	sfl(a), sfl(b);
	int Len=strlen(S);
	ll mod=0;
	
	rep(i, Len)
	{
		mod=((mod*10)+(S[i]-'0'))%a;
		if(!mod) div_a[i]=true;
		else div_a[i]=false;
	}
	
	mod=S[Len-1]-'0';
	mod%=b;
	if(!mod)
	div_b[Len-1]=true;
	ll ten=1;
	
	repd(i, Len-2, 0)
	{
		ten*=10;
		ten%=b;
		mod=(mod+(S[i]-'0')*ten)%b;
		if(!mod) div_b[i]=true;
		else div_b[i]=false;
	}
	
	int partition=-1;
	
	rep(i, Len-1)
	{
		if(div_a[i] && div_b[i+1] && S[i+1] != '0')
		{
			partition=i;
			break;
		}
	}
	
	if(partition != -1)
	{
		puts("YES");
		
		rept(i, 0, partition)
		{
			cout<<S[i];
		} nl;
		
		rept(i, partition+1, Len-1)
		{
			cout<<S[i];
		} nl;
	}
	else
	puts("NO");
	
	return (0);
}