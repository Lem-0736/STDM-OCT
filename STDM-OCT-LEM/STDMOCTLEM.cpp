#include <stdio.h>
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
int daqErr = DAQmxSuccess;
void DAQmxErr()
{
	char errBuff[2048] = { '\0' };
	DAQmxGetExtendedErrorInfo(errBuff, 2048);
	printf("DAQmxErr: %s\n", errBuff);
}
#define DAQmxErrChk(functionCall) if( DAQmxFailed(daqErr=(functionCall)) ) DAQmxErr()
void DAQmxConfig();

STDMOCTLEM::STDMOCTLEM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void STDMOCTLEM::Start()
{
	DAQmxConfig();
}
void STDMOCTLEM::Create()
{
	int         error = 0;
	TaskHandle  taskHandle = 0;
	char        errBuff[2048] = { '\0' };
	DAQmxConfig();
	
}
void DAQmxConfig() {
	int         error = 0;
	TaskHandle  taskHandle = 0;
	char        errBuff[2048] = { '\0' };
	DAQmxErrChk(DAQmxCreateTask("", &taskHandle));
	DAQmxErrChk(DAQmxCreateCOPulseChanFreq(taskHandle, "Dev1/ctr0", "", DAQmx_Val_Hz, DAQmx_Val_Low, 0.0, 1.00, 0.50));
	DAQmxErrChk(DAQmxCfgImplicitTiming(taskHandle, DAQmx_Val_ContSamps, 1000));
	DAQmxErrChk(DAQmxSetStartTrigRetriggerable(taskHandle, TRUE));
	DAQmxErrChk(DAQmxConnectTerms("/Dev1/ctr0InternalOutput", "/Dev1/RTSI0", DAQmx_Val_DoNotInvertPolarity));


	/*********************************************/
	// DAQmx Start Code
	/*********************************************/
	DAQmxErrChk(DAQmxStartTask(taskHandle));

	printf("Generating pulse train. Press Enter to interrupt\n");
	getchar();
}