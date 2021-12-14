#include<iostream>
using namespace std;
void enterarray(int*& a, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		cout << "enter a[" << i << "]" ;
		cin >> a[i];
	}
}
void outputarray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " " << a[i];
	}
}
int sumofnumbers(int n)
{
	int s = 0;
	int z;
	while (n != 0)
	{
		z = n % 10;
		s += z;
		n /= 10;
	}
	return s;
}
void permutation(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sortdescending(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sumofnumbers(a[i]) < sumofnumbers(a[j]))
			{
				permutation(a[i], a[j]);
			}
		}

	}
}
int splitthelastdigit(int& n)
{
	return n % 10;
}
void sortdescendinglastdigit(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (splitthelastdigit(a[i]) < splitthelastdigit(a[j]))
			{
				permutation(a[i], a[j]);
			}
		}

	}
}
void sortascendinglastdigit(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (splitthelastdigit(a[i]) > splitthelastdigit(a[j]))
			{
				permutation(a[i], a[j]);
			}
			else if (splitthelastdigit(a[i]) == splitthelastdigit(a[j]))
			{
				sortdescendinglastdigit(a, n);
			}
		}

	}
}
int main()
{
	int n;
	
	cout << "enter ele:";
	cin >> n;
	int* a = new int[n];
	int chose;
	cout << "------------------------menu------------------" << endl;
	cout << "\n1.enter arr:";
	cout << "\n2.output arr:";
	cout << "\n3.sort by sum of digits in even positions";
	cout << "\n4.sort array:";
	cout << "\n5.exit";
	do
	{
		cout << "enter chose:";
		cin >> chose;
		switch (chose)
		{
		case 1:enterarray(a, n);
			break;
		case 2:enterarray(a, n); outputarray(a, n); cout << endl; break;
		case 3:enterarray(a, n); cout << "array after sorting by sum of digits!";
			sortdescending(a, n);
			outputarray(a, n);
			cout << endl;
			break;
		case 4:enterarray(a, n); cout << "array after sorting ascending last digit";
			sortascendinglastdigit(a, n);
			outputarray(a, n);
			cout << endl;
			break;
		case 5:exit(0); break;
		default:cout << "illegal";
		}
	} while (chose!=1|| chose!=2||chose!=3|| chose != 4|| chose != 5);
		
	delete[]a;
}

