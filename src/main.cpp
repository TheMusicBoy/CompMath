#include <views/main_interface.hpp>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QMainWindow window;

	QWidget *widget = new QWidget();
	window.setCentralWidget(widget);
	vw::MainInterface* main_interface = new vw::MainInterface(widget);

	window.show();
	app.exec();

}