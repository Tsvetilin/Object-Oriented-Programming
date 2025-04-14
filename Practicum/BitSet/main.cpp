#include <iostream>

#include "BitSet.h"

int main()
{
	BitSet b1(10);
	
	b1.add(3);
	b1.add(7);
	b1.add(8);

	BitSet b2(21);
	
	b2.add(2);
	b2.add(3);
	b2.add(8);
	b2.add(13);
	b2.add(15);

	BitSet b3 = unify(b1, b2);

	b3.print();

	BitSet b4 = intersect(b1, b2);

	b4.print();

	return 0;
}