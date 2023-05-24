#ifndef _MODELS_DATA_HPP_
#define _MODELS_DATA_HPP_

#include <limits>
#include <vector>

namespace mdl {

////////////////////////////////////////////////////////////////
// \brief Object that contains the bounds of data.
////////////////////////////////////////////////////////////////
struct Bounds {
    using limits = std::numeric_limits<double>;

    double x_min = limits::infinity();   // Minimum x-coordinate
    double x_max = -limits::infinity();  // Maximum x-coordinate
    double y_min = limits::infinity();   // Minimum y-coordinate
    double y_max = -limits::infinity();  // Maximum y-coordinate
};

inline Bounds operator+(Bounds a, Bounds b) {
    return {std::min(a.x_min, b.x_min), std::max(a.x_max, b.x_max),
            std::min(a.y_min, b.y_min), std::max(a.y_max, b.y_max)};
}

inline Bounds operator+(Bounds a, std::pair<double, double> b) {
    return {std::min(a.x_min, b.first), std::max(a.x_max, b.first),
            std::min(a.y_min, b.second), std::max(a.y_max, b.second)};
}

inline Bounds& operator+=(Bounds& a, Bounds b) {
    return a = a + b;
}

inline Bounds& operator+=(Bounds& a, std::pair<double, double> b) {
    return a = a + b;
}

////////////////////////////////////////////////////////////////
// \brief Object that represents data.
////////////////////////////////////////////////////////////////
class Data {
 private:
    std::vector<double> x_data_;  // x-coordinates
    std::vector<double> y_data_;  // y-coordinates

 public:
    // Default constructor
    Data();
    // Constructor with copy data in two vectors
    Data(const std::vector<double>& x_data, const std::vector<double>& y_data);
    // Constructor with move data in two vectors
    Data(std::vector<double>&& x_data, std::vector<double>&& y_data);
    // Constructor with data in vector of pairs
    Data(const std::vector<std::pair<double, double>>& data);
    // Copy constructor
    Data(const Data& data);
    // Move constructor
    Data(Data&& data);
    // Destructor
    ~Data();

    // Assignment operators

    // Copy assignment operator
    Data& operator=(const Data& data);
    // Move assignment operator
    Data& operator=(Data&& data);

    // Accessors

    // Get x-coordinates
    const std::vector<double>& getXData() const;
    // Get y-coordinates
    const std::vector<double>& getYData() const;

    // Set x-coordinates with copy
    void setXData(const std::vector<double>& x_data);
    // Set x-coordinates with move
    void setXData(std::vector<double>&& x_data);
    // Set y-coordinates with copy
    void setYData(const std::vector<double>& y_data);
    // Set y-coordinates with move
    void setYData(std::vector<double>&& y_data);

    // Set x-coordinate of element with index
    void setXData(size_t index, double x_data);
    // Set y-coordinate of element with index
    void setYData(size_t index, double y_data);
    // Set element with index from two numbers
    void setElement(size_t index, double x_data, double y_data);
    // set element with index from pair
    void setElement(size_t index, std::pair<double, double> element);

    // Add element to data with two coordinates
    void addData(double x, double y);
    // Add element to data with pair of coordinates
    void addData(const std::pair<double, double>& data);
    // Remove element from data with index
    void removeData(size_t index);
    // Remove all elements from data
    void clear();

    // Get bounds of data
    Bounds getBounds() const;
    // Get element from data with index
    std::pair<double, double> at(size_t index) const;
    // Get size of data
    size_t size() const;
    // Check if data is empty
    bool empty() const;
};

}  // namespace mdl

#endif  // _MODELS_DATA_HPP_