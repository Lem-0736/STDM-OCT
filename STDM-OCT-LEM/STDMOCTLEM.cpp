#include "STDMOCTLEM.h"

#include <shlwapi.h>
#include <windows.h>
#include "AcapLib2.h"
#pragma comment( lib, "AcapLib2.lib" )

#include <NIDAQmx.h>

#include <iostream>
#include <fstream>
#include <array>

#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtCore/QDateTime>

#include <fstream>
#include <sstream>
#include <iomanip>

STDMOCTLEM::STDMOCTLEM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
