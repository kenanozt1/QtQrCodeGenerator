#include "generatorcontroller.h"
#include <QDebug>
#include <QrCodeGenerator.h>
#include <QBuffer>

#include <QClipboard>
#include <QGuiApplication>
#include <QImage>
#include <QMimeData>
#include <QUrl>
#include <QDir>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPainter>
GeneratorController* GeneratorController::instance = nullptr;
GeneratorController::GeneratorController(QObject *parent)
    : QObject{parent}
{}

QString GeneratorController::qrCodeImage(QString text)
{
    QImage unscaledImage = m_generator.generateQr(text);
    QImage image = unscaledImage.scaled(500, 500);

    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    QString base64Image = QString::fromLatin1(byteArray.toBase64());

    return base64Image;
}


void GeneratorController::copyImageToClipboard(const QImage &image) {
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setImage(image);
    qDebug() << "Copied Qr Code";
}

QString GeneratorController::getTempFilePath(const QString &fileName)
{
    return QDir::tempPath() + "/" + fileName;
}
bool GeneratorController::printImage(const QString &path)
{
    QImage image(path);
    if (image.isNull()) {
        qDebug() << "Image could not be loaded for printing:" << path;
        return false;
    }
    QPrinter printer;
    printer.setPrinterName(QPrinterInfo::defaultPrinterName());
    QPainter painter;
    if (!painter.begin(&printer)) {
        qDebug() << "Could not connect to printer";
        return false;
    }
    QRect rect = painter.viewport();
    QSize size = image.size();
    size.scale(rect.size(), Qt::KeepAspectRatio);
    painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
    painter.setWindow(image.rect());
    painter.drawImage(0, 0, image);
    painter.end();
    qDebug() << "Image printed:" << path;
    return true;
}
