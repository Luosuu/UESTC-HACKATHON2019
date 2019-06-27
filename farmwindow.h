#pragma execution_character_set("utf-8")
#ifndef FARMWINDOW_H
#define FARMWINDOW_H

#include <vector>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QSize>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPushButton>
#include "flowershopwindow.h"

class FarmWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FarmWindow(QWidget *parent = nullptr);

signals:
	void Close();

public slots:

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QGridLayout *Layout;
	QPushButton *GobackButton;
	QLabel *InformationLabel;

	std::vector<QPushButton*> Grounds;
	std::vector<FlowershopWindow*> Shops;
};

#endif // FARMWINDOW_H