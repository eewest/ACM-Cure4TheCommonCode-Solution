#include "Cure4CC_Solution.h"


int main(){
	char arr[5][100] = {"abbbcdcdcdabbbcdcdcd","abcbcdedeabcbcdede","abbbcdcdcdabbbcdcdcdabcbcdedeabcbcdede","abcbcdedeabcbcdedeabcbcdedeabcbcdede", "aaaa"};
	char *ss = (char*)malloc(100);
	int idx = 0;
	for(idx = 0; idx < 5; idx++){
		printf("%s ==== %s\n", arr[idx], CompressString(arr[idx]));
	}
	
	gets(ss);
}