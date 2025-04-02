#pragma once

#include <ANoiseFunction.hpp>

template<typename Fun, unsigned N, typename F = float>
class Octaves:	public Fun
{
	static_assert(N > 0, "Octave count must be greater than 0!");

private:
	typedef F									float_t;
	typedef Fun									function_t;
	typedef typename function_t::seed_t			seed_t;
	typedef typename function_t::pos_t			pos_t;

	typedef std::vector<float_t>				float_container_t;

	float_container_t		amplitudes;
	float_container_t		frequencies;
	float_t					totalAmplitude;

public:
	Octaves(seed_t seed, float_t gain, float_t lacunarity, float_t amplitude = 1, float_t frequency = 1)
		:	function_t(seed), amplitudes(N, amplitude), frequencies(N, frequency), totalAmplitude(0)
	{
		for (unsigned i = 1; i < N; i++)
		{
			amplitude *= gain;
			frequency *= lacunarity;

			totalAmplitude += amplitude;

			amplitudes[i] = amplitude;
			frequencies[i] = lacunarity;
		}
	}

	float_t	operator()(const pos_t &pos) const
	{
		float_t	res = 0;

		for (unsigned i = 0; i < N; i++)
			res += amplitudes[i] * function_t::operator()(pos * frequencies[i]);

		return res / totalAmplitude;
	}

	~Octaves()
	{ }
};
