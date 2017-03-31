#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* CollapseSeq(char* s);
char* CollapseSeries(char* s);
char* subString(char* s, int sidx, int eidx){
	int idx, len = (eidx-sidx+1);
	char* subs = (char*) malloc(len+1);
	subs[len] = 0;
	for(idx = 0;sidx < eidx; sidx++){
		subs[idx++] = s[sidx];
	}
	subs[idx] = 0;
	return subs;
}

char* CollapseSeries(char* s){
	char* output = (char*)malloc(strlen(s)*2);
	int count = 0, idx = 0, oidx = 0;
	char c;

	while(s[idx] != 0){
		c = s[idx];
		if(s[idx+1] != 0 && c == s[idx+1]){
			count = 0;
			while(c == s[idx] && count != 9){
				count++;
				idx++;
			}
			output[oidx++] = '0' + count;
			output[oidx++] = c;
		}
		else if(s[idx+1] != 0 && c != s[idx+1]){
			output[oidx++] = '1';
			output[oidx++] = c;
			idx++;
		}else{
			output[oidx++] = '1';
			output[oidx++] = c;
			idx++;
		}
	}
	output[oidx] = 0;
	return output;

}

char* CollapseSeq(char* s){
	char* output = (char*) malloc(2001);
	char* subS = 0;
	char cA, cB;
	unsigned int sidxA = 0, sidxB = 0, sidxC = 0, idx = 0, oidx = 0;
	int iA, iB, repCount = 0;
	output[2000] = 0;

	for(sidxA = 0; sidxA < strlen(s);){
		iA = s[sidxA] - '0';
		cA = s[sidxA+1];

		for(sidxB = (sidxA+2); sidxB < strlen(s); sidxB+=2){
			iB = s[sidxB] - '0';
			cB = s[sidxB+1];
			
			if(iA == iB && cA == cB){
				subS = subString(s,sidxA, sidxB);
				repCount = 0;
				sidxC = sidxA;
				while(sidxC < strlen(s) && s[sidxC] == subS[0] && s[sidxC+1] == subS[1]){
					for(idx = 0; idx < strlen(subS) && sidxC < strlen(s); idx+= 2){
						if(subS[idx] == s[sidxC] && subS[idx+1] == s[sidxC+1]){
							sidxC += 2;
						}else{
							break;
						}
					}
					if(idx == strlen(subS)){
						repCount++;
					}
				}
				if(sidxC >= strlen(s) || subS[0] != s[sidxC] || subS[1] != s[sidxC+1]){
					break;
				}
			}

		}
		if(repCount >1){
				sidxA += strlen(subS) * repCount;
				subS = CollapseSeq(subS);
				output[oidx++] = repCount + '0';
				output[oidx++] = '(';
				for(idx = 0; idx < strlen(subS); idx++){
					output[oidx++] = subS[idx];
				}
				output[oidx++] = ')';
				repCount = 0;
			}
			else{
				output[oidx++] = '0'+iA;
				output[oidx++] = cA;
				sidxA += 2;
			}
	}
	output[oidx++] = 0;

	if(subS != 0){
		free(subS);
	}

	return output;
}

char* CompressString(char* s){
	char* temp = (char*)malloc(1000);
	int idx = 0, pos = 0;
	char* output = CollapseSeries(s);
	output = CollapseSeq(output);

	while(output[idx] != 0){
		if(output[idx] != '1'){
			temp[pos++] = output[idx++];
		}else{
			idx++;
		}
	}
	temp[pos] = 0;
	free(output);
	return temp;
}