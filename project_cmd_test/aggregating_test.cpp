#include "aggregating_test.hpp"
#include "aggregating.hpp" 

TEST(FunctionalityOfTheAggregating, SumAllVectorElementsWithEmptyContainerVector) {
	aggregating<int> aggr;
	std::vector<int> xs{};

	auto res = aggr.vectorSum(xs);

	ASSERT_EQ(0, res);
}


TEST(FunctionalityOfTheAggregating, SumAllVectorElementsWhenElementsOfTheVectorCanBeNegative) {
	aggregating<int> aggr;
	std::vector<int> xs{1, -3};

	auto res = aggr.vectorSum(xs);

	ASSERT_EQ(-2, res);
}

TEST(FunctionalityOfTheAggregating, SumAllArrayElementsWhenAllElementsAreNegativeNumbersUsingTheTemplateFunction) {
	aggregating<int> aggr;
	aggr.initial_state_res = 0;

	std::array<int, 2> xs{ -5, -3 };

	auto bound_add = std::bind(&aggregating<int>::add, &aggr, std::placeholders::_1, std::placeholders::_2);
	auto res = aggr.aggregate(xs, bound_add);

	ASSERT_EQ(-8, res);
}

TEST(FunctionalityOfTheAggregating, MulAllVectorElementsWhenAllElementsAreNegativeNumbersUsingTheTemplateFunction) {
	aggregating<int> aggr;
	aggr.initial_state_res = 1;

	std::vector<int> xs{ -2, -5};

	auto bound_add = std::bind(&aggregating<int>::mul, &aggr, std::placeholders::_1, std::placeholders::_2);
	auto res = aggr.aggregate(xs, bound_add);

	ASSERT_EQ(10, res);
}

TEST(FunctionalityOfTheAggregating, MulAllVectorElementsFromGivenStartingPosition) {
	aggregating<int> aggr;
	constexpr int start_pos = 10;
	std::vector<int> xs{ 1, 2, 3, 4};

	auto bound_add = std::bind(&aggregating<int>::mul, &aggr, std::placeholders::_1, std::placeholders::_2);
	auto res = aggr.aggregate(xs, bound_add, start_pos);

	ASSERT_EQ(240, res);
}

TEST(FunctionalityOfTheAggregating, SumAllVectorElementsUsingTheRecursiveFunction) {
	aggregating<int> aggr;
	constexpr int start_pos = 0;
	std::vector<int> xs{ 1, 2, 3, 4 };

	auto bound_add = std::bind(&aggregating<int>::add, &aggr, std::placeholders::_1, std::placeholders::_2);
	auto res = aggr.aggregate_special_form_for_recursive(xs, bound_add, start_pos);

	ASSERT_EQ(10, res);
}