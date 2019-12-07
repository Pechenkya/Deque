#include <iostream>
#include "Deque.h"

int main()
{
	Deque<int> deq;
	for(int i = 0; i < 12; i++)
		deq.push_back(i);
	deq.emplace_front(15);

	for (int i = 0; i < 13; i++)
		std::cout << deq[i] << " ";

	std::cout << std::endl;

	auto itr = deq.begin();
	itr++;
	itr++;
	itr++;

	deq.emplace(itr, 36);

	for (auto t : deq)
	{
		std::cout << t << " ";
	}
}