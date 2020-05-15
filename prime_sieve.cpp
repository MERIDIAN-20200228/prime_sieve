/*
 * Prime seive using modified Sieve of Eratothenes
 * by MERIDIAN (SGT_Stabby) 2020-05
 *
 * Note: runs significantly faster without outputting primes as they are found. Working on methods for storing
 * 	 primes and running on sections of a larger set to increase maximum searchable values at reduced cost.
 */
 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	
// initializing variables and check_vector ----------------------------------------------------------------
	
	int64_t high_num = 0, current_index = 1, max_check_set_index = 0, max_index = 0, set_high_index = 0, real_num = 0, primes = 1;
	char set_high = '.';
	
	cout << "Set the high value for the check range (odd integer): ";
	cin >> high_num;
	max_index = 0.5*high_num - 0.5;
	vector<char> check_vector(max_index);
	
// checking, outputting, and setting high up to ~sqrt(high_num) -------------------------------------------
	
//	cout << 2 << endl;
	max_check_set_index = 0.5*( sqrt(high_num) - 1 );
	
	while ( current_index <= max_check_set_index )
	{
		
		if ( check_vector[current_index] == NULL )
		{

			real_num = 2*current_index + 1;
			set_high_index = current_index;
//			cout << real_num << endl;
		
			while ( set_high_index < max_index )
			{

				check_vector[set_high_index] = set_high;
				set_high_index += real_num;

			}
			
			++primes;
			
		}
		
		++current_index;
		
	}
	
// checking and outputting up to high_num------------------------------------------------------------------
	
	while ( current_index <= max_index )
	{
		
		if ( check_vector[current_index] == NULL )
		{

//			cout << 2*current_index + 1 << endl;
			
			++primes;
			
		}
		
		++current_index;
		
	}

	check_vector.clear();
	check_vector.shrink_to_fit();
	
// asking nicely if you want to exit the program-----------------------------------------------------------

	cout << endl << "Primes found: " << primes << endl << endl << "Enter an integer to exit: ";
	cin >> current_index;
	return 0;

}
