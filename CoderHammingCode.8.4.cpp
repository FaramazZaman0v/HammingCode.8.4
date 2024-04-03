#include <iostream>
#include <vector>

int main(){
	std::vector<int> d, p;
	int U=0, tmp1, tmp2=0, c=0;
//	char C;
//	std::cin >> C;
	
	std::cin >> U;
	if(U<0 || U>255) return -3;
	
	tmp1=U;
	
	for(int i=0; i<4; i++){
		c=tmp1&1;
		if(c>0) d.push_back(1);
		else d.push_back(0);
		tmp1=tmp1>>1;
	}
	
	p.push_back((1+d[0]+d[2]+d[3])%2);
	p.push_back((1+d[0]+d[1]+d[3])%2);
	p.push_back((1+d[0]+d[1]+d[2])%2);
	p.push_back((1+p[0]+d[0]+p[1]+d[1]+p[2]+d[2]+d[3])%2);
	
	if((d[0]+d[2]+d[3]+p[0])%2!=1) return -1;
	
	tmp1=0;
	for(int i=0; i<(int)d.size(); i++){
		tmp1=tmp1|p[i];
		tmp1=tmp1<<1;
		tmp1=tmp1|d[i];
		tmp1=tmp1<<1;
	}
//----------------------------------------------------------------------
	
	d.clear();
	p.clear();
	tmp2=U>>4;
	for(int i=0; i<4; i++){
		c=tmp2&1;
		if(c>0) d.push_back(1);
		else d.push_back(0);
		tmp2=tmp2>>1;
	}
	
	p.push_back((1+d[0]+d[2]+d[3])%2);
	p.push_back((1+d[0]+d[1]+d[3])%2);
	p.push_back((1+d[0]+d[1]+d[2])%2);
	p.push_back((1+p[0]+d[0]+p[1]+d[1]+p[2]+d[2]+d[3])%2);
	
	if((d[0]+d[2]+d[3]+p[0])%2!=1) return -2;
	
	tmp2=0;
	for(int i=0; i<(int)d.size(); i++){
		tmp2=tmp2|p[i];
		tmp2=tmp2<<1;
		tmp2=tmp2|d[i];
		tmp2=tmp2<<1;
	}
//----------------------------------------------------------------------

	tmp2=tmp2<<4;
	tmp1=tmp1|tmp2;
	std::cout << tmp1 << "\n";
	return 0;
}
