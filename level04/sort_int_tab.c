void	sort_int_tab(int *tab, unsigned int size)
{
	int		tmp;
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j += 1;
		}
		i += 1;
	}
}
