#include <models/data.hpp>

namespace mdl {

////////////////////////////////////////////////////////////////
/// Data implementation
////////////////////////////////////////////////////////////////

Data::Data() = default;

Data::Data(const std::vector<double>& x_data, const std::vector<double>& y_data)
    : x_data_(x_data), y_data_(y_data) {}

Data::Data(std::vector<double>&& x_data, std::vector<double>&& y_data)
    : x_data_(std::move(x_data)), y_data_(std::move(y_data)) {}

Data::Data(const std::vector<std::pair<double, double>>& data) {
    for (auto i = data.rbegin(); i != data.rend(); ++i) {
        x_data_.push_back(i->first);
        y_data_.push_back(i->second);
    }
}

Data::Data(const Data& data) = default;

Data::Data(Data&& data) = default;

Data::~Data() = default;

//----------------------------------------------------------------

Data& Data::operator=(const Data& data) {
    x_data_ = data.x_data_;
    y_data_ = data.y_data_;
    return *this;
}

Data& Data::operator=(Data&& data) {
    x_data_ = std::move(data.x_data_);
    y_data_ = std::move(data.y_data_);
    return *this;
}

//----------------------------------------------------------------

const std::vector<double>& Data::getXData() const {
    return x_data_;
}

const std::vector<double>& Data::getYData() const {
    return y_data_;
}


void Data::setXData(const std::vector<double>& x_data) {
    x_data_ = x_data;
}

void Data::setYData(const std::vector<double>& y_data) {
    y_data_ = y_data;
}

void Data::setXData(std::vector<double>&& x_data) {
    x_data_ = std::move(x_data);
}

void Data::setYData(std::vector<double>&& y_data) {
    y_data_ = std::move(y_data);
}

void Data::setXData(size_t index, double x_data) {
    x_data_[index] = x_data;
}

void Data::setYData(size_t index, double y_data) {
    y_data_[index] = y_data;
}

void Data::setElement(size_t index, double x_data, double y_data) {
    x_data_[index] = x_data;
    y_data_[index] = y_data;
}

void Data::setElement(size_t index, std::pair<double, double> element) {
    x_data_[index] = element.first;
    y_data_[index] = element.second;
}


void Data::addData(double x, double y) {
    x_data_.push_back(x);
    y_data_.push_back(y);
}

void Data::addData(const std::pair<double, double>& data) {
    x_data_.push_back(data.first);
    y_data_.push_back(data.second);
}

void Data::removeData(size_t index) {
    x_data_.erase(x_data_.begin() + index);
    y_data_.erase(y_data_.begin() + index);
}

void Data::clear() {
    x_data_.clear();
    y_data_.clear();
}


Bounds Data::getBounds() const {
    Bounds result;

    for (size_t i = 0; i < size(); ++i)
        result += at(i);
    
    return result;
}

std::pair<double, double> Data::at(size_t index) const {
    return std::make_pair(x_data_[index], y_data_[index]);
}

size_t Data::size() const {
    return std::min(x_data_.size(), y_data_.size());
}

bool Data::empty() const {
    return x_data_.empty() || y_data_.empty();
}

}  // namespace mdl