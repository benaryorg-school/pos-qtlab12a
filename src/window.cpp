#include <window.h>
#include <stateitem.h>

Window::Window(QWidget *parent):QWidget(parent)
{
	this->setWindowTitle(tr("States"));

	this->layout=new QVBoxLayout(this);

	this->list=new QListWidget(this);
	this->layout->addWidget(this->list);

	QFile f(":/data/minister.txt");
	if(!f.open(QIODevice::ReadOnly))
	{
		throw(tr("Could not read from file!"));
	}
	QString str;
	QTextStream stream(&f);
	stream.readLine();
	while(!(str=stream.readLine()).isNull())
	{
		QListWidgetItem *it=new QListWidgetItem;
		it->setSizeHint(QSize(0,128));
		this->list->addItem(it);
		this->list->setItemWidget(it,new StateItem(str));
	}
	f.close();
}

Window::~Window(void)
{
}
