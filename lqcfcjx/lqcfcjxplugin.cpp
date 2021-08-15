#include "lqcfcjxplugin.h"
#include <QtPlugin>

LQCFCJXPlugin::LQCFCJXPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void LQCFCJXPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool LQCFCJXPlugin::isInitialized() const
{
    return m_initialized;
}

QString LQCFCJXPlugin::name() const
{
    return m_name;
}

QString LQCFCJXPlugin::group() const
{
    return m_group;
}

QIcon LQCFCJXPlugin::icon() const
{
    return m_icon;
}

QString LQCFCJXPlugin::toolTip() const
{
    return m_toolTip;
}

QString LQCFCJXPlugin::whatsThis() const
{
    return m_whatsThis;
}

bool LQCFCJXPlugin::isContainer() const
{
    return m_isContainer;
}

QString LQCFCJXPlugin::domXml() const
{
    return m_domXml;
}

QString LQCFCJXPlugin::includeFile() const
{
    return m_includeFile;
}

MyCustomWidgets::MyCustomWidgets(QObject *parent)
         : QObject(parent)
 {
//     widgets.append(new CustomWidgetOneInterface(this));//添加示例
    widgets.append(new TestWidgetInterface(this));
 }

QList<QDesignerCustomWidgetInterface*> MyCustomWidgets::customWidgets() const
 {
     return widgets;
 }

TestWidgetInterface::TestWidgetInterface(QObject *parent): LQCFCJXPlugin(parent){
    m_name = "TestWidget";
    m_includeFile = "testwidget.h";
    m_icon = QPixmap("");
    m_isContainer = true;
    m_domXml =
            "<widget class=\"TestWidget\" name=\"testwidget\">\n"
            " <property name=\"geometry\">\n"
            "  <rect>\n"
            "   <x>0</x>\n"
            "   <y>0</y>\n"
            "   <width>100</width>\n"
            "   <height>30</height>\n"
            "  </rect>\n"
            " </property>\n"
            "</widget>\n";
}

QWidget *TestWidgetInterface::createWidget(QWidget *parent)
{
    return new TestWidget(parent);
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(lqcfcjx, LQCFCJXPlugin)
#endif // QT_VERSION < 0x050000
