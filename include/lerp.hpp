#pragma once

template<typename T, typename W>
static constexpr T	lerp(T a, T b, W weight)
{ return a + (b - a) * weight; }
