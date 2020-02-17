#include<iostream>
#include<string>
using namespace std;
int Sub(int* num1, int* num2, int len1, int len2)
{
	if (len1 < len2)
		return -1;
	for (int i = len1 - 1;i >= 0;i--)
	{
		if (num1[i] > num2[i])
			break;
		if (num1[i] < num2[i])
			return -1;
	}
	int res = 0;
	int tmp = 0;
	for (int i = 0;i < len1;i++)
	{
		tmp = num1[i] - num2[i] + 10 + res;
		num1[i] = tmp % 10;
		res = tmp / 10-1;
	}
	for (int i = len1 - 1;i >= 0;i--)
	{
		if (num1[i] != 0)
			return i + 1;
	}
	return 0;
}
int main()
{
	int len = 0;
	int len1 = 0;
	int len2 = 0;
	int num1[1000] = {0};
	int num2[1000] = { 0 };
	int res[1000] = { 0 };
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	len1 = str1.size();
	len2 = str2.size();
	len = len1 - len2;
	if (len1 < len2)
	{
		cout << "0" << " " << "0" << endl;
		return 0;
	}
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	for (int i = 0;i < len1;i++)
	{
		num1[i] = str1[i] - '0';
	}
	for (int i = 0;i < len2;i++)
	{
		num2[i] = str2[i] - '0';
	}
	for (int i = len1-1;i >= 0;i--)
	{
		if (i >= len)
			num2[i] = num2[i - len];
		else
			num2[i] = 0;
	}
	len2 = len1;
	int datelen = 1;
	for (int i = 0;i <= len;i++)
	{
		while ((datelen = Sub(num1, num2 + i, len1, len2-i)) >= 0)
		{
			len1 = datelen;
			res[len - i]++;
		}
	}
	for (int i = len;i >= 0;i--)
	{
		if (res[i] != 0)
		{
			for (int j = i;j >= 0;j--)
			{
				cout << res[j];
			}
			break;
		}
	}
	cout << endl;
	for (int i = 1000 - 1;i >= 0;i--)
	{
		if (num1[i] != 0)
		{
			for (int j = i;j >= 0;j--)
			{
				cout << num1[j];
			}
		}
		if (i == 0 && num1[i] == 0)
			cout << 0;
   }
	return 0;
}