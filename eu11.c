#include <stdio.h>
#include <stdlib.h>

long long digitvalue(int index, char digits[]){
		char temp[2];
		temp[0] = digits[index];
		temp[1] = digits[index + 1];
		return atoi(temp);
}

int main(int argc, char *argv[]){
	char digits[1601] = "08022297381500400075040507785212507791084949994017811857608717409843694804566200814931735579142993714067538830034913366552709523046011426924685601325671370236912231167151676389419236542240402866331380244732609903450244753353783684203517125032988128642367102638406759547066183864706726206802621220956394396308409166499421245558056673992697177878968314883489637221362309750076442045351400613397343133957817532822753167159403800462161409535692163905429635314755588824001754243629855786560048357189070544443744602158515417581980816805944769287392138652177704895540045208839735991607975732162626793327986688366887576220720346336746551232639353690442167338253911249472180846293240627636206936417230238834629969826759857404361620733529783190017431497148868116235705540170547183515469169233486143520189196748";
	long long result = 1;
	long long tempresult = 0;
	//test row
	for(int i = 0; i < 1594; i += 2){
		//prevent leak into other row
		if(i % 40 < 32){
			tempresult = digitvalue(i, digits) * digitvalue(i + 2, digits) * digitvalue(i + 4, digits) * digitvalue(i + 6, digits);
			if(tempresult > result){
				result = tempresult;
			}
		}
	}

	//test column
	for(int i = 0; i < 1480; i += 2){
		tempresult = digitvalue(i, digits) * digitvalue(i + 40, digits) * digitvalue(i + 80, digits) * digitvalue(i + 120, digits);
		if(tempresult > result){
			result = tempresult;
		}
	}

	//test diagonal
	for(int i = 0; i < 1474; i += 2){
		//make sure not our of bounds
		if(i % 40 <= 32){
			tempresult = digitvalue(i, digits) * digitvalue(i + 42, digits) * digitvalue(i + 84, digits) * digitvalue(i + 126, digits);
			if(tempresult > result){
				result = tempresult;
			}
		}
	}

	//test other diagonal
	for(int i = 120; i < 1600; i += 2){
		//make sure not out of bounds
		if(i % 40 <= 32){
			tempresult = digitvalue(i, digits) * digitvalue(i - 38, digits) * digitvalue(i - 76, digits) * digitvalue(i - 114, digits);
			if(tempresult > result){
				result = tempresult;
			}
		}
	}

	printf("value is: %lld", result);
	return 0;
}
