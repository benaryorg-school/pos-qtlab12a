#ifndef STATEITEM_H
#define STATEITEM_H

#include <QtCore>
#if QTCORE_VERSION>=0x050000
#include <QtWidgets>
#endif
#include <QtGui>

class StateItem:public QWidget
{
	Q_OBJECT

public:
	StateItem(QString &line,QWidget *parent=0);
	~StateItem(void);

	enum CSVIndex
	{
		name,
		position,
		party,
		icon,
	};

private:
	QStringList list;
	QLayout *layout;
};

#endif /** STATEITEM_H **/
