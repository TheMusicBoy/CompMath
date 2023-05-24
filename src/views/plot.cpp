#include <views/plot.hpp>

namespace vw {

////////////////////////////////////////////////////////////////
/// Plot implementation
////////////////////////////////////////////////////////////////

Plot::Plot(QWidget* parent) : WBase(parent) {
	this->WBase::setWidget(static_cast<PBase*>(this));
    this->WBase::setMinimumSize(QSize(200, 150));
    this->PBase::xAxis->setLabel("x");
    this->PBase::yAxis->setLabel("y");
}

Plot::~Plot() = default;

void Plot::draw(const mdl::Data& data, QColor color) {
    bounds_ += data.getBounds();

    QVector<double> x(data.size()), y(data.size());
    for (size_t i = 0; i < data.size(); i++) {
        x[i] = data.at(i).first;
        y[i] = data.at(i).second;
    }

    this->xAxis->setRange(bounds_.x_min, bounds_.x_max);
    this->yAxis->setRange(bounds_.y_min, bounds_.y_max);

    auto graph = this->addGraph();
    graph->setData(x, y);
    graph->setPen(QPen(color));
	
	this->replot();
}

QCPGraph* Plot::getGraph(size_t index) {
    return this->PBase::graph(index);
}

void Plot::remove(size_t index) {
    this->PBase::removeGraph(index);
}

void Plot::clear() {
    this->PBase::clearGraphs();
}

void Plot::show() {
    this->WBase::show();
}

void Plot::update() {
    this->PBase::replot();
}


size_t Plot::dataCount() const {
    return this->PBase::graphCount();
}

void Plot::setName(const std::wstring& name) {
    this->WBase::setWindowTitle(QString::fromStdWString(name));
}

void Plot::setXLabel(const std::wstring& label) {
    this->PBase::xAxis->setLabel(QString::fromStdWString(label));
}

void Plot::setYLabel(const std::wstring& label) {
    this->PBase::yAxis->setLabel(QString::fromStdWString(label));
}

} // namespace vw