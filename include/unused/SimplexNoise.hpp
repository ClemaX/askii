#pragma once

#include <numeric>

#include <cmath>


#include <AFunction.hpp>

template<unsigned Dim = 2, typename In = int, typename Out = int, typename F = float>
class SimplexNoise:	public AFunction<Dim, In, Out>
{
public:
	typedef AFunction<Dim, In, Out>		function_t;

	typedef typename function_t::pos_t	pos_t;
	typedef Vector<pos_t::dim, int>		pos_i_t;
	typedef Vector<pos_t::dim, u_int>	pos_u_t;
	typedef Vector<pos_t::dim, F>		pos_f_t;

/*
	typedef Vector<Dim, int>			vec_i_t;
	typedef Vector<Dim, unsigned>		vec_u_t;
	typedef Vector<Dim, F>				vec_f_t;
*/

	typedef Vector<Dim, pos_i_t>	simplex_t;

	Out operator()(pos_t const &pos) const
	{
		// Skew input coordinates
		const F			skewFactor = (std::sqrt((F)Dim + 1) - 1) / Dim;
		const F			unskewFactor = (1 - 1 / std::sqrt((F)Dim + 1)) / Dim;

		// TODO: Maybe need to floor (for negative values)
		const pos_i_t	skewed(pos + pos.sum() * skewFactor);

		// Unskew
		const pos_f_t	unskewed(skewed - skewed.sum() * unskewFactor);
		const pos_f_t	skewDistance(pos - unskewed);

		simplex_t	simplex;

		// Subdivide
		{
			// Get the coordinates indices ordered by their size
			pos_u_t	indices;
			pos_i_t	vertex(skewed);

			// Initializing { 0..Dim }
			std::iota(indices.begin(), indices.end(), 0);

			std::sort
			(
				indices.begin(), indices.end(),
				std::greater()
			);

			simplex[0] = vertex;

			std::transform
			(
				indices.begin(), indices.end(),
				simplex.begin() + 1,
				[&](unsigned i) { vertex[i]++; return vertex; }
			);
		}

		// Select gradient
		{
			pos_i_t	significant(skewed & 255);
			/*
			int gi0 = perm[ii+perm[jj+perm[kk+perm[ll]]]] % 32;
			int gi1 = perm[ii+i1+perm[jj+j1+perm[kk+k1+perm[ll+l1]]]] % 32;
			int gi2 = perm[ii+i2+perm[jj+j2+perm[kk+k2+perm[ll+l2]]]] % 32;
			int gi3 = perm[ii+i3+perm[jj+j3+perm[kk+k3+perm[ll+l3]]]] % 32;
			int gi4 = perm[ii+1+perm[jj+1+perm[kk+1+perm[ll+1]]]] % 32;
			*/

			// The permutation table hashes the significant bits of the skewed coordinates
			/*
			std::transform
			(
				indices.begin()
			)
			*/
		}

		std::cerr << "Skewed: " << skewed << ", Unskewed: " << unskewed << std::endl;

		return 0;
	}

	SimplexNoise()
	{ }

	~SimplexNoise()
	{ }
};

