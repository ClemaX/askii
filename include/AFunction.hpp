#pragma once

#include <Vector.hpp>

template<unsigned Dim = 2, typename In = int, typename Out = int>
class AFunction
{
	static_assert(Dim > 1, "Function dimension count must be greater than 1!");

public:
	typedef Vector<Dim - 1, In> pos_t;

	virtual Out	operator()(const pos_t &pos) const = 0;
};
