#include "fizzbuzz.h"



std::string fizzBuzz(int value) {

	if (0 ==value % 3 && 0 == value % 5) {
		return "FizzBuzz";
	}

	if (0 == value % 3) {
		return "Fizz";
	}

	if (0 == value % 5) {
		return "Buzz";
	}

	return std::to_string(value);

}