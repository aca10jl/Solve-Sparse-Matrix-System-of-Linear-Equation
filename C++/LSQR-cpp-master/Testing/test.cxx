#include <fstream>
#include <iostream>

float AValue[6];
int rowIndex[6];
int columnIndex[6];


int main(void){
	// std::ifstream infile("AA.txt");

	typedef double * RowType;
	RowType A[3];

	double AA[6];
	std::ifstream File;
	//std::string line;
	File.open("AA.txt");
	for (int i = 0; i < 6; i++) {
		File >> rowIndex[i] >> columnIndex[i] >> AValue[i];
		// std::cout << rowIndex[i] <<", "<<columnIndex[i] << ", " << AValue[i] << std::endl;
	}
	int a, b, c;
	for (int i = 0; i < 3; ++i)
	{
		A[i] = &(AA[i*2]);
		for (int j = 0; j < 2; ++j)
		{
			// File >> a >> b >> c;
			// std::cout << a <<", "<<b << ", " << c << std::endl;
			A[rowIndex[i]][columnIndex[j]] = AValue[i];
			// std::cout << a <<", "<<b << ", " << c << std::endl;
		}
	}


	for (int i = 0; i < 6; ++i)
	{
	std::cout << std::endl << "WTF?!" << std::endl;
	std::cout << rowIndex[i] << std::endl;
	std::cout << columnIndex[i] << std::endl;
	std::cout << AValue[i] << std::endl;
	}
	return(0);
}