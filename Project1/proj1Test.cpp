#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>

void enumeration(std::vector<int>&);
void enumeration2(std::vector<int>&);


int main()
{
	std::ofstream outputFile;
	std::vector<int>input;
	std::chrono::duration<double> timeDiff;
	int userN, userAlg;
	unsigned seed;
	int loop = 10;  //number of data points for analysis at each input size
	
	//Set seed for random function
	seed=time(0);
	srand(seed);
	
	//Initialize timing mechanism
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	
	//Open output file
	outputFile.open("Time_Results.txt");
	if(outputFile){
         std::cout << "Output file opened!" << std::endl;
     } 
	 else {
         std::cout << "Failed to open output file!" << std::endl;
         return -1;
     }
	
	do
	{
		//Get user input
		std::cout << "How many elements are in your array? ";
		std::cin >> userN;
		std::cout << "Select an algorithm to use:" <<  std::endl;
		std::cout << "1) Enumeration   2) Better Enumeration   3) Quit" << std::endl;
		std::cin >> userAlg;
		if (userAlg != 3)
		{
			//Print algorithm name and n to output file
			switch(userAlg)
			{
				case 1: outputFile << "1) Enumeration," << userN << ", ";
						break;
				case 2: outputFile << "2) Better Enumeration," << userN << ", ";
						break;
			}
			
			//Set range for random numbers
			int high = userN;
			int low = -1 * userN;
			
			//Loop through create new random array and running algorithm, write time to output file
			for (int i = 0; i < 10; i++)
			{
				//Populate random array
				for (int j = 0; j < userN; j++)
					input.push_back(rand() % (high - low + 1) + low);
				
				//Start time
				start = std::chrono::high_resolution_clock::now();
				//Run algorithm
				switch(userAlg)
				{
					case 1: enumeration(input);
							break;
					case 2: enumeration2(input);
							break;
					default: std::cout << "Not a valid algorithm selection" << std::endl;
				}
				//End Time
				end = std::chrono::high_resolution_clock::now();
				timeDiff = end - start;
				outputFile << timeDiff.count() << ",";
				
				//Clear array
				input.clear();
			}
			
			outputFile << "\n";
		}
	}while(userAlg != 3);
	
	return 0;
}



/**************************************************************************************
*            						enumeration
* Description: Finds the maximum subarray using an enumeration algorithm. Changes
* the start index, end index, and max sum parameters based on algorithm.
* Parameters:
*	vector<int> array: Provided array of values
*	int startInd: The starting index variable to set, changed in function
*	int endInd: The ending index variable to set, changed in function
*	int maxSum: Maximum sum variable to set, changed in function
**************************************************************************************/
void enumeration(std::vector<int>& array)
{
	int sum, first, last;
	int max = 0;
	int n = array.size();
	
	//Loop through all subarrays and find sum
	//Starting index control
	for(int i = 0; i < n; i++)
	{
		
		if (i != (n-1))
		{
			//Ending index control
			for(int j = i; j < n; j++)
			{
				sum = 0;
				//Sum all values within specified index
				for (int k = i; k <= j; k++)
					sum += array.at(k);
				
				//Compare sum to see if it's max and set indices
				if (max < sum)
				{
					max = sum;
					first = i;
					last = j;
				}
			}
		}
		else
		{
			//If last element in array, sum is that element value
			sum = array.at(i);
			//Compare sum to see if it's max and set indices 
			if (max < sum)
			{
				max = sum;
				first = i;
				last = i;
			}
		}
	}
	
/*	//Set maximum sum, the start index, and end index of the maximum subarray
	maxSum = max;
	startInd = first;
	endInd = last;*/
}

/**************************************************************************************
*            						enumeration2
* Description: Finds the maximum subarray using an improved enumeration algorithm. Changes
* the start index, end index, and max sum parameters based on algorithm.
* Parameters:
*	vector<int> array: Provided array of values
*	int startInd: The starting index variable to set, changed in function
*	int endInd: The ending index variable to set, changed in function
*	int maxSum: Maximum sum variable to set, changed in function
**************************************************************************************/
void enumeration2(std::vector<int>& array)
{
	int sum, first, last;
	int max = 0;
	int n = array.size();
	
	//Loop through all subarrays and find sum
	//Starting index control
	for(int i = 0; i < n; i++)
	{
		sum = 0;
		if (i != (n-1))
		{
			//Loop through remaining elements of array based on starting point
			for(int j = i; j < n; j++)
			{
				sum += array.at(j);
				//Compare sum to see if it's max and set indices
				if (max < sum)
				{
					max = sum;
					first = i;
					last = j;
				}
			}
		}
		else
		{
			//If last element in array, sum is that element value. Compare for max and set indices
			if (max < array.at(i))
			{
				max = array.at(i);
				first = i;
				last = i;
			}
		}
	}
	
/*	//Set maximum sum, the start index, and end index of the maximum subarray
	maxSum = max;
	startInd = first;
	endInd = last;*/
}