//============================================================================
// Name        : math_functions.cpp
// Author      : Justin Hales
// Version     :
// Copyright   :
// Description : Some math functions in C++
//============================================================================

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

/*
 * Determines if x is prime and returns boolean.
 */
bool is_prime(int x) {
	if(x < 2) {
		return false;
	}
	if(x % 2 == 0) {
		return false;
	}
	int d = 3;
	while(d <= (x/ 2)) {
		if(x % d == 0) {
			return false;
		}
		d += 2;
	}
	return true;
}

/*
 * Clears then fills a vector with prime numbers up to maxi.
 */
void generate_primes(std::vector<int>& primes, unsigned maxi) {
	primes.clear();
	unsigned number = 2;
	if(number <= maxi) {
		primes.push_back(2);
		number++;
		while(number <= maxi) {
			if(is_prime(number)) {
				primes.push_back(number);
			}
			number += 2;
		}
	}
}

void generate_primes2(std::vector<int>& primes, unsigned max) {
	primes.clear();
	for(unsigned i = 2; i <= max; i++) {
		primes.push_back(i);
	}
	std::vector<int> remove;
	unsigned index = 0;
	unsigned pn_index = 0;
	int remove_index;
	while(pow(primes[pn_index],2) <= max) {
		index = pn_index;
		std::cout << "index assigned to " << index << std::endl;
		std::cout << "Beginning 1st mini-loop" << std::endl;
		remove_index = (primes[pn_index] * primes[index]) - 2 - (2 * pn_index);
		while(remove_index < primes.back()) {
			std::cout << "  Number to remove: " << primes[remove_index] << std::endl;
			remove.push_back(remove_index);
			index++;
			remove_index = (primes[pn_index] * primes[index]) - 2 - (2 * pn_index);
		}
		std::cout << "Beginning 2nd mini-loop" << std::endl;
		while(remove.size() > 0) {
			std::cout << "  Removing " << primes[remove.back()] << " from primes" << std::endl;
			primes.erase(primes.begin() + remove.back());
			remove.pop_back();
		}
		std::cout << "primes is now: " << std::endl;
		for(unsigned i = 0; i < primes.size(); i++) {
			std::cout << primes[i] << std::endl;
		}
		pn_index++;
		std::cout << "Next prime number: " << primes[pn_index] << std::endl;
	}
}

/*
 * Clears a vector and fill it with primes up to max.
 */
void generate_primes3(std::vector<int>& primes, int max) {
	primes.clear();
	primes.push_back(2);
	for(int i = 3; i <= max; i++) {

	}
	// Put known primes in initially. This allows the later algorithm to be fast.
	int known_primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	for(unsigned i = 0; i < 8; i++) {
		if(known_primes[i] <= max) {
			primes.push_back(known_primes[i]);
		} else {
			return;
		}
	}

	if(23 > max) {
		return;
	}

	int n = 23;
	while(n <= max) {

	}
	primes.push_back(2);
	for(int n = 3; n <= max; n++) {
		for(int p = 0;; p++) {
			if(n % primes[p] == 0) {
				break;
			} else if (primes[p] > sqrt(n)) {
				primes.push_back(n);
				break;
			}
		}
	}

	//for(unsigned i = 0; i < primes.size(); i++) {
	//	std::cout << primes[i] << ", ";
	//}

	//std::cout << std::endl;
}

void generate_primes4(std::vector <int>& primes, int max) {
	// Put known primes in initially. This allows the later algorithm to be fast.
	int known_primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	for(unsigned i = 0; i < 8; i++) {
		if(known_primes[i] <= max) {
			primes.push_back(known_primes[i]);
		} else {
			return;
		}
	}

	if(23 > max) {
		return;
	}

	int n = 23;
	while(n <= max) {

	}
	primes.push_back(2);
	for(int n = 3; n <= max; n++) {
		for(int p = 0;; p++) {
			if(n % primes[p] == 0) {
				break;
			} else if (primes[p] > sqrt(n)) {
				primes.push_back(n);
				break;
			}
		}
	}

	//for(unsigned i = 0; i < primes.size(); i++) {
	//	std::cout << primes[i] << ", ";
	//}

	//std::cout << std::endl;
}

/*
 * Prints out prime number information.
 */
void print_primes() {

}

/*
 * Clears then fills a vector with the factors of x.
 */
void find_factors(int x, std::vector<int>& factors) {
	factors.clear();
	if(x > 0) {
		if(x > 1) {
			factors.push_back(1);
			factors.push_back(x);
			int divisor = 2;
			while(divisor <= sqrt(x)) {
				if(x % divisor == 0) {
					factors.push_back(x / divisor);
					factors.push_back(divisor);
				}
				divisor += 1;
			}
			std::sort(factors.begin(),factors.end());
		} else {
			factors.push_back(1);
		}
	}
}

/*
 * Clears then fills a vector with the prime factors of x.
 */
void prime_factors(int x, std::vector<int>& factors) {
	factors.clear();
	std::vector<int> possi;
	generate_primes(possi, x);
	int i = 1;
	while(x != 1) {
		i++;
		while(x % possi[i] == 0) {
			factors.push_back(possi[i]);
			x /= possi[i];
		}
	}
	std::sort(factors.begin(), factors.end());
}

/*
 * Takes x and y and returns their least common multiple.
 */
int lcm(int x, int y) {
	int addx = x;
	int addy = y;
	while(true) {
		if(x < y) {
			x += addx;
		} else if(x > y) {
			y += addy;
		} else {
			break;
		}
	}
	return x;
}

/*
 * Takes x and y and returns their greatest common factor.
 */
