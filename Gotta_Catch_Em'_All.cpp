#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<utility>
#include<list>

#define pb push_back
#define ll long long int
#define mp make_pair
//#define sci(a) scanf("%d",&a)
//#define scll(a) scanf("%lld",&a)
//#define scc(a) scanf("%s",&a) 
#define F first
#define S second
#define all(c) (c.begin(),c.end())
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++)
#define fr(i,s,e) for(i=s;i<e;i++)
using namespace std;

bool cmp(pair<ll,ll>a,pair<ll,ll>b){
if(a.F >= b.F)
return true;
else
return false;	
}

int main(){
	string s;
	cin>>s;
	map<char,int>m;
	int i=0;
	while(s[i] != '\0'){
		if(s[i]=='B' || s[i]=='u' || s[i]=='l' || s[i]=='b' || s[i]=='a' || s[i]=='s' || s[i]=='r' ){
			m[s[i]]++;
		}
		i++;
	}
	int ans = 999999,k=1;
 tr(m, it) { 
 int temp;
       if(k==2 || k==3 || k==7){
       	 temp = (((*it).S)/2);
       	}
	   else{
	   	temp = (*it).S;
	   }
	   
	ans = ans < temp ? ans : temp;
	k++;
 } 
 cout<<ans;
	return 0;
}
