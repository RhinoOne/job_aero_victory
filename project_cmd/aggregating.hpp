#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

template <typename T>
class aggregating {
public:
	T vectorSum(const std::vector<T>& xs) {
		T res = 0;

		std::for_each(xs.cbegin(), xs.cend(), [&](const T& v) {res += v; });

		return res;
	}

	template <typename CollectionType>
	T aggregate(const CollectionType& xs, std::function<void(T&, T)> func) {
		T res = initial_state_res;

		std::for_each(xs.cbegin(), xs.cend(), [&](const T& v) {func(res, v); });

		return res;
	}

	template <typename CollectionType>
	T aggregate(const CollectionType& xs, std::function<void(T&, T)> func, const T init_stat_val) {
		T res = init_stat_val;

		std::for_each(xs.cbegin(), xs.cend(), [&](const T& v) {func(res, v); });

		return res;
	}

	template <typename CollectionType>
	T aggregate_special_form_for_recursive(const CollectionType& xs, std::function<void(T&, T)> func, T init_stat_val) {
		return aggregate_recursive(xs.begin(), xs.end(), func, init_stat_val);
	}

	template <typename CollectionIterType>
	T aggregate_recursive(CollectionIterType current, CollectionIterType end, std::function<void(T&, T)> func, T& result) {
		if (current == end)
			return result;

		func(result, *current);

		return aggregate_recursive(std::next(current), end, func, result);
	}

	void add(T& res, T value) {
		res += value;
	}

	void mul(T& res, T value) {
		res *= value;
	}

public:
	T initial_state_res;
};
