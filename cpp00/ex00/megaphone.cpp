#include <iostream> // preprocess statement for input/output stream library
#include <string>	// preprocess statement for input/output stream library
// alt + shift + i to auto indent
// alt + shift + f to format the code

int main(int argc, char **argv)
{
	if (argc == 1) // or message is empty at every argc
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			char *string = argv[i];
			if (string)
			{
				for (int j = 0; string[j] != '\0'; j++)
					std::cout << (char)toupper(string[j]);
				if (argc > 2)
					std::cout << " "; /* adding space if there is more than 1*/
			}
		}
	}
	return 0;
}
