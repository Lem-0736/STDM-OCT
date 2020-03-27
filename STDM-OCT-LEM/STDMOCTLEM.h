#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_STDMOCTLEM.h"

class STDMOCTLEM : public QMainWindow
{
	Q_OBJECT

public:
	STDMOCTLEM(QWidget *parent = Q_NULLPTR);
	void Create();
private:
	Ui::STDMOCTLEMClass ui;

private slots:
	void Start();
};
