#include <stateitem.h>

StateItem::StateItem(QString &line,QWidget *parent):QWidget(parent)
{
	this->list=line.split(QRegExp(";"));
	if(list.length()!=4)
	{
		throw(tr("Could not parse line \"%1\"!").arg(line));
	}

	this->layout=new QHBoxLayout(this);

	QLabel *l=new QLabel(this);
	l->setPixmap(QPixmap(":/data/"+list[icon]));
	this->layout->addWidget(l);

	this->layout->addWidget(new QLabel(tr("%1")
		.arg(list[name]),this));
	this->layout->addWidget(new QLabel(tr("position: %1")
		.arg(list[position]),this));
	this->layout->addWidget(new QLabel(tr("party: %1")
		.arg(list[party]),this));
}

StateItem::~StateItem(void)
{
}
