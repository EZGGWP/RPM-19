#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

///
/// \brief Это конструктор главного окна
/// \param parent Принимает ссылку на виджет-родитель
///
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	layout->addWidget(table, 1);
	ui->centralwidget->setLayout(layout);
	ui->menubar->addAction("Save...", this, &MainWindow::saveContAction);

}

///
/// \brief Это деструктор главного окна
///
MainWindow::~MainWindow() {
	delete ui;
}

///
/// \brief Это функция сохранения содержимого таблицы в файл .xlsx
/// \param filepath Принимает путь с именем для сохранения файла
///
void MainWindow::saveContents(QUrl filepath) {

	QAxObject *excelItself = new QAxObject("Excel.Application", this);
	QAxObject *workbooks = excelItself->querySubObject("Workbooks");
	QAxObject *workbook = workbooks->querySubObject("Add");
	QAxObject *spreadSheets = workbook->querySubObject("Sheets");
	QAxObject *spreadSheet = spreadSheets->querySubObject("Add");
	for (auto i = table->model->dataMap.begin(); i != table->model->dataMap.end(); i++) {
		QAxObject *cell = spreadSheet->querySubObject("Cells(int, int)", i.key().row()+1, i.key().column()+1);
		cell->setProperty("Value", i.value());
		delete cell;
	}
	if (!filepath.isEmpty()) {
		workbook->dynamicCall("SaveAs (const QString&)", filepath);
	} else {
		QMessageBox::information(this, "Wrong path", "You entered wrong path. Try again.");
	}
	workbook->dynamicCall("Close ()");
	excelItself->dynamicCall("Quit ()");
	delete spreadSheet, spreadSheets, workbook, workbooks, excelItself;
	this->table->model->dataMap.clear();
};

///
/// \brief Это перегрузка эвента закрытия окна
/// \param event Принимает ссылку на событие закрытия окна
///
void MainWindow::closeEvent(QCloseEvent *event) {
	int state = QMessageBox::question(this, "You want to quit?", "Want to save your work before quitting?", QMessageBox::Save, QMessageBox::No);
	if (state == QMessageBox::Save) {
		saveContAction();
	}
};

///
/// \brief Это слот сохранения данных с проверкой пути
///
void MainWindow::saveContAction() {
	QUrl filepath = QFileDialog::getSaveFileUrl(this, "Save file...", QUrl(), "Excel spreadsheet(*.xlsx)");
	if (filepath.isValid()) {
		saveContents(filepath);
	};
}



