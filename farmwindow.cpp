#include "farmwindow.h"

FarmWindow::FarmWindow(QWidget *parent) : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

void FarmWindow::InitializeUi()
{
	setWindowTitle("种菜");
	setFixedSize(QSize(1200, 900));

	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/farm.jpg)").scaled(size()));
	setPalette(Pal);

	GobackButton = new QPushButton;
	GobackButton->setFlat(true);

	InformationLabel = new QLabel;

	for (int i = 0; i < 9; ++i)
	{
		auto *Btn = new QPushButton;
		Btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		Btn->setFlat(true);
		Grounds.push_back(Btn);

		auto *EachShop = new FlowershopWindow;
		Shops.push_back(EachShop);
	}

	Layout = new QGridLayout(this);
	Layout->setMargin(30);
	Layout->addWidget(GobackButton, 0, 0);
	Layout->addWidget(InformationLabel, 0, 1, 1, 2);
	for (int i = 0; i < 9; ++i)
	{
		Layout->addWidget(Grounds[i], i / 3 + 1, i % 3);
	}
	for (int i = 0; i < Layout->columnCount(); ++i)
	{
		Layout->setColumnStretch(i, 1);
	}
	for (int i = 0; i < Layout->rowCount(); ++i)
	{
		Layout->setRowStretch(i, 1);
	}

	GobackButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	InformationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	for (int i = 0; i < 9; ++i)
	{
		Grounds[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	}

	setLayout(Layout);
}

void FarmWindow::InitializeConnect()
{
	connect(GobackButton, &QPushButton::clicked, [this]()
	{
		emit Close();
	});

	for (int i = 0; i < 9; ++i)
	{
		connect(Grounds[i], &QPushButton::clicked, Shops[i], &FlowershopWindow::show);
	}
}
