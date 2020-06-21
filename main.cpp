#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

///
/// \brief Это функция мэйн, в которой выполняется программа
/// \param argc Это количество аргументов
/// \param argv	Это массив с аргументами
/// \return	Возвращает результат выполнения программы
///
int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
