#include<bits/stdc++.h>
using namespace std;

bool is_prime[1000005];
long long cnt[1000005], n, t;

void sieve(int n){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
    	if (is_prime[i]) {
        	for (int j = i * i; j <= n; j += i)
            	is_prime[j] = false;
    	}
	}
}
bool takut(int n){
	int now=n;
	int cnt=0;
	while(now>0){
		if(now%10==0)return false;
		else {
			now/=10;
			cnt++;
		}
	}
	now=n;
	int div=pow(10, cnt);
	while(now>0){
		now%=div;
		div/=10;
		if(now!=0 && is_prime[now]==false)return false;
	}
	return true;
}
void cnttakut(){
	for(int i=2; i<=1000000; i++){
		cnt[i]=cnt[i-1];
		if(is_prime[i] && takut[i])cnt[i]++;
	}
}

int main(){
	cin>>t;
	for(int i=1; i<=1000000; i++)is_prime[i]=true;
	sieve(1000000);
	cnttakut();
	for(int i=1; i<=t; i++){
		cin>>n;
		cout<<cnt[n]<<endl;
	}
}