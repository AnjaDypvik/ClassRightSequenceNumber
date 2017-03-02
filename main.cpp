#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include "rightseqnum.h"
#include <qqmllist.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    RightSeqNumModel model;
    QFile rSeqNumFile(":/memberItems.txt");

    if (!rSeqNumFile.exists()){
        qDebug()<< "No file found.";
    }

    if (rSeqNumFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream saveStream(&rSeqNumFile);
        while (!saveStream.atEnd()) {
            char dummy;
            int rSeqNumSave;

            saveStream >>rsNumSave;

           qDebug()<<"Read Name: "<<dummy;

            saveStream>>dummy;
            qDebug()<<"Read Name: "<<dummy;
            model.addRSeqNum(RightSeqnumModel(rsNumSave));



        }
        rSeqNumFile.close();
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlContext *ctxt = engine.rootContext();  //view?
    ctxt->setContextProperty("myModel",&model);

    return app.exec();
}

