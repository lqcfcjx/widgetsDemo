#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TestWidget; }
QT_END_NAMESPACE

/**
** QDESIGNER_WIDGET_EXPORT:这个宏主要防止该控件导出的接口在其他平台
** 不能被正确识别。
*/
class QDESIGNER_WIDGET_EXPORT TestWidget : public QWidget
{
    Q_OBJECT

public:
    TestWidget(QWidget *parent = nullptr);
    ~TestWidget();

private:
    Ui::TestWidget *ui;
};
#endif // TESTWIDGET_H
