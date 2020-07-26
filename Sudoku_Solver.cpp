//#include<bits/stdc++.h>
#include <iostream>


#define endl '\n'
#define pi acos(-1)
#define euler_e 2.71828
#define pii pair<int,int>
#define pb push_back
#define all(a) a.begin(),a.end()
#define ll long long
#define ull unsigned long long
#define io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
void mycode();
const ll int infLL=(1LL<<62);
const ll int mod=998244353;
ll int ceil(ll int a,ll int b){return (a+b-1)/b;}
ll int min(ll int a, ll int b){if(a>b)return b;else return a;}
bool bit_check(ll int a,int i){
  if((a & (1LL<<i)))return 1;
  return 0;
}
ll int bit_toggle(ll int a,int i){
  return (a^(1LL<<i));
}
ll int bit_sum(ll int a,int i){
  return a+(1LL<<i);
}
ll int bit_sub(ll int a,int i){
  return a-(1LL<<i);
}
ll int mod_power(ll int x,ll int y){//x^y%p
  ll int p=mod;
  ll int res = 1;
  x = x % p;
  while (y > 0) { 
    if (y & 1)res = (res*x) % p;
    y = y>>1;x = (x*x) % p;
  }
  return res;
}
ll int power_of(ll int a,int b){
  if(a==0)return -1;
  return 1+power_of(a/b,b);
}
ll power(ll int a, ll int b) {
	if(a==1)return 1;
    ll int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){
	//boost;
	//io;
	//auto start = chrono::high_resolution_clock::now();
	mycode();
	//auto end = chrono::high_resolution_clock::now();cerr << "\nExecution time: "<< chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
	return 0;
}
#include<vector>
struct ss{
	bool iscons;
	bool arr[10];
	short fix;
};
ss init1,init2;

short count=1;

void soveit(vector<ss> vc, short idx, short idxfix){
	if(idxfix!=-1){
		idx--;
		short y=idx/9;
		short x=idx%9;

		vc[idx].fix=idxfix;
			
		for(short i=x+1;i<9;i++){
			if(!vc[9*y+i].iscons)vc[9*y+i].arr[idxfix]=false;
		}
		for(short i=y+1;i<9;i++){
			if(!vc[9*i+x].iscons)vc[9*i+x].arr[idxfix]=false;
		}

		y=(y/3)*3;
		x=(x/3)*3;

		if(!vc[9*y+x].iscons && 9*y+x!=idx)vc[9*y+x].arr[idxfix]=false;
		if(!vc[9*y+x+1].iscons && 9*y+x+1!=idx)vc[9*y+x+1].arr[idxfix]=false;
		if(!vc[9*y+x+2].iscons && 9*y+x+2!=idx)vc[9*y+x+2].arr[idxfix]=false;

		if(!vc[9*(y+1)+x].iscons && 9*(y+1)+x!=idx)vc[9*(y+1)+x].arr[idxfix]=false;
		if(!vc[9*(y+1)+x+1].iscons && 9*(y+1)+x+1!=idx)vc[9*(y+1)+x+1].arr[idxfix]=false;
		if(!vc[9*(y+1)+x+2].iscons && 9*(y+1)+x+2!=idx)vc[9*(y+1)+x+2].arr[idxfix]=false;

		if(!vc[9*(y+2)+x].iscons && 9*(y+2)+x!=idx)vc[9*(y+2)+x].arr[idxfix]=false;
		if(!vc[9*(y+2)+x+1].iscons && 9*(y+2)+x+1!=idx)vc[9*(y+2)+x+1].arr[idxfix]=false;
		if(!vc[9*(y+2)+x+2].iscons && 9*(y+2)+x+2!=idx)vc[9*(y+2)+x+2].arr[idxfix]=false;

		idx++;
	}

	if(idx==81){
		cout<<"Solve "<<count<<":\n";
		for(short i=0;i<9;i++){
			if(i%3==0)cout<<" -----------------------\n";
			for(short j=0;j<9;j++){
				if(j%3==0)cout<<"| ";
				cout<<vc[9*i+j].fix<<" ";
			}
			cout<<"|"<<endl;
		}
		cout<<" -----------------------\n\n\n\n";
		count++;
		return;
	}


	if(vc[idx].iscons==true)soveit(vc,idx+1,-1);
	else{
		for(short k=1;k<=9;k++){
			if(vc[idx].arr[k])soveit(vc,idx+1,k);
		}
	}
}

void mycode(){
	vector<ss> vc;
	ss st;
	init1.iscons=0;
	for(short i=0;i<10;i++)init1.arr[i]=true;
	init2.iscons=1;


	char ch;
	for(short i=0;i<9;i++){
		for(short j=0;j<9;j++){
			cin>>ch;

			if(ch<='9'&&ch>='1'){
				init2.fix=ch-'0';
				vc.push_back(init2);
			}


			else {
				vc.push_back(init1);
			}
		}
	}

	for(short i=0;i<9;i++){
		for(short j=0;j<9;j++){
			short idx=9*i+j;
			if(vc[idx].iscons){
				short idxfix=vc[idx].fix;
				for(short k=0;k<9;k++){
					if(!vc[9*i+k].iscons)vc[9*i+k].arr[idxfix]=false;
					if(!vc[9*k+j].iscons)vc[9*k+j].arr[idxfix]=false;
				}

				short x,y;
				y=(i/3)*3;
				x=(j/3)*3;

				if(!vc[9*y+x].iscons)vc[9*y+x].arr[idxfix]=false;
				if(!vc[9*y+x+1].iscons)vc[9*y+x+1].arr[idxfix]=false;
				if(!vc[9*y+x+2].iscons)vc[9*y+x+2].arr[idxfix]=false;

				if(!vc[9*(y+1)+x].iscons)vc[9*(y+1)+x].arr[idxfix]=false;
				if(!vc[9*(y+1)+x+1].iscons)vc[9*(y+1)+x+1].arr[idxfix]=false;
				if(!vc[9*(y+1)+x+2].iscons)vc[9*(y+1)+x+2].arr[idxfix]=false;

				if(!vc[9*(y+2)+x].iscons)vc[9*(y+2)+x].arr[idxfix]=false;
				if(!vc[9*(y+2)+x+1].iscons)vc[9*(y+2)+x+1].arr[idxfix]=false;
				if(!vc[9*(y+2)+x+2].iscons)vc[9*(y+2)+x+2].arr[idxfix]=false;

			}
		}
	}

	soveit(vc,0,-1);

}
