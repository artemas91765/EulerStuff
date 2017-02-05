#include <stdio.h>
#include <stdlib.h>

long long digitvalue(int index, char digits[]){
		char temp[2];
		temp[0] = digits[index];
		temp[1] = digits[index + 1];
		return atoi(temp);
}

int main(int argc, char *argv[]){
	char digits[1601] = "0802229738150040007504050778521250779108\
											 4949994017811857608717409843694804566200\
											 8149317355791429937140675388300349133665\
											 5270952304601142692468560132567137023691\
											 2231167151676389419236542240402866331380\
											 2447326099034502447533537836842035171250\
											 3298812864236710263840675954706618386470\
											 6726206802621220956394396308409166499421\
											 2455580566739926971778789683148834896372\
											 2136230975007644204535140061339734313395\
											 7817532822753167159403800462161409535692\
											 1639054296353147555888240017542436298557\
											 8656004835718907054444374460215851541758\
											 1980816805944769287392138652177704895540\
											 0452088397359916079757321626267933279866\
											 8836688757622072034633674655123263935369\
											 0442167338253911249472180846293240627636\
											 2069364172302388346299698267598574043616\
											 2073352978319001743149714886811623570554\
											 0170547183515469169233486143520189196748";
	long long result = 1;
	long long tempresult = 0;
	//test row
	for(int i = 0; i <= 792; i += 2){
		//prevent leak into other row
		if(i % 40 <= 32){
			tempresult = digitvalue(i, digits) * digitvalue(i + 2, digits) * digitvalue(i + 4, digits) * digitvalue(i + 6, digits);
			if(tempresult > result){
				result = tempresult;
			}
		}
	}

	//test column
	for(int i = 0; i <= 679; i += 2){
		tempresult = digitvalue(i, digits) * digitvalue(i + 40, digits) * digitvalue(i + 80, digits) * digitvalue(i + 120, digits);
		if(tempresult > result){
			result = tempresult;
		}
	}

	//test diagonal
	for(int i = 0; i <= 672; i += 2){
		tempresult = digitvalue(i, digits) * digitvalue(i + 42, digits) * digitvalue(i + 84, digits) * digitvalue(i + 126, digits);
		if(tempresult > result){
			result = tempresult;
		}
	}
	int j = 0;
	tempresult = digitvalue(j, digits) * digitvalue(j + 40, digits) * digitvalue(j + 80, digits) * digitvalue(j + 120, digits);
	printf("test: %lld", tempresult);
	//printf("value is: %lld", result);
	return 0;
}
