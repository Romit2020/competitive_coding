#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;

ull k;
int n,m;

void build(int t[]){
	//cout<<"value of k here in fxn "<<k<<endl;
	int flag=1,b;
	ull limit;
	ull h = n;
	for(b=k-1;b>=0;b--){
	    limit = 1<<(h-1);
		//cout<<"limit "<<limit<<endl;
		if(b<limit){
		if(flag==1){
				flag=0;
			}
			else{
				flag=1;
			}
			h--;
			limit = 1<<(h-1); 
		}
		if(flag==1 && (b>=limit)){
			t[b] = t[b<<1] | t[(b<<1)|1]; 
		}
		if(flag==0 && (b>=limit)){
			t[b] = t[b<<1] ^ t[(b<<1)|1];
		}  
	}    
}

void modify(int t[],int a,int b){
	
	ull limit,i;
	a+=k;
	t[a] = b;
	limit = 1<<(n-1);
	int flag=1;
	
	for(i=a/2; i>0; i >>= 1){
		
	//cout<<"i here "<<i<<endl;
	//cout<<"limit here "<<limit<<endl;

	 if(i >= limit && flag==1){
		t[i] = t[i<<1] | t[(i<<1)^1];
		limit = limit/2;
		flag=0;
	}
	
	
	else if(i >= limit && flag==0){
		t[i] = t[i<<1] ^ t[(i<<1)^1];
		limit = limit/2;
		flag=1;
	}
	
	}
	
}


int main(){
	ios_base::sync_with_stdio(false);
	
	ull i;
	//int n,m;
	cin>>n>>m;
    k = 1<<(n);
    //cout<<"k= "<<k<<endl; k is number of elements
	int ar[(2*k)] = {0};
	for(i=0;i<k;i++){
		cin>>ar[k+i];
	}
	
	build(ar);
	
	//for(i=1;i<2*k;i++)cout<<ar[i]<<" ";
	//cout<<endl;
	
	int x,y;
	for(int h=0;h<m;h++){
		cin>>x>>y;
		modify(ar,x-1,y);
		cout<<ar[1]<<" ";
		
	}
	
	//modify(ar,0,4);
	//for(i=1;i<2*k;i++)cout<<ar[i]<<" ";
	
	return 0;
}
