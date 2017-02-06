#include <stdio.h>

int findDivisors(int input){
	int numdivi = 0;
	for(int divi = 1; divi * divi < input; divi++){
			if(input % divi == 0){
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
	while(!solved){
		if(findDivisors(tsqnce) > 500){
			printf("%d has over 500 divisors", tsqnce);
			solved = 1;
		}
		tsqnce += index;
		index++;
	}
}
