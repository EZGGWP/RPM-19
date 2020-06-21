#include "tableview.h"
#include <QDebug>
#include <QMouseEvent>

///
/// \brief Это конструктор класса представления таблицы
///
TableView::TableView() {
	model = new TableModel(100, 100);
	connect(this, &TableView::itemPressed, model, &TableModel::editItemAtIndex, Qt::QueuedConnection);
	connect(model, &TableModel::updateViewSignal, this, &TableView::updateSlot);
	setModel(model);
}

///
/// \brief Это перегрузка эвента нажатия кнопки мыши
/// \param event Принимает ссылку на эвент мыши
///
void TableView::mousePressEvent(QMouseEvent *event) {
	currentIndex = indexAt(event->pos());
	if (event->button() == Qt::LeftButton) {
		bool *state;
		dialog->show();
		connect(dialog, &QInputDialog::accepted, this, &TableView::someSlotThatWorks);

	} else if (event->button() == Qt::RightButton) {
		qDebug() << "Right clicked on index" << indexAt(event->pos());
		emit itemPressed(indexAt(event->pos()), "");
	}
}

///
/// \brief Это слот для обновления представления
///
void TableView::updateSlot() {
	this->update();
}

///
/// \brief Это слот, который забирает текст из диалогового окна после его принятия. Были проблемы с эвент лупом внутри эвента, поэтому пришлось вынести
///
void TableView::someSlotThatWorks() {
	QString value = dialog->textValue();
	emit itemPressed(currentIndex, value);
}
