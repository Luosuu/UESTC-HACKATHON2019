#pragma execution_character_set("utf-8")
#ifndef HOUSEWINDOW_H
#define HOUSEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QSize>
#include <QPixmap>

class HouseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HouseWindow(QWidget *parent = nullptr);

signals:
	void Close();

public slots:

private:
	void InitializeUi();
	void InitializeConnect();

private:
	QPushButton *GobackButton;
};

#endif // HOUSEWINDOW_H