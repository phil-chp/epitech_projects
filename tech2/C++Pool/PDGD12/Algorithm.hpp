/*
** EPITECH PROJECT, 2022
** PDG-D12 (Workspace)
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
# define ALGORITHM_HPP_

template<typename T>
void swap(T &a, T &b)
{
    T c = b;
    b = a;
    a = c;
}

template<typename T>
const T min(const T a, const T b)
{
    return (a < b ? a : b);
}

template<typename T>
const T max(const T a, const T b)
{
    return (a < b ? b : a);
}

template<typename T>
const T clamp(const T x, const T min, const T max)
{
    return (x < min ? min : (x < max ? x : max));
}

#endif /* !ALGORITHM_HPP_ */
