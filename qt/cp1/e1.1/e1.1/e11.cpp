#include <iostream>
#include <sstream>
#include <fstream>

bool fileExists(const char *fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

int main()
{
	std::string fOutName;
	std::ostringstream strStream;
	std::ofstream fileOut;
	std::cout << "Podaj nazwe pliku do otwarcia." << std::endl;
	std::cin >> fOutName;

	strStream << "Strumien stringow... \o/\n"
		<< "Kolejny wiersz\n"
		<< "Nazwa pliku: "
		<< fOutName;
	
	bool flagReWrite = fileExists(fOutName.c_str());
	bool flagUserChoice = true;
	if (flagReWrite)
	{
		std::cout << "Plik: " << fOutName << " istnieje\n"
				  << "Nadpisac plik [Y\\N]" << std::endl;
		char ch;
		while ((getchar()) != '\n');
		ch = getchar();
		if (ch != 'Y' || ch != 'y')
			flagUserChoice = false;
	}
	if(flagUserChoice)
	{ 
		fileOut.open(fOutName.c_str());
		if (fileOut.is_open())
			fileOut << strStream.str();
		fileOut.close();
	}

	return 0;
}