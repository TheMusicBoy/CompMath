#include <cmath>
#include <controllers/calc.hpp>

namespace ctrl {

////////////////////////////////////////////////////////////////
/// LiOperator implementation
////////////////////////////////////////////////////////////////

double LiOperator::get_element(double pos, int index,
                               const std::vector<int>& elements) const {
    double value = data_.at(index).second;
    double top = 1, bottom = 1;

    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == index)
            continue;

        top *= (pos - data_.at(elements[i]).first);
        bottom *= (data_.at(index).first - data_.at(elements[i]).first);
    }

    return value * (top / bottom);
}

std::vector<int> LiOperator::get_nearest_points(double pos) const {
    int left = 0, right = data_.size() - 1;

    while (right - left > pow_)
        if (std::abs(data_.at(left).first - pos) <
            std::abs(data_.at(right).first - pos))
            right--;
        else
            left++;

    std::vector<int> result;
    for (int i = left; i <= right; i++) result.push_back(i);

    return result;
}

//----------------------------------------------------------------

LiOperator::LiOperator(size_t pow) : pow_(pow) {}

LiOperator::LiOperator(const LiOperator& other) = default;

LiOperator::LiOperator(LiOperator&& other) = default;

LiOperator::~LiOperator() = default;

//----------------------------------------------------------------

LiOperator& LiOperator::operator=(const LiOperator& other) = default;

LiOperator& LiOperator::operator=(LiOperator&& other) = default;

//----------------------------------------------------------------

void LiOperator::setData(const mdl::Data& data) { data_ = data; }

double LiOperator::operator()(double value) const {
    double result           = 0;
    std::vector<int> points = get_nearest_points(value);

    for (int i = 0; i < points.size(); ++i)
        result += get_element(value, points[i], points);

    return result;
}

}  // namespace ctrl