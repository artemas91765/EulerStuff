#include <stdio.h>



int isPrime(long long tested){
	if(tested == 1){return 0;}
	if(tested == 2){return 1;}
	if(tested % 2 == 0){return 0;}

	for(int i = 3; i * i  <= tested; i+= 2){
		if(tested % i == 0){return 0;}
	}
	return 1;
}


int main(int argc, char *argv[]){
	long long stuff = 0;
	for(long long i = 1; i <= 2000000; i++){
		if(isPrime(i)){
			stuff += i;
		}
	}
	printf("The value is: %lld\n", stuff);
	return 0;
}
