#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QMouseEvent>

///
/// \brief Это класс модели таблицы, наследованный от абстрактного
///
class TableModel : public QAbstractTableModel {
	Q_OBJECT
public:
	///
	/// \brief Это конструктор модели таблицы
	/// \param rowNum Принимает количество строк таблицы
	/// \param columnNum И столбцов таблицы
	///
	TableModel(int rowNum, int columnNum);

	///
	/// \brief Это деструктор модели таблицы
	///
	~TableModel();

	///
	/// \brief Это дефолтное количество строк
	///
	int rows = 0;

	///
	/// \brief Это дефолтное количество столбцов
	///
	int columns = 0;

	///
	/// \brief Это функция, которая возвращает количество строк таблицы, нужна из-за абстрактности модели, чтобы представление могло работать правильно
	/// \param parent Принимает индекс элемента таблицы (осталось с абстракции, поэтому Unused)
	/// \return Возвращает число строк
	///
	int rowCount(const QModelIndex &parent) const;

	///
	/// \brief Это функция, которая возвращает количество столбцов таблицы, нужна из-за абстрактности модели, чтобы представление могло работать правильно
	/// \param parent Принимает индекс элемента таблицы (осталось с абстракции, поэтому Unused)
	/// \return Возвращает число столбцов
	///
	int columnCount(const QModelIndex &parent) const;

	///
	/// \brief Это функция, которая возвращает содержимое элемента по индексу
	/// \param index Принимает индекс элемента
	/// \param role И роль, она также осталась от абстракции
	/// \return Возвращает значение элемента
	///
	QVariant data(const QModelIndex &index, int role) const;

	///
	/// \brief Это мапа, которая содержит значения, которые нужно вставить по соответствующим индексам
	///
	QMap<QModelIndex, QString> dataMap;
public slots:
	///
	/// \brief Этот слот позволяет изменять значение ячейки по индексу
	/// \param index Принимает индекс нужного элемента
	/// \param value И значение, которое в него нужно поместить
	///
	void editItemAtIndex(QModelIndex index, QString value);
signals:
	///
	/// \brief Это сигнал для обновления представления таблицы
	///
	void updateViewSignal();
};



#endif // TABLEMODEL_H
