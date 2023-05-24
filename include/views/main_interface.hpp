#ifndef _VIEWS_MAIN_INTERFACE_HPP_
#define _VIEWS_MAIN_INTERFACE_HPP_

#include <views/nav_bar.hpp>
#include <models/data.hpp>
#include <QVBoxLayout>
#include <QMdiArea>
#include <list>

namespace vw {

////////////////////////////////////////////////////////////////
// \brief Object that used to draw interface.
////////////////////////////////////////////////////////////////
class MainInterface : public QVBoxLayout {
 protected:
	using Self = MainInterface;
	using Base = QVBoxLayout;

	NavBar nav_bar_;
	QMdiArea workspace_;

 public:
	// Default constructor
	MainInterface(QWidget* parent = nullptr);
	// Destructor
	~MainInterface();

	// Add plot
	void plot(const mdl::Data& data);
	// Add plots
	void plot(std::list<std::pair<mdl::Data, QColor>> data);

};

} // namespace vw

#endif // _VIEWS_MAIN_INTERFACE_HPP_