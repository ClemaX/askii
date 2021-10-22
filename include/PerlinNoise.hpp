#pragma once

#include <random>
#include <algorithm>
#include <numeric>

#include <ANoiseFunction.hpp>
#include <lerp.hpp>

template<typename T>
static constexpr T	fade(T value)
{ return value * value * value * (value * (value * 6 - 15) + 10); }

template<typename In = float, typename Out = float, typename F = float>
class PerlinNoise:	public ANoiseFunction<3, In, Out, F, unsigned>
{
protected:
	typedef ANoiseFunction<3, In, Out, F>	function_t;

public:
	typedef typename function_t::seed_t		seed_t;
	typedef typename function_t::pos_t		pos_t;

protected:
	typedef typename function_t::float_t	float_t;
	typedef uint8_t							hash_t;

	typedef typename function_t::pos_f_t	pos_f_t;
	typedef typename function_t::pos_i_t	pos_i_t;
	typedef typename function_t::pos_u_t	pos_u_t;

	std::vector<hash_t>	p;
	seed_t				seed;

	constexpr float_t	gradient(hash_t hash, float_t x, float_t y) const
	{
		const hash_t	h = hash & 15;
		const float_t	u = h < 8 ? x : y;
		const float_t	v = h < 4 ? y : h == 12 || h == 14 ? x : 0;

		return ((h & 1) == 0 ? u : -u) + ((h % 2) == 0 ? v : -v);
	}

public:
	PerlinNoise(seed_t seed = 1)
		:	p(512)
	{ setSeed(seed); }

	void	setSeed(seed_t newSeed)
	{
		if (newSeed != seed)
		{
			std::default_random_engine	engine(seed);
			const std::vector<hash_t>::iterator	half(p.begin() + 256);

			seed = newSeed;

			std::iota(p.begin(), half, 0);

			std::shuffle(p.begin(), half, engine);

			p.insert(half, p.begin(), half);
		}
	}

	Out	operator()(const pos_t &pos) const
	{
		const pos_i_t	floored(pos.floor());
		const pos_i_t	cubePos(floored & 255);
		pos_f_t			relative(pos - floored);
		pos_f_t			faded(pos - floored);
		pos_i_t			hashA;
		pos_i_t			hashB;

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
