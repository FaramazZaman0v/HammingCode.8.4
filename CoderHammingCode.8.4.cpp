#include <iostream>
#include <bitset>

std::bitset<16> coder(int a){
	std::bitset<8> d=a, p;
	std::bitset<16> C;
	
	p[0]=((1+d[0]+d[2]+d[3])%2);
	p[1]=((1+d[0]+d[1]+d[3])%2);
	p[2]=((1+d[0]+d[1]+d[2])%2);
	p[3]=((1+p[0]+d[0]+p[1]+d[1]+p[2]+d[2]+d[3])%2); 
	if((d[0]+d[2]+d[3]+p[0])%2!=1) return -1;

	p[4] = (1 + d[4] + d[6] + d[7]) % 2;
	p[5] = (1 + d[4] + d[5] + d[7]) % 2;
	p[6] = (1 + d[4] + d[5] + d[6]) % 2;
	p[7] = (1 + p[4] + d[4] + p[5] + d[5] + p[6] + d[6] + d[7]) % 2;
	if((d[4]+d[6]+d[7]+p[4])%2!=1) return -2;

	for(int i=0; i<8; i++){
		C[2*i]=d[i];
		C[2*i+1]=p[i];
	}
	return C;
}


std::bitset<8> decoder(std::bitset<16> R){
	std::bitset<8> Dec;
	bool A=R[0]^R[2]^R[4]^R[6] ;
	bool B=R[1]^R[2]^R[5]^R[6] ;
	bool C=R[3]^R[4]^R[5]^R[6] ;
	bool D=R[0]^R[1]^R[2]^R[3]^R[4]^R[5]^R[6]^R[7] ;
	
	int P=(C*4)+(B*2)+A-1;
	
	if( !A && !B && !C && !D ) {
		std::cout << "No errors\n" ;
	} else if ( D && P==-1) {
		std::cout << "Error at parity bit\n" ;
	} else if( !D && A+B+C!=0 ) {
		std::cout << "Double error - Packet rejected\n" ;
		return -3;
	}else if( D && A+B+C!=0 ) {
		std::cout << "Error at position: " << P << "\n" ;
		R.flip(P) ;
	} else {
		std::cout << "Unknown error. Packet rejected\n" ;
		return -4;
	}
	 	
	for(int i=0; i<8; i++){
		Dec[i]=R[2*i];
	}

	return Dec;
}


int main(){
	int U=0, tmp=0;
	std::bitset<16> C;
	std::bitset<8> Dec;
	
	std::cin >> U;
	if(U<0 || U>255) return -5;
	
	C=coder(U);
	std::cout << C << "\n";
	
	Dec=decoder(C);
	std::cout << Dec << "\n";
	
	for(int i=1; i<9; i++){
		tmp<<=1;
		tmp|=Dec[8-i];
	}
	std::cout << tmp << "\n";
	return 0;
}