#pragma once

#include <iostream>
using namespace std;


	class Hash
	{
	public:
		string getHash(string userString, unsigned lenghtHash);

	private:
		string hash;
		int receivingExistCode(int x);
		
		int controlSum(string str);
	};
	int Hash::receivingExistCode(int x)
	{
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97))))
		{
			if (x < 48)
				x += 24;
			else
				x -= 47;
		}
		return x;
	}
	int Hash::controlSum(string str)
	{
		unsigned int sault = 0, strlen = 0;

		for (; strlen < str.size(); strlen++)
		{
			sault += int(str[strlen]);
		}
		return sault;
		/*string sum;

		str += sault;

		if (str.size() % 2 != 0)
			str += 's';

		for (int i = 0; i < str.size(); i += 2)
		{
			int mult = str[i] * str[i + 1];
			int div = str[i] / str[i + 1];

			sum += receivingExistCode(mult);
			sum += receivingExistCode(div);

		}
		return sum;*/
	}
	string Hash::getHash(string userString, unsigned lenghtHash)
	{
		if (lenghtHash > 3)
		{
			unsigned minLen = 2;
			unsigned realminLen = 0;

			unsigned int originalSault = controlSum(userString);
			unsigned int originalLengthStr = (userString.size());

			while (minLen <= lenghtHash)//2<=5 => minlen realminlen = 8
				realminLen = (minLen *= 2);

			while (minLen < originalLengthStr)
				minLen *= 2;
			if ((minLen - originalLengthStr) < minLen)
				minLen *= 2;

			int addCount = minLen - originalLengthStr;

			for (int i = 0; i < addCount; i++)
			{
				userString += receivingExistCode(userString[i] + userString[i + 1]);
			}
			//получаем максимальную соль
			int maxSault = controlSum(userString);
			int maxLengthStr = (userString.size());

			//Определение степени сжатия
			while (userString.size() != realminLen)
			{
				for (int i = 0, center = userString.size() / 2; i < center; i++)
				{
					hash += receivingExistCode(userString[center - i] + userString[center + i]);
				}
				userString = hash;
				hash.clear();
			}
			//приведение к нужной длинне
			unsigned int rem = realminLen - lenghtHash;
			for (unsigned int i = 0, countCompress = realminLen / rem; hash.size() < (lenghtHash - 4);i++)
			{
				if (i % countCompress == 0)
					hash += receivingExistCode(userString[i] + userString[++i]);
				else
					hash += userString[i];
			}

			hash += receivingExistCode(originalSault);
			hash += receivingExistCode(originalLengthStr);
			//добавление максимальных солей
			hash += receivingExistCode(maxSault);
			hash += receivingExistCode(maxLengthStr);
		}
		return hash;
	}
