#include <iostream>

int	gcd(int a, int b)
{
	std::cout << "GCD(" << a << "," << b << ")\n";
	if (a == 0 || b == 0)
		return (a + b);
	return (gcd(abs(a - b), std::min(a, b)));
}

int	main(void)
{
	int	mn;
	int	mx;
	int	r;

	int a, b;
	std::cin >> a >> b;
	mn = std::min(a, b);
	mx = std::max(a, b);

	r = gcd(mx - mn, mn);
	std::cout << "GCD(" << a << "," << b << ")=" << r << std::endl;
}
