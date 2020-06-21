#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "tableview.h"
#include <QHBoxLayout>
#include <ActiveQt/qaxbase.h>
#include <ActiveQt/qaxobject.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

///
/// \brief Это класс главного окна
///
class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	///
	/// \brief Это конструктор главного окна
	/// \param parent Принимает ссылку на виджет-родитель
	///
	MainWindow(QWidget *parent = nullptr);

	///
	/// \brief Это деструктор главного окна
	///
	~MainWindow();

	///
	/// \brief Это горизонтальный блочный лэйаут для виджетов
	///
	QHBoxLayout *layout = new QHBoxLayout(this);

	///
	/// \brief Это объект представления таблицы
	///
	TableView *table = new TableView();

	///
	/// \brief Это функция сохранения содержимого таблицы в файл .xlsx
	/// \param filepath Принимает путь с именем для сохранения файла
	///
	void saveContents(QUrl filepath);

	///
	/// \brief Это слот сохранения данных с проверкой пути
	///
	void saveContAction();

	///
	/// \brief Это перегрузка эвента закрытия окна
	/// \param event Принимает ссылку на событие закрытия окна
	///
	void closeEvent(QCloseEvent *event);

private:
	///
	/// \brief Этот объект содержит интерфейс программы
	///
	Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
