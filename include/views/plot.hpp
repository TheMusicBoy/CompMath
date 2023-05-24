#ifndef _VIEWS_PLOT_HPP_
#define _VIEWS_PLOT_HPP_

#include <models/data.hpp>
#include <qcustomplot.h>
#include <QMdiSubWindow>
#include <string>

namespace vw {

////////////////////////////////////////////////////////////////
// \brief Object that used to plot data
////////////////////////////////////////////////////////////////
class Plot : public QMdiSubWindow, public QCustomPlot {
 private:
    using Self = Plot;
    using WBase = QMdiSubWindow;
    using PBase = QCustomPlot;

    mdl::Bounds bounds_;

 public:
    // Default constructor
    explicit Plot(QWidget* parent = nullptr);
    // Destructor
    ~Plot();

    // Assignment operator

    // Copy assignment operator
    Self& operator=(const Self& other);
    // Move assignment operator
    Self& operator=(Self&& other);

    // Methods

    // Draw from mdl::Data
    void draw(const mdl::Data& data, QColor color = Qt::red);
    // Get graph object
    QCPGraph* getGraph(size_t index);
    // Remove data by index
    void remove(size_t index);
    // Remove all data
    void clear();
    // Show by QMdiSubWindow
    void show();
    // Update the plot
    void update();

    // Get data count
    size_t dataCount() const;
    // Set name
    void setName(const std::wstring& name);
    // Set label of x
    void setXLabel(const std::wstring& label);
    // Set label of y
    void setYLabel(const std::wstring& label);

};

} // namespace vw

#endif // _VIEWS_PLOT_HPP_