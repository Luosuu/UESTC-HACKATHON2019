#pragma execution_character_set("utf-8")
#ifndef FLOWERSHOPWINDOW_H
#define FLOWERSHOPWINDOW_H

#include <QLabel>
#include <QWidget>
#include <QGridLayout>

class FlowershopWindow : public QWidget
{
    Q_OBJECT
public:
    explicit FlowershopWindow(QWidget *parent = nullptr);

signals:

public slots:

private:
	QGridLayout *Layout;
	QLabel *FlowerLabel;

private:
	void InitializeUi();
	void InitializeConnect();
};

#endif // FLOWERSHOPWINDOW_H