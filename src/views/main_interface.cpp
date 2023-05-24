#include <cmath>
#include <controllers/calc.hpp>
#include <views/main_interface.hpp>
#include <views/plot.hpp>

namespace vw {

////////////////////////////////////////////////////////////////
/// MainInterface implementation
////////////////////////////////////////////////////////////////

MainInterface::MainInterface(QWidget* parent) : Base(parent) {
    this->setContentsMargins(0, 0, 0, 0);
    this->setSpacing(0);

    nav_bar_.addButton(L"Ничего не делать");

    nav_bar_.addButton(L"по Лагранжу", [this]() {
        std::list<std::pair<mdl::Data, QColor>> data;

        std::function<double(double)> f = [](double x) {
            return x * x - std::sin(3.14 * x);
        };

        std::vector<double> x(100);
        std::vector<double> y(100);

        for (int i = 0; i < 100; i++) x[i] = double(i) / 100 * 0.5 + 0.4;

        for (int i = 0; i < 100; i++) y[i] = f(x[i]);

        data.push_back(std::make_pair(mdl::Data(x, y), Qt::blue));

        std::vector<double> args = {0.53, 0.43, 0.86, 0.67};
        std::sort(args.begin(), args.end());

        mdl::Data arg_points(
            args, std::vector<double>(
                      {f(args[0]), f(args[1]), f(args[2]), f(args[3])}));

        ctrl::LiOperator L(3);
        L.setData(arg_points);

        for (int i = 0; i < 100; i++) y[i] = L(x[i]);
        data.push_back(std::make_pair(mdl::Data(x, y), Qt::red));

        data.push_back(std::make_pair(arg_points, Qt::black));

        this->plot(data);
    });

    this->addLayout(&nav_bar_);
    this->addWidget(&workspace_);
}

MainInterface::~MainInterface() = default;

void MainInterface::plot(const mdl::Data& data) {
    Plot* plot = new Plot(&workspace_);
    plot->draw(data);
    plot->show();
}

void MainInterface::plot(std::list<std::pair<mdl::Data, QColor>> data) {
    Plot* plot = new Plot(&workspace_);
    for (auto& el : data) plot->draw(el.first, el.second);
    plot->show();
}

}  // namespace vw