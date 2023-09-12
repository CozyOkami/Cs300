#include <iostream>
#include <string>
#ifndef project1_header
#define project1_header
using namespace std;

void decoder(string s){
    string decoded = s;
    string map = "1234567890-=WERTYUIOP[]SDFGHJKL;'XCVBNM,./";
    for (int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
	    decoded[i] = s[i];
	} if(s[i] == 'Q'){
	    decoded[i] = s[i];
	} if(s[i] == 'A'){
	    decoded[i] = s[i];
	} if(s[i] == 'Z'){
	    decoded[i] = s[i];
	} if(s[i] == '1'){
	    decoded[i] = s[i];
        } else{
	    for(int j = 0; j < map.length(); j++){
	        if(s[i] == map[j]){
		    s[i] = map[j-1];
	         }
	     } //need to add print statement
	}
    }       
}

//problem 3
int reverseNumber(int n) {
    unsigned int reverse = 0;
    while (n > 0) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }
    return reverse;
    }
int reverseAdd (int n){
	int reverse = reverseNumber(n);
    int i = 0;
    while (i < 1000 || reverse != n || n < 4294967295){
	    n += reverseNumber(n);
	    i++;
	} //need to add print statement
}

#endif
