#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include "tablemodel.h"
#include <QInputDialog>

///
/// \brief Это класс представления таблицы, который пришлось отнаследовать, чтобы перегрузить ему эвенты мыши
///
class TableView : public QTableView {
	Q_OBJECT
public:
	///
	/// \brief Это конструктор класса представления таблицы
	///
	TableView();

	///
	/// \brief Это перегрузка эвента нажатия кнопки мыши
	/// \param event Принимает ссылку на эвент мыши
	///
	void mousePressEvent(QMouseEvent *event);

	///
	/// \brief Это модель таблицы, с которой берутся данные для представления
	///
	TableModel *model;

	///
	/// \brief Это диалоговое окно для получения нового значения ячейки
	///
	QInputDialog *dialog = new QInputDialog(this);

	///
	/// \brief Это поле сохраняет индекс последней ячейки, которая редактировалась
	///
	QModelIndex currentIndex;
signals:

	///
	/// \brief Это слот, который срабатывает при нажатии на ячейку для редактирования
	/// \param index Принимает индекс редактируемой ячейки
	/// \param value И новое значение
	///
	void itemPressed(QModelIndex index, QString value);
public slots:
	///
	/// \brief Это слот для обновления представления
	///
	void updateSlot();

	///
	/// \brief Это слот, который забирает текст из диалогового окна после его принятия. Были проблемы с эвент лупом внутри эвента, поэтому пришлось вынести
	///
	void someSlotThatWorks();

};

#endif // TABLEVIEW_H
