#include "startwindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
{
	InitializeUi();
	InitializeConnect();
}

StartWindow::~StartWindow()
{
}

void StartWindow::InitializeUi()
{
	setWindowTitle("黄金时代");
	setFixedSize(QSize(1200, 900));

	_FarmWindow = new FarmWindow;
	_BirdWindow = new BirdWindow;
	_FishingWindow = new FishingWindow;
	_HouseWindow = new HouseWindow;

	const auto ButtonSize = QSize(width() / 2 - 50, height() / 2 - 50);

	FarmButton = new QPushButton(this);
	FarmButton->setFlat(true);
	FarmButton->move(width() / 2 + 50, 100);
	FarmButton->setFixedSize(ButtonSize);

	BirdButton = new QPushButton(this);
	BirdButton->setFlat(true);
	BirdButton->move(width() / 2 + 50, height() / 2 + 50);
	BirdButton->setFixedSize(ButtonSize);

	FishingButton = new QPushButton(this);
	FishingButton->setFlat(true);
	FishingButton->move(50, height() / 2 + 50);
	FishingButton->setFixedSize(ButtonSize);

	HouseButton = new QPushButton(this);
	HouseButton->setFlat(true);
	HouseButton->move(50, 100);
	HouseButton->setFixedSize(ButtonSize);

	setAutoFillBackground(true);
	auto Pal = palette();
	Pal.setBrush(backgroundRole(), QPixmap(R"(:/main_background.png)"));
	setPalette(Pal);
}

void StartWindow::InitializeConnect()
{
	connect(FarmButton, &QPushButton::clicked, [this]()
	{
		this->hide();
		_FarmWindow->show();
	});
	connect(_FarmWindow, &FarmWindow::Close, [this]()
	{
		_FarmWindow->hide();
		this->show();
	});

	connect(BirdButton, &QPushButton::clicked, [this]()
	{
		this->hide();
		_BirdWindow->show();
	});
	connect(_BirdWindow, &BirdWindow::Close, [this]()
	{
		_BirdWindow->hide();
		this->show();
	});

	connect(FishingButton, &QPushButton::clicked, [this]()
	{
		this->hide();
		_FishingWindow->show();
	});
	connect(_FishingWindow, &FishingWindow::Close, [this]()
	{
		_FishingWindow->hide();
		this->show();
	});

	connect(HouseButton, &QPushButton::clicked, [this]()
	{
		_HouseWindow->show();
		this->hide();
	});
	connect(_HouseWindow, &HouseWindow::Close, [this]()
	{
		_HouseWindow->hide();
		this->show();
	});
}
