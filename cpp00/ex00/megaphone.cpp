#include <iostream>
// alt + shift + i to auto indent
// alt + shift + f to format the code

int main(int argc, char **argv)
{
	if (argc == 1) // or message is empty at every argc
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i <= argc; i++)
		{
			if (argv[i])
			{
				for (int j = 0; argv[i][j] != '\0'; j++)
					std::cout << (char)toupper(argv[i][j]);
				// std::cout << " "; // unsure if it needs to be here
			}
		}
	}
	return 0;
}
