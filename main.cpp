#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl;

#include "src/utils.hpp"

using utils::tulong;


/**
 * @brief Called when the program is launched
 * 
 * @param argc Count of command-line arguments
 * @param argv Args, zero is the name of the program
 * @return int An error code
 */
int main(int argc, char *argv[])
{
	cout << "Hello, world!! I'm test-cpp-repo :)" << endl;

	struct code { tulong i; tulong j; tulong k; tulong l; };
	

	std::vector<code> possibleCodes;

	for (size_t i = 0; i <= 9; i++)
	{
		for (size_t j = 0; j <= 9; j++)
		{
			for (size_t k = 0; k <= 9; k++)
			{
				for (size_t l = 0; l <= 9; l++)
				{
					// Check if any digits are the same
					if (i == j || i == k || i == l) continue;
					if (j == i || j == k || j == l) continue;
					if (k == i || k == j || k == l) continue;
					if (l == i || l == j || l == k) continue;

					bool exists = false;

					// Check if the code already exists
					for (auto &&xCode : possibleCodes)
					{
						tulong similarity = 0;
						
						// Check if any digits already exist
						if (xCode.i == i || xCode.j == i || xCode.k == i || xCode.l == i) similarity++;
						if (xCode.i == j || xCode.j == j || xCode.k == j || xCode.l == j) similarity++;
						if (xCode.i == k || xCode.j == k || xCode.k == k || xCode.l == k) similarity++;
						if (xCode.i == l || xCode.j == l || xCode.k == l || xCode.l == l) similarity++;

						// If there are 4 digits that already exist, don't mark the code down
						if (similarity >= 4) { exists = true; break; }
						else similarity = 0;
					}

					if (!exists) possibleCodes.push_back( code{.i = i, .j = j, .k = k, .l = l} );
				}
			}
		}
	}
	
	// List the count of possible codes (should be 210, hopefully XD)
	cout << "Total number of codes: " << possibleCodes.size() << endl;

	// List every code that can be used!
	for (size_t i = 0; i < possibleCodes.size(); i++)
	{
		code &iCode = possibleCodes[i];
		
		cout << "Code #" << i 
			// Ensure all codes line up with each-other
			<< ((i > 999)? " " : ((i > 99)? "  " : ((i > 9)? "   " : "    ")))
			<< iCode.i << iCode.j << iCode.k << iCode.l
			<< endl;
	}
	
	return 0;
}