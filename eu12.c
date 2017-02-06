#include <stdio.h>

int findDivisors(int input){
	int numdivi = 0;
	//only search till sqrt of input, as divisors are in pairs, one is less than the sqrt and the other is greater
	for(int divi = 1; divi * divi < input; divi++){
			if(input % divi == 0){
				//except for when its the square root
				if(divi * divi == input){
					numdivi++;
				}
				else{
					numdivi += 2;
				}
			}
	}
	return numdivi;
}

int main(int argc, char *argv[]){
	int tsqnce = 1;
	int index = 2;
	int solved = 0;
	//the triangle sequence is generated using the index starting at 2 and the number at 1
	while(!solved){
		if(findDivisors(tsqnce) > 500){
			printf("%d has over 500 divisors", tsqnce);
			solved = 1;
		}
		tsqnce += index;
		index++;
	}
}
