//Name : Alphonsa George
//Assignment : PROG1003 HW8 -Numbers

#include <cmath>
#include <fstream>
#include<iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "numbers.h"

/*!
\brief Represesnts the minimum value number_of_values can take.
*/
const int k_min_number_of_values = 1;

/*!
\brief Represesnts the maximum value number_of_values can take.
*/
const int k_max_number_of_values = 25;

/*!
\brief Represesnts the minimum value first_value can take.
*/
const int k_min_first_value = -1000;

/*!
\brief Represesnts the maximum value first_value can take.
*/
const int k_max_first_value = 1000;

/*!
\brief Represesnts the minimum value increment value can take.
*/
const int k_min_increment = 1;

/*!
\brief Represesnts the maximum value increment value can take.
*/
const int k_max_increment = 20;

/*!
\brief Represents the value column width can take. 
*/
const int k_column_width = 20;

int main()
{
	
	auto number_of_values = nwacc::get_values_within_range("Enter the number of values in the table(1 to 25):", k_min_number_of_values,k_max_number_of_values);

	auto first_value = nwacc::get_values_within_range("Enter the first value in the table(-1000 to 1000):", k_min_first_value,k_max_first_value);

	auto increment_value = nwacc::get_values_within_range("Enter the increment between values in the table(1 to 20):",k_min_increment,k_max_increment);

	std::vector<int>values;

	nwacc::load_values(values, number_of_values, first_value, increment_value);

	std::vector<int>square_values;
	nwacc::load_square_values(values, square_values);

	std::vector<std::string>square_root_values;
	nwacc::load_square_root_values(values, square_root_values);

	std::vector<int>cube_values;
	nwacc::load_cube_values(values, cube_values);

	std::vector<std::string>cube_root_values;
	nwacc::load_cube_root_values(values, cube_root_values);

	std::vector<std::string>even_odd_values;
	nwacc::load_even_odd_values(values, even_odd_values);

	std::vector<bool>prime_values;
	nwacc::load_prime_values(values, prime_values);

	std::cout << "Number" << std::setw(k_column_width) << std::right << "Square of number" << std::setw(k_column_width) << std::right << "Square root " <<
	std::setw(k_column_width) << std::right << "Cube of number" << std::setw(k_column_width) << std::right << "Cube root   " << std::setw(k_column_width) << std::right
	<< "Even/Odd" << std::setw(k_column_width) << std::right << "Prime-ness" << std::endl;

	for (auto index = 0; index < number_of_values; index++)
	{
		std::cout << values[index] << std::setw(k_column_width) << std::right << square_values[index] << std::setw(k_column_width) << std::right
			<< square_root_values[index] << std::setw(k_column_width) << std::right << cube_values[index] << std::setw(k_column_width) << std::right
			<< cube_root_values[index] << std::setw(k_column_width) << std::right << even_odd_values[index] << std::setw(k_column_width) << std::right
			<<std::boolalpha<< prime_values[index] << std::endl;
	}

	std::cout << "Enter the file name: ";
	std::string file;
	std::cin >> file;
	std::string file_name;
	file_name = file + ".csv";

	std::ofstream fout;
	fout.open(file_name);

	fout << "Number" << "," << "Square of number" << "," << "Square root " <<
		"," << "Cube of number" << "," << "Cube root   " << ","
		<< "Even/Odd" << "," << "Prime-ness " << std::endl;

	for (auto index = 0; index < number_of_values; index++)
	{
		fout<< values[index] << "," << square_values[index] << ","
			<< square_root_values[index] << "," << cube_values[index] << ","
			<< cube_root_values[index] << "," << even_odd_values[index] << ","
			<< std::boolalpha << prime_values[index] << std::endl;
	}
	fout.close();

	std::cout << "Saved to the file " << file_name << std::endl;

	return 0;
}
