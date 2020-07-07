void multiply(const vector<double>& arry1 ,vector<double>& arry2)
{
	int length1 = arry1.size();
	int length2 = arry2.size();

	arry2[0] = 1;
	for(int i=1;i<length2;i++)
	{
		arry2[i] = arry[i-1]*arry1[i-1];
	}

	double temp = 1;
	for(int i=length2-1;i>=0;i--)
	{
		arry2[i] *= temp;
		temp = temp*arry1[i]
	}
}
