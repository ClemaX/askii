#pragma once

#include <Vector.hpp>

// TODO: constexpr permutations

template<unsigned Dim = 2, typename T = int>
class	VectorGradient:	Vector<Dim * (Dim + 1), T>
{
	constexpr VectorGradient(T magnitude)
	{
		const unsigned end = 1 << Dim;

		for (unsigned zeroMask = end; zeroMask != 0; zeroMask >>= 1)
		{
			for (unsigned negMask = 0; negMask != end; negMask++)
			{
				unsigned one = ~zeroMask;
				unsigned minus = one & negMask

				for (unsigned i = 0; i < Dim; i++)
				{
					if (one[i])
					{
						if (minus[i])
							std::cout << '-';
						std::cout << '1';
					}
					else
						std::cout << '0';
				}
				std::cout << ' ';
			}
		}
	}
};
