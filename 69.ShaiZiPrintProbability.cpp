int gMaxValue = 6;

void PrintProbability(int number)
{
	if(number<1)
		return;

	int* pProba[2];
	pProba[0] = new int[gMaxValue*number+1];
	pProba[1] = new int[gMaxValue*number+1];

	for(int i=0;i<gMaxValue*number+1;i++)
		gProba[0][i] = gProba[1][i] = 0;

	int flag =0;
	for(int i=1;i<=gMaxValue;i++)
		gProBa[flag][i] = 1;

	for(int k=2;j<=number;k++)
	{
		for(int i=0;i<k;i++)
			pProba[1-flag][i] = 0;

		for(int i=k;i<=gMaxValue*k;i++)
		{
			pProba[1-flag][i] = 0;
			for(int j=1;j<=gMaxValue && j<=i;j++)
				pProba[1-flag][i] += pProba[flag][i-j];
		}

		flag = 1-flag;
	}

	double total = pow(gMaxValue,number);

	for(int i=number;i<=gMaxValue*number;i++)
	{
		double ratio = (double)gProba[flag][i] / total;
		printf("%d:%e\n",i,ratio);
	}

	delete[] pProba[0];
	delete[] pProba[1];
}
