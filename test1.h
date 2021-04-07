#ifndef TEST1_H
#define TEST1_H

int& add(const int& a, const int& b)
{
	int temp = a + b;
	return temp;
}
#endif
