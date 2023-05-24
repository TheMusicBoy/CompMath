#ifndef _CONTROLLERS_CALC_HPP_
#define _CONTROLLERS_CALC_HPP_

#include <models/data.hpp>

namespace ctrl {

class LiOperator {
 private:
	size_t pow_;
	mdl::Data data_;

	double get_element(double pos, int index, const std::vector<int>& elements) const;

	std::vector<int> get_nearest_points(double pos) const;

 public:
	// Constructor with pow
	LiOperator(size_t pow = 1);
	// Copy constructor
	LiOperator(const LiOperator& other);
	// Move constructor
	LiOperator(LiOperator&& other);
	// Destructor
	~LiOperator();

	// Assignment operator

	// Copy assignment operator
	LiOperator& operator=(const LiOperator& other);
	// Move assignment operator
	LiOperator& operator=(LiOperator&& other);
	
	// Set data
	void setData(const mdl::Data& data);

	// Get data in dot
	double operator()(double value) const;
	
};

} // namespace ctrl

#endif // _CONTROLLERS_CALC_HPP_