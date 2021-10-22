#pragma once

#include <AFunction.hpp>

template<unsigned Dim, typename In = float, typename Out = float, typename F = float, typename S = unsigned>
class ANoiseFunction:	public AFunction<Dim, In, Out>
{
protected:
	typedef AFunction<Dim, In, Out>	function_t;
	typedef F						float_t;

public:
	typedef typename function_t::pos_t		pos_t;
	typedef S								seed_t;

protected:
	typedef Vector<pos_t::dim, float_t>		pos_f_t;
	typedef Vector<pos_t::dim, int>			pos_i_t;
	typedef Vector<pos_t::dim, unsigned>	pos_u_t;

public:

	virtual void	setSeed(S seed) = 0;
};
