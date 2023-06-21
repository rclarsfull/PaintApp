#include <QPushButton> 
#include <QComboBox>
#include <QLabel>
#include <QColorDialog>
#include <QGridLayout>
#include <QCheckBox>
#include <QDebug>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include "paint.h"
#include "canvas.h"

/** c'tor */
Paint::Paint(QWidget *parent)
	: QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();
    viewport->setFillMode(true);

	btnClearCanvas = new QPushButton("&Clear Canvas");

    cobPrimModes = new QComboBox();
    cobPrimModes->addItem(tr("None"), Canvas::NONE);
    cobPrimModes->addItem(tr("Line"), Canvas::LINE);
    cobPrimModes->addItem(tr("Freehand"), Canvas::FREE_HAND);
    cobPrimModes->addItem(tr("Circle"), Canvas::CIRCLE);
    cobPrimModes->addItem(tr("Rectangle"), Canvas::RECTANGLE);
    //cobPrimModes->addItem(tr("Triangle"), Canvas::TRIANGLE);
    //cobPrimModes->addItem(tr("Polygon"), Canvas::POLYGON);

	lblPrimModes = new QLabel("Primitive Mode");
	lblPrimModes->setBuddy(cobPrimModes);

    radioGroup = new QButtonGroup(this);
    radioGroupBox = new QGroupBox("Selection Tools", this);
    radioVBox = new QVBoxLayout(this);

    createObj = new QRadioButton("Create Object", this);
    selectObj = new QRadioButton("Select Object", this);
    //changeCol = new QRadioButton("Change Color", this);
    moveObj = new QRadioButton("Move Object", this);

    radioGroup->addButton(createObj, 0);
    radioGroup->addButton(selectObj, 1);
    //radioGroup->addButton(changeCol, 2);
    radioGroup->addButton(moveObj, 2);

    radioVBox->addWidget(createObj);
    radioVBox->addWidget(selectObj);
    //radioVBox->addWidget(changeCol);
    radioVBox->addWidget(moveObj);

    radioGroupBox->setLayout(radioVBox);
    createObj->click();

    unselect = new QPushButton("Unselect All");

    btnSetCol = new QPushButton("Change Color");
    btnDeleteObj = new QPushButton("Delete Selected");

    cbOutline = new QCheckBox("Show Only &Outline", this);

	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(viewport,       0, 0, 1, 4);
    mainLayout->addWidget(btnSetCol,      2, 3);
    mainLayout->addWidget(cbOutline,      1, 1, Qt::AlignLeft);
    mainLayout->addWidget(lblPrimModes,   1, 2, Qt::AlignRight);
    mainLayout->addWidget(cobPrimModes,   1, 3);
    mainLayout->addWidget(btnDeleteObj,   2, 1);
    mainLayout->addWidget(btnClearCanvas, 2, 2);
    mainLayout->addWidget(radioGroupBox,  1, 0, 3, 1);
    mainLayout->addWidget(unselect,       3, 1);

	// add layout to this widget instance
	setLayout(mainLayout);
	
    // connect button click event to clear canvas handler
    connect(btnClearCanvas, SIGNAL(clicked()),
            this, SLOT(clearBtnPressed()));
    // connect button click event to delete selected object handler
    connect(btnDeleteObj, SIGNAL(clicked()),
            this, SLOT(deleteBtnPressed()));
    // connect button click event to color chooser handler
    connect(btnSetCol, SIGNAL(clicked()),
            this, SLOT(colorBtnPressed()));
    // connect list view to primitive changed event handler
    connect(cobPrimModes, SIGNAL(activated(int)),
            this, SLOT(primModeChanged()));
    // connect checkbox to toggle outline event handler
    connect(cbOutline, SIGNAL(toggled(bool)),
            this, SLOT(showOutlineOnly(bool)));
    // connect RadioButtonGroup
    connect(radioGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(changeInteractionMode()));
    connect(unselect, SIGNAL(clicked()),
            this, SLOT(unselectAll()));
}

/** d'tor */
Paint::~Paint()
{
    delete viewport;
    delete btnClearCanvas;
    delete cobPrimModes;
    delete lblPrimModes;
    delete btnDeleteObj;
    delete btnSetCol;
    delete cbOutline;
    delete createObj;
    delete selectObj;
    //delete changeCol;
    delete moveObj;
    delete radioVBox;
    delete radioGroupBox;
    delete radioGroup;
}

/** method for handling button clicked event */
void Paint::clearBtnPressed()
{
    viewport->clearCanvas();

	// force redraw
	update();
    qDebug() << "Clear image called";
}

void Paint::deleteBtnPressed()
{
    viewport->removeSelected();
    //qDebug() << "Next action: delete selected item (NYI)";
    update();
}

void Paint::colorBtnPressed()
{
    QColor color = QColorDialog::getColor(Qt::white, this );
    if (color.isValid()) {
        qDebug() << "Color Choosen : " << color.name();
        viewport->setObjColor(color);
    }
}

void Paint::showOutlineOnly(bool outline)
{
    qDebug() << "Only show outline: " << outline;
    viewport->setFillMode(!outline);
}

void Paint::changeInteractionMode()
{
    int mode = radioGroup->checkedId();
    viewport->setInteractionMode(mode);
}

void Paint::unselectAll()
{
    viewport->unselectAll();
    update();
}

void Paint::primModeChanged()
{
	int mode = cobPrimModes->itemData(
			   cobPrimModes->currentIndex(), Qt::UserRole).toInt();
	viewport->setPrimitiveMode(mode);
    qDebug() << "Primitive Mode changed to " << mode;
}
