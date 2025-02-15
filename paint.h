#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

class QPushButton;
class QComboBox;
class QLabel;
class QCheckBox;
class Canvas;
class QButtonGroup;
class QRadioButton;
class QGroupBox;
class QVBoxLayout;
class QMenuBar;

class Paint : public QWidget
{
	Q_OBJECT

public:
	Paint(QWidget *parent = 0);
	~Paint();

private slots:
	void clearBtnPressed();
    void deleteBtnPressed();
    void colorBtnPressed();
	void primModeChanged();
    void showOutlineOnly(bool);
    void changeInteractionMode();
    void unselectAll();
    void duplicateBtnClicked();
    void showBBox(bool);
    void undoFunc();
private:
	Canvas *viewport;

    QGroupBox *radioGroupBox;
    QButtonGroup *radioGroup;
    QVBoxLayout *radioVBox;
    QRadioButton *createObj;
    QRadioButton *selectObj;
    //QRadioButton *changeCol;
    QRadioButton *moveObj;
    QPushButton *unselect;
    QPushButton *duplicateBtn;
    QCheckBox *showBBoxBtn;

    QMenuBar *bar;
    QMenu *shortcuts;
    QAction *undo;

	QPushButton *btnClearCanvas;
	QComboBox *cobPrimModes;
	QLabel *lblPrimModes;
    QPushButton *btnDeleteObj;
    QPushButton *btnSetCol;
    QCheckBox *cbOutline;
};

#endif // PAINT_H
