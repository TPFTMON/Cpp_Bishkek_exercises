// #include <iostream>
// #include <string>

// std::string normalize(const std::string &s)
// {
// 	std::string res = "";
// 	for (int i = 0; i < s.length(); i++)
// 	{
// 		res += s[i];
// 		if (s[i] == '*')
// 		{
// 			while (i + 1 < s.length() && s[i + 1] == '*')
// 				i++;
// 		}
// 	}
// 	return (res);
// }

// int	main(void)
// {
// 	std::string s1, s2;
// 	std::getline(std::cin, s1);
// 	std::getline(std::cin, s2);
// 	std::string n1 = normalize(s1);
// 	std::string n2 = normalize(s2);
// 	if (n1 == n2)
// 	{
// 		std::cout << "yes" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "no" << std::endl;
// 	}
// 	return (0);
// }
