#include "tablemodel.h"
#include <QDebug>

///
/// \brief Это конструктор модели таблицы
/// \param rowNum Принимает количество строк таблицы
/// \param columnNum И столбцов таблицы
///
TableModel::TableModel(int rowNum, int columnNum) {
	rows = rowNum;
	columns = columnNum;
}

///
/// \brief Это деструктор модели таблицы
///
TableModel::~TableModel() {

};

///
/// \brief Это функция, которая возвращает количество строк таблицы, нужна из-за абстрактности модели, чтобы представление могло работать правильно
/// \param parent Принимает индекс элемента таблицы (осталось с абстракции, поэтому Unused)
/// \return Возвращает число строк
///
int TableModel::rowCount(const QModelIndex &parent) const {
	Q_UNUSED(parent);
	return rows;
};

///
/// \brief Это функция, которая возвращает количество столбцов таблицы, нужна из-за абстрактности модели, чтобы представление могло работать правильно
/// \param parent Принимает индекс элемента таблицы (осталось с абстракции, поэтому Unused)
/// \return Возвращает число столбцов
///
int TableModel::columnCount(const QModelIndex &parent) const {
	Q_UNUSED(parent);
	return columns;
};

///
/// \brief Это функция, которая возвращает содержимое элемента по индексу
/// \param index Принимает индекс элемента
/// \param role И роль, она также осталась от абстракции
/// \return Возвращает значение элемента
///
QVariant TableModel::data(const QModelIndex &index, int role) const {
	Q_UNUSED(role);
	return dataMap.value(index);
};

///
/// \brief Этот слот позволяет изменять значение ячейки по индексу
/// \param index Принимает индекс нужного элемента
/// \param value И значение, которое в него нужно поместить
///
void TableModel::editItemAtIndex(QModelIndex index, QString value) {
		dataMap.insert(index, value);
		emit updateViewSignal();
}

