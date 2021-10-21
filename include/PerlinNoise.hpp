#pragma once

#include <random>
#include <algorithm>
#include <numeric>

#include <AFunction.hpp>

template<typename T, typename W>
static constexpr T	lerp(T a, T b, W weight)
{ return a + (b - a) * weight; }

template<typename T>
static constexpr T	fade(T value)
{ return value * value * value * (value * (value * 6 - 15) + 10); }

template<typename In = float, typename Out = float, typename F = float>
class PerlinNoise:	public AFunction<3, In, Out>
{
protected:
	typedef AFunction<3, In, Out>	function_t;
	typedef F						float_t;
	typedef uint8_t					hash_t;

	typedef Vector<2, float_t>		vec_f_t;
	typedef Vector<2, int>			vec_i_t;
	typedef Vector<2, unsigned>		vec_u_t;
	//typedef Vector<1 << 3, int>		cube_t;

	std::vector<hash_t>				p;

	constexpr float_t	gradient(hash_t hash, float_t x, float_t y) const
	{
		const hash_t	h = hash & 15;
		const float_t	u = h < 8 ? x : y;
		const float_t	v = h < 4 ? y : h == 12 || h == 14 ? x : 0;

		return ((h & 1) == 0 ? u : -u) + ((h %2) == 0 ? v : -v);
	}

public:
	typedef typename function_t::pos_t	pos_t;

	PerlinNoise(unsigned int seed = 420)
	{
		std::default_random_engine engine(seed);

		p.resize(256);

		std::iota(p.begin(), p.end(), 0);

		std::shuffle(p.begin(), p.end(), engine);

		p.insert(p.end(), p.begin(), p.end());
	}

	Out	operator()(const pos_t &pos) const
	{
		const vec_i_t	floored(pos.floor());
		const vec_i_t	cubePos(floored & 255);
		vec_f_t			relative(pos - floored);
		vec_f_t			faded(pos - floored);
		vec_i_t			hashA;
		vec_i_t			hashB;

		hashA[0] = p[cubePos[0]] + cubePos[1];
		hashA[1] = p[hashA[0]];// + cubePos[2];
		//hashA[2] = p[hashA[0] + 1] + cubePos[2];

		hashB[0] = p[cubePos[0] + 1] + cubePos[1];
		hashB[1] = p[hashB[0]];// + cubePos[2];
		//hashB[2] = p[hashB[0] + 1] + cubePos[2];

		std::transform
		(
			relative.begin(), relative.end(),
			faded.begin(),
			&fade<float_t>
		);

		float res = lerp
		(
			lerp
			(
				lerp
				(
					gradient(p[hashA[1]], relative[0], relative[1]),
					gradient(p[hashB[1]], relative[0] - 1, relative[1]),
					faded[0]
				),
				lerp
				(
					gradient(p[0], relative[0], relative[1] - 1),
					gradient(p[0], relative[0] - 1, relative[1] - 1),
					faded[0]
				),
				faded[1]
			),
			lerp
			(
				lerp
				(
					gradient(p[hashA[1] + 1], relative[0], relative[1] - 1),
					gradient(p[hashB[1] + 1], relative[0] - 1, relative[1] - 1),
					faded[0]
				),
				lerp
				(
					gradient(p[0 + 1], relative[0], relative[1] - 1),
					gradient(p[0 + 1], relative[0] - 1, relative[1] - 1),
					faded[0]
				),
				faded[1]
			),
			1
		);

		return (res + 1.0) / 2.0;
	}
};
