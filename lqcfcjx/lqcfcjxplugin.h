#ifndef LQCFCJXPLUGIN_H
#define LQCFCJXPLUGIN_H

//添加插件子项目的头文件
#include "testwidget.h"

#include <QDesignerCustomWidgetInterface>

class LQCFCJXPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    LQCFCJXPlugin(QObject *parent = 0);

    //子类继承重写，所以需要设置为虚函数
    virtual bool isContainer() const;
    virtual bool isInitialized() const;
    virtual QIcon icon() const;
    virtual QString domXml() const;
    virtual QString group() const;
    virtual QString includeFile() const;
    virtual QString name() const;
    virtual QString toolTip() const;
    virtual QString whatsThis() const;
//    QWidget *createWidget(QWidget *parent);//这个在子类中实现，构建各自的widget
    virtual void initialize(QDesignerFormEditorInterface *core);

protected:
    bool m_isContainer{false};//是否是一个容器控件，即内部可以添加其他控件
    QIcon m_icon;
    QString m_domXml;
    QString m_group{"lqcfcjx"};
    QString m_includeFile;
    QString m_name;
    QString m_toolTip;
    QString m_whatsThis;

private:
    bool m_initialized;
};

class MyCustomWidgets: public QObject,
        public QDesignerCustomWidgetCollectionInterface{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    MyCustomWidgets(QObject *parent = 0);
    QList<QDesignerCustomWidgetInterface*> customWidgets() const;

private:
    QList<QDesignerCustomWidgetInterface*> widgets;
};

//子项目控件模块
class TestWidgetInterface: public LQCFCJXPlugin{
    Q_OBJECT
    Q_INTERFACES( QDesignerCustomWidgetInterface )

public:
    TestWidgetInterface( QObject *parent );
    virtual QWidget *createWidget( QWidget *parent );
};

#endif // LQCFCJXPLUGIN_H
