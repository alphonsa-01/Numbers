//Name : Alphonsa George
//Assignment : PROG1003 HW8 -Numbers

#include "numbers.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief To check if a function is of type integer
	extracts the number from the input stream and checks it's type and repeats the prompt until
	the user enters the right type.

	\param prompt, prompts the user for the input

	\return returns the valid integer input
	*/
	int get_int_correct_type(std::string prompt)
	{
		std::cout << prompt;
		auto values = 0;
		std::cin >> values;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
			std::cout << "Invalid type!!should be integer, try again" << std::endl;
			std::cout << prompt;
			std::cin >> values;
		}

		return values;
	}

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
	int get_values_within_range(std::string prompt, int min, int max)
	{
		auto values = get_int_correct_type(prompt);

		while (values<min || values>max)
		{
			std::cout << "Invalid range, try again!" << std::endl;
			values = get_int_correct_type(prompt);
		}
		return values;
	}


	/*!
	\breif Calculates the square of a number

	\param number, the number whose square needs to be calculated

	\return returns the square of the number
	*/
	int square(int number)
	{
		return number * number;
	}

	/*!
	\brief Calculates the square root of the number
	if the number is less than 0 it returns a string "NA", if not it
	returns the square root of the number.

	\param number, the number whose square root needs to be calculated.

	\return returns the square root of the number for number>0 else "NA"
	*/
	std::string square_root(int number)
	{
		if (number > 0)
		{
			return std::to_string(std::sqrt(number));
		}
		else
		{
			return "NA";
		}

	}

	/*!
	\breif Calculates the cube of a number

	\param number, the number whose cube needs to be calculated

	\return returns the cube of the number
	*/
	int cube(int number)
	{
		return number * number * number;
	}

	/*!
	\brief Calculates the cube root of the number
	if the number is less than 0 it returns a string "NA", if not it
	returns the cube root of the number.

	\param number, the number whose cube root needs to be calculated.

	\return returns the cube root of the number for number>0 else "NA"
	*/
	std::string cube_root(int number)
	{
		if (number > 0)
		{
			return std::to_string(std::pow(number, k_cube_power));
		}
		else
		{
			return "NA";
		}
	}

	/*!
	\brief Checks if a number is even or odd

	\param number, number to be checked for the even/odd status.

	\return returns a string "Even" for even numbers and "Odd" for odd numbers.
	*/
	std::string even_or_odd(int number)
	{

		if (number % k_even_checker == 0)
		{
			return "Even";
		}
		else
		{
			return "Odd";
		}
	}

	/*!
	\brief Checks if a number is prime number or not.
	checks the prime-ness of the given number.

	\param number, number to be checked for the prime-ness.

	\return returns 'true' if the number is prime else 'false'.
	*/
	bool is_prime(int number)
	{
		auto is_prime_value = true;
		auto value = 0;
		value = static_cast<int>(std::sqrt(number));
		auto check_value = value + k_prime_checker_addend;

		if (number > 0 && number != k_first_prime_number && number != k_not_prime_not_composite_number)
		{
			for (auto count = k_first_prime_number; count < check_value; count++)
			{
				if (number % count == 0)
				{
					is_prime_value = false;
				}//else,is_prime_value is already set to true, so do_nothing();
			}
			return is_prime_value;
		}
		else if (number == k_not_prime_not_composite_number)
		{
			is_prime_value = false;
		}
		else if (number == k_first_prime_number)
		{
			is_prime_value = true;
		}
		else
		{
			is_prime_value = false;
		}

		return is_prime_value;
	}

	/*!
	\brief Loads values to a vector based on the inputs from user.
	loads vector of size, first value and the increment between the numbers based on the user input.

	\param values, vector to be loaded.
	\param number_of_values size of the vector.
	\param first_value first value of the vector.
	\param increment_value increment between the values.

	*/
	void load_values(std::vector<int>& values, int number_of_values, int first_value, int increment_value)
	{
		auto value = first_value;
		values.push_back(value);

		for (auto counter = 0; counter < number_of_values - 1; counter++)
		{
			value = value + increment_value;
			values.push_back(value);
		}
	}

	/*!
	\brief Loads a vector with the square of the numbers of the given vector.

	\param values, the vector which has the values whose square needs to be calculated.
	\param square_values, the vector to be loaded with the square of the elements of the vector values.
	*/
	void load_square_values(const std::vector<int>& values, std::vector<int>& square_values)
	{
		for (const auto& value : values)
		{
			auto squared_value = square(value);
			square_values.push_back(squared_value);
		}
	}

	/*!
	\brief Loads a vector with the square root of the numbers of the given vector.

	\param values, the vector which has the values whose square root needs to be calculated.
	\param square_root_values, the vector to be loaded with the square root of the elements of the vector values.
	*/
	void load_square_root_values(const std::vector<int>& values, std::vector<std::string>& square_root_values)
	{
		for (const auto& value : values)
		{
			std::string square_rooted_value;
			square_rooted_value = square_root(value);
			square_root_values.push_back(square_rooted_value);
		}
	}

	/*!
	\brief Loads a vector with the cube of the numbers of the given vector.

	\param values, the vector which has the values whose cube needs to be calculated.
	\param cube_values, the vector to be loaded with the cube of the elements of the vector values.
	*/
	void load_cube_values(const std::vector<int>& values, std::vector<int>& cube_values)
	{
		for (const auto& value : values)
		{
			auto cubed_value = cube(value);
			cube_values.push_back(cubed_value);
		}
	}

	/*!
	\brief Loads a vector with the cube root of the numbers of the given vector.

	\param values, the vector which has the values whose cube root needs to be calculated.
	\param cube_root_values, the vector to be loaded with the cube root of the elements of the vector values.
	*/
	void load_cube_root_values(const std::vector<int>& values, std::vector<std::string>& cube_root_values)
	{
		for (const auto& value : values)
		{
			std::string cube_rooted_value;
			cube_rooted_value = cube_root(value);
			cube_root_values.push_back(cube_rooted_value);
		}
	}

	/*!
	\brief Loads a vector with the even/odd status of the given vector.

	\param values, the vector which has the values whose even/odd status needs to be checked.
	\param even_odd_values, the vector to be loaded with the even/odd status of the elements
	of the vector values.
	*/
	void load_even_odd_values(const std::vector<int>& values, std::vector<std::string>& even_odd_values)
	{
		for (const auto& value : values)
		{
			std::string even_odd_checker;
			even_odd_checker = even_or_odd(value);
			even_odd_values.push_back(even_odd_checker);
		}
	}

	/*!
	\brief Loads a vector with the prime-ness of the given vector.

	\param values, the vector which has the values whose prime-ness needs to be checked.
	\param prime_values, the vector to be loaded with the boolean value
	representing the prime-ness of the elements of the vector values.
	*/
	void load_prime_values(const std::vector<int>& values, std::vector<bool>& prime_values)
	{
		for (const auto& value : values)
		{
			auto prime_checker = is_prime(value);
			prime_values.push_back(prime_checker);
		}

	}

}