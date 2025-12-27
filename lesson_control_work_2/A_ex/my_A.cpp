#include <iostream>
#include <string>

struct	Query
{
	std::string text;
	int	freq;
};

void	quickSort(Query q[], int l, int r)
{
	Query	pivot;
	int		i, j;
	int		cmp;
	Query	temp;

	if (l >= r)
		return ;
	pivot = q[(l + r) / 2];
	i = l, j = r;
	while (i <= j)
	{
		cmp = 0;
		if (q[i].freq > pivot.freq)
			cmp = -1;
		else if (q[i].freq < pivot.freq)
			cmp = 1;
		else
			cmp = q[i].text.compare(pivot.text);
		while (cmp < 0)
		{
			i++;
			cmp = 0;
			if (q[i].freq > pivot.freq)
				cmp = -1;
			else if (q[i].freq < pivot.freq)
				cmp = 1;
			else
				cmp = q[i].text.compare(pivot.text);
		}
		cmp = 0;
		if (q[j].freq > pivot.freq)
			cmp = -1;
		else if (q[j].freq < pivot.freq)
			cmp = 1;
		else
			cmp = q[j].text.compare(pivot.text);
		while (cmp > 0)
		{
			j--;
			cmp = 0;
			if (q[j].freq > pivot.freq)
				cmp = -1;
			else if (q[j].freq < pivot.freq)
				cmp = 1;
			else
				cmp = q[j].text.compare(pivot.text);
		}
		if (i <= j)
		{
			temp = q[i];
			q[i] = q[j];
			q[j] = temp;
			i++;
			j--;
		}
	}
	quickSort(q, l, j);
	quickSort(q, i, r);
}

int	main(void)
{
	int		n;
	Query	q[1001];
	int		q_cnt;
	int		found;
	int		out;

	std::cin >> n;
	std::cin.ignore();
	q_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		std::string line;
		std::getline(std::cin, line);
		found = 0;
		for (int j = 0; j < q_cnt; j++)
		{
			if (q[j].text == line)
			{
				q[j].freq++;
				found = 1;
				break ;
			}
		}
		if (found == 0)
		{
			q[q_cnt].text = line;
			q[q_cnt].freq = 1;
			q_cnt++;
		}
	}
	quickSort(q, 0, q_cnt - 1);
	out = q_cnt;
	if (out > 10)
		out = 10;
	for (int i = 0; i < out; i++)
	{
		std::cout << q[i].text << std::endl;
	}
	return (0);
}
