#include <iostream>
#include <cstdio>

using namespace std;

char wejscie[100000000];

int main()
{
	int wyraz,
		poprzedni=0,
		monotonicznosc=0,
		dlugoscCiagu=0,
		maxDlugosc=0,
		dlugoscStaly=0,
		i=0;
	long long sumaCiagu=0,
			  maxSuma=0,
			  sumaStaly=0;
	gets(wejscie);
	while (wejscie[i]!=0)
	{
		for (wyraz=0;wejscie[i]>='0' && wejscie[i]<='9';i++)
			wyraz=wyraz*10+wejscie[i]-'0';
		if (wejscie[i]==' ')
			i++;
		if (wyraz==poprzedni)
		{
			dlugoscCiagu++;
			sumaCiagu+=wyraz;
			sumaStaly+=wyraz;
			dlugoscStaly++;
		}
		else if (wyraz>poprzedni)
		{
			if (monotonicznosc==1)
			{
				dlugoscCiagu++;
				sumaCiagu+=wyraz;
			}
			else
			{
				if (dlugoscStaly==0 && poprzedni!=0)
				{
					dlugoscCiagu=2;
					sumaCiagu=poprzedni+wyraz;
				}
				else
				{
					dlugoscCiagu=dlugoscStaly+1;
					sumaCiagu=sumaStaly+wyraz;
				}
				monotonicznosc=1;
			}
			dlugoscStaly=1;
			sumaStaly=wyraz;
		}
		else
		{
			if (monotonicznosc==0)
			{
				dlugoscCiagu++;
				sumaCiagu+=wyraz;
			}
			else
			{
				if (dlugoscStaly==0 && poprzedni!=0)
				{
					dlugoscCiagu=2;
					sumaCiagu=poprzedni+wyraz;
				}
				else
				{
					dlugoscCiagu=dlugoscStaly+1;
					sumaCiagu=sumaStaly+wyraz;
				}
				monotonicznosc=0;
			}
			dlugoscStaly=1;
			sumaStaly=wyraz;
		}
		if (dlugoscCiagu>maxDlugosc)
		{
			maxDlugosc=dlugoscCiagu;
			maxSuma=sumaCiagu;
		}
		poprzedni=wyraz;
	}
	cout<<maxDlugosc<<" "<<maxSuma;
	return 0;
}
