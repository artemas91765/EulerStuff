#include <stdio.h>

long long collatzSequence(long long collatzint, long long index){
	if(collatzint == 1){
		return index;
	}
	if(collatzint % 2 == 0){
		return collatzSequence(collatzint / 2, index+1);
	}
	else{
		return collatzSequence((collatzint * 3) + 1, index+1);
	}
}

int main(int argc, char *argv[]){
	long long temp;
	long long value;
	long long largest = 0;
	for(long long i = 2; i <= 1000000; i++){
		temp = collatzSequence(i, 1);
		if(temp > largest){
			largest = temp;
			value = i;
		}
	}
	printf("The integer with the longest Collatz Sequence is: %lld \n", value);
	return 0;
}
