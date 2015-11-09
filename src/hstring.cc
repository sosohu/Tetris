#include "hstring.h"

void strNumAddU(std::string &num, size_t w, size_t n){
	if(num.size() < w){
		num.insert(num.begin(), w - num.size(), '0');
	}
	size_t cin = 0;
	for(int i = num.size() - 1; i >= num.size() - w && (n || cin); i--){
		size_t cur = num[i] - '0' + (n % 10) + cin;
		cin = cur / 10;
		num[i] = (cur % 10) + '0';
		n = n / 10;
	}
}
