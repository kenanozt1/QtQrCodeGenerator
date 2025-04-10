#ifndef GENERATORCONTROLLER_H
#define GENERATORCONTROLLER_H

#include <QObject>
#include <QString>
#include <QrCodeGenerator.h>
class GeneratorController : public QObject
{
    Q_OBJECT
    explicit GeneratorController(QObject *parent = nullptr);
    static GeneratorController* instance;
public:
    GeneratorController(const GeneratorController& obj) = delete;
    static GeneratorController* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new GeneratorController();
            return instance;
        }
        else
        {
            return instance;
        }
    }
    Q_INVOKABLE QString qrCodeImage(QString text);
    Q_INVOKABLE void copyImageToClipboard(const QImage &image);

    Q_INVOKABLE QString getTempFilePath(const QString &fileName);
    Q_INVOKABLE bool printImage(const QString &path);
private:
  QrCodeGenerator m_generator;

signals:
};

#endif // GENERATORCONTROLLER_H
