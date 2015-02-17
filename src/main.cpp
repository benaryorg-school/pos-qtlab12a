#include <window.h>
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc,char **argv)
{
	//create the application
	QApplication app(argc,argv);

	//load our favourite locale
	QLocale locale=QLocale::system();
	QTranslator translator;
	translator.load(QString(":/lang/")+locale.name());
	app.installTranslator(&translator);

	//create the window
	Window *win;
	try
	{
		win=new Window;
	}
	catch(QString err)
	{
		//display the error
		QMessageBox::critical(0,QObject::tr("Error"),err+"\n"+
			QObject::tr("Will now exit!"),QMessageBox::Close);
		return 1;
	}
	//show the window
	win->show();

	//execute
	return app.exec();
}