int gcf(int x, int y) {
	std::vector<int> x_factors;
	find_factors(x,x_factors);
	std::reverse(x_factors.begin(),x_factors.end());
	std::vector<int> y_factors;
	find_factors(y,y_factors);
	std::reverse(y_factors.begin(),y_factors.end());
	if(x_factors.size() > y_factors.size()) {
		for(unsigned i = 0; i < y_factors.size(); i++) {
			if(std::find(x_factors.begin(),x_factors.end(),y_factors[i]) != x_factors.end()) {
				return y_factors[i];
			}
		}
	} else {
		for(unsigned i = 0; i < x_factors.size(); i++) {
			if(std::find(y_factors.begin(),y_factors.end(),x_factors[i]) != y_factors.end()) {
				return x_factors[i];
			}
		}
	}
	return -1;
}

/*
 * Determines whether x, y, and z are a pythagorean triplet, and
 * returns boolean.
 */
bool is_pythag_triplet(int x, int y, int z) {
	std::vector<int> n;
	n.push_back(x);
	n.push_back(y);
	n.push_back(z);
	std::sort(n.begin(),n.end());
	if(pow(n[2],2) == pow(n[0],2) + pow(n[1],2)) {
		return true;
	}
	return false;
}

/*
 * Changes a char to it's integer equivalent
 */
int char_to_int(char l) {
	int n = l - '0';
	if(n >= 0 && n <= 9) {
		return n;
	}
	return -1;
}

/*
 * Changes an integer to it's char equivalent
 */
char int_to_char(int n) {
	if(n >= 0 && n <= 9) {
		char l = n + '0';
		return l;
	}
	return '~';
}

/*
 * Returns the digit equivalent of x.
 */
std::string digit_to_string(char x) {
	switch(x) {
	case 0:
		return "zero";
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	default:
		return "digit_error";
	}
}

std::string teens_to_string(char x) {
	switch(x) {
	case 0:
		return "ten";
	case 1:
		return "eleven";
	case 2:
		return "twelve";
	case 3:
		return "thirteen";
	case 4:
		return "fourteen";
	case 5:
		return "fifteen";
	case 6:
		return "sixteen";
	case 7:
		return "seventeen";
	case 8:
		return "eighteen";
	case 9:
		return "nineteen";
	default:
		return "teens_error";
	}
}

/*
 * Returns the tens-place equivalent of x. (ten, twenty...)
 */
std::string tens_to_string(char x) {
	switch(x) {
	case 0:
		return "";
	case 1:
		return "ten";
	case 2:
		return "twenty";
	case 3:
		return "thirty";
	case 4:
		return "forty";
	case 5:
		return "fifty";
	case 6:
		return "sixty";
	case 7:
		return "seventy";
	case 8:
		return "eighty";
	case 9:
		return "ninety";
	default:
		return "tens_error";
	}
}

std::string major_number_words(int x) {
	switch(x) {
	case 1:
		return "thousand";
	case 2:
		return "million";
	case 3:
		return "billion";
	case 4:
		return "trillion";
	case 5:
		return "quadrillion";
	case 6:
		return "quintillion";
	case 7:
		return "sextillion";
	case 8:
		return "septillion";
	case 9:
		return "octillion";
	case 10:
		return "nonillion";
	case 11:
		return "decillion";
	case 12:
		return "undecillion";
	case 13:
		return "duodecillion";
	case 14:
		return "tredecillion";
	case 15:
		return "quattuordecillion";
	case 16:
		return "quindecillion";
	case 17:
		return "sexdecillion";
	case 18:
		return "septendecillion";
	default:
		return "major_error";
	}
}

/*
 * Takes a number between 0 and 18,446,744,073,709,551,615 and
 * returns the result in word form. (123 = one-hundred-twenty-three)
 */
std::string int_to_string(unsigned long long x) {
	if(x == 0) {
		return "zero";
	}
	int first_digit;
	bool add_major_word = false;
	std::string word = "";
	for(int xlen = floor(log10(x)); xlen >= 0; xlen--) {
		first_digit = x/pow(10,xlen);
		if(add_major_word && (xlen + 1) % 3 == 0) {
			word += major_number_words((xlen + 1) / 3);
			word += "-";
			add_major_word = false;
		}
		if(first_digit != 0) {
			add_major_word = true;
		} else {
			continue;
		}
		if((xlen + 2) % 3 != 0) {
			word += digit_to_string(first_digit);
			if((xlen + 1) % 3 == 0 && first_digit != 0) {
				word += "-hundred";
			}
		} else {
			if(first_digit != 1) {
				word += tens_to_string(first_digit);
			} else {
				x -= pow(10,xlen);
				xlen--;
				first_digit = x/pow(10,xlen);
				word += teens_to_string(first_digit);
			}
		}
		word += "-";
		x -= first_digit * (pow(10,xlen));
	}
	word.erase(word.end() - 1);
	return word;
}

int main() {
	std::vector<int> primes;
	//std::vector<int> change;
	//std::clock_t start;

	/*for(int i = 1000; i <= 100000; i += 1000) {
		start = std::clock();
		generate_primes3(primes, i);
		std::cout << "Time for up to " << i << ": " << (std::clock() - start) / double(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	}*/

	generate_primes3(primes, 100);
	double total = 0;
	int num = 1;
	std::vector<int> previous;

	for(unsigned f = 0; f < primes.size(); f++) {
		previous.push_back(primes[f]);
		std::cout << "prime: " << primes[f] << std::endl;
		num = 1;

		for(unsigned i = 0; i < previous.size(); i++) {
			num *= previous[i];
		}

		total += 1 / double(num);
		std::cout << "Portion removed: " << total << std::endl;
	}

	return 0;
}
