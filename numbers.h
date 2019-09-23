//Name : Alphonsa George
//Assignment : PROG1003 HW8 -Numbers

#ifndef NUMBERS_H_
#define NUMBERS_H_

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief The character literal for new line.
	*/
	const char k_newline = '\n';

	/*!
	\brief This represents the power to find cube root, which is equal to 0.3333
	*/
	const double k_cube_power = 0.3333;

	/*!
	\brief This represents the constant to check if a number is even, which is equal to 2.
	*/
	const int k_even_checker = 2;

	/*!
	\brief This represents the first prime number, which is 2.
	*/
	const int k_first_prime_number = 2;

	/*!
	\brief This represents a number which is neither prime nor composite, which is 1
	*/
	const int k_not_prime_not_composite_number = 1;

	/*!
	\brief This represents a constant to be added which is used while checking if a number is prime.
	*/
	const int k_prime_checker_addend = 1;

	/*!
	\brief To check if a function is of type integer
	extracts the number from the input stream and checks it's type and repeats the prompt until
	the user enters the right type.

	\param prompt, prompts the user for the input

	\return returns the valid integer input
	*/
	int get_int_correct_type(std::string prompt);

	/*!
	\brief Checks if an integer is in the valid range
	extracts the number from the input stream and checks if it falls
	in the valid range and epeats the prompt until
	the user enters the right type.

	\param prompt, prompts the user for the input
	\param min, minimum value of the range input can take
	\param max, maximum value of the range input can take

	\return returns the valid range integer input
	*/
	int get_values_within_range(std::string prompt, int min, int max);

	/*!
	\breif Calculates the square of a number

	\param number, the number whose square needs to be calculated

	\return returns the square of the number
	*/
	int square(int number);

	/*!
	\brief Calculates the square root of the number
	if the number is less than 0 it returns a string "NA", if not it
	returns the square root of the number.

	\param number, the number whose square root needs to be calculated. 

	\return returns the square root of the number for number>0 else "NA"
	*/
	std::string square_root(int number);

	/*!
	\breif Calculates the cube of a number

	\param number, the number whose cube needs to be calculated

	\return returns the cube of the number
	*/
	int cube(int number);

	/*!
	\brief Calculates the cube root of the number
	if the number is less than 0 it returns a string "NA", if not it
	returns the cube root of the number.

	\param number, the number whose cube root needs to be calculated.

	\return returns the cube root of the number for number>0 else "NA"
	*/
	std::string cube_root(int number);

	/*!
	\brief Checks if a number is even or odd
	
	\param number, number to be checked for the even/odd status.

	\return returns a string "Even" for even numbers and "Odd" for odd numbers.
	*/
	std::string even_or_odd(int number);

	/*!
	\brief Checks if a number is prime number or not.
	checks the prime-ness of the given number. 

	\param number, number to be checked for the prime-ness.

	\return returns 'true' if the number is prime else 'false'.
	*/
	bool is_prime(int number);

	/*!
	\brief Loads values to a vector based on the inputs from user.
	loads vector of size, first value and the increment between the numbers based on the user input.

	\param values, vector to be loaded.
	\param number_of_values size of the vector.
	\param first_value first value of the vector.
	\param increment_value increment between the values.

	*/
	void load_values(std::vector<int>& values, int number_of_values, int first_value, int increment_value);

	/*!
	\brief Loads a vector with the square of the numbers of the given vector.

	\param values, the vector which has the values whose square needs to be calculated.
	\param square_values, the vector to be loaded with the square of the elements of the vector values.
	*/
	void load_square_values(const std::vector<int>& values, std::vector<int>& square_values);

	/*!
	\brief Loads a vector with the square root of the numbers of the given vector.

	\param values, the vector which has the values whose square root needs to be calculated.
	\param square_root_values, the vector to be loaded with the square root of the elements of the vector values.
	*/
	void load_square_root_values(const std::vector<int>& values, std::vector<std::string>& square_root_values);

	/*!
	\brief Loads a vector with the cube of the numbers of the given vector.

	\param values, the vector which has the values whose cube needs to be calculated.
	\param cube_values, the vector to be loaded with the cube of the elements of the vector values.
	*/
	void load_cube_values(const std::vector<int>& values, std::vector<int>& cube_values);

	/*!
	\brief Loads a vector with the cube root of the numbers of the given vector.

	\param values, the vector which has the values whose cube root needs to be calculated.
	\param cube_root_values, the vector to be loaded with the cube root of the elements of the vector values.
	*/
	void load_cube_root_values(const std::vector<int>& values, std::vector<std::string>& cube_root_values);

	/*!
	\brief Loads a vector with the even/odd status of the given vector.

	\param values, the vector which has the values whose even/odd status needs to be checked.
	\param even_odd_values, the vector to be loaded with the even/odd status of the elements
	of the vector values. 
	*/
	void load_even_odd_values(const std::vector<int>& values, std::vector<std::string>& even_odd_values);

	/*!
	\brief Loads a vector with the prime-ness of the given vector.

	\param values, the vector which has the values whose prime-ness needs to be checked.
	\param prime_values, the vector to be loaded with the boolean value
	representing the prime-ness of the elements of the vector values.
	*/
	void load_prime_values(const std::vector<int>& values, std::vector<bool>& prime_values);

}
#endif