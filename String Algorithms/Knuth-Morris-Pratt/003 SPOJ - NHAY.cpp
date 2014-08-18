// Author : Bony Roopchandani
// NHAY
// KMP

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
#define ll long long
#define mp make_pair
#define nl printf("\n")
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

string A;

class KMP
{
	string needle;
	int* b;
	
	public:
	
	KMP(int N)
	{
		b = new int[N+5];
	}
	
	~KMP()
	{
		delete []b;
	}
	
	void KMP_PreProcess()
	{
		cin>>needle;
		
		int i=1, j=-1;
		b[0]=-1;
		
		while(i<needle.sz+1)
		{
			while(j>=0 && needle[i-1]!=needle[j])
			j = b[j];
			
			b[i++]=++j;
		}
	}
	
	void KMP_Search()
	{
		cin>>A;
		int i, j;
		i=j=0;
		
		while(i<A.sz)
		{
			while(j>=0 && A[i] != needle[j])
			j = b[j];
			
			i++, j++;
			
			if(j==needle.sz)
			{
				pfi(i-j);
				j=b[j];
			}
		}
	}
};

int main()
{
//	freopen("input.txt", "r", stdin);
	
	int N, cs=1;
	
	while(sfi(N)==1)
	{
		if(cs!=1)
		nl;
		cs++;
		
		KMP K(N);
		K.KMP_PreProcess();
		K.KMP_Search();
	}
	return (0);
}