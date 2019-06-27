#include "housewindow.h"

HouseWindow::HouseWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void HouseWindow::InitializeUi()
{
	setWindowTitle("温馨小屋");
	setFixedSize(QSize(1200, 900));

	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/house.png)"));
	setPalette(Pal);

	GobackButton = new QPushButton(this);
	GobackButton->setFlat(true);
	GobackButton->move(27, 27);
	GobackButton->setFixedSize(QSize(105, 185));
}

void HouseWindow::InitializeConnect()
{
	connect(GobackButton, &QPushButton::clicked, [this]()
	{
		emit Close();
	});
}
