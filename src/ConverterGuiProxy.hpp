#pragma once

#include "ConverterFactory.hpp"

#include <QObject>
#include <QUrl>

class ConverterGuiProxy : public QObject
{
    Q_OBJECT

    // clang-format off
    Q_PROPERTY(bool convSuccessfull READ convSuccessfull NOTIFY conversionCompleted)
    Q_PROPERTY(QString convMsg READ convMsg NOTIFY conversionCompleted)
    Q_PROPERTY(QString detailedConvMsg READ detailedConvMsg NOTIFY conversionCompleted)
    // clang-format on

  public:
    explicit ConverterGuiProxy(QObject *parent = nullptr);

    enum QConversionType {
        Ts2Csv  = ConverterFactory::Ts2Csv,
        Csv2Ts  = ConverterFactory::Csv2Ts,
        Ts2Xlsx = ConverterFactory::Ts2Xlsx,
        Xlsx2Ts = ConverterFactory::Xlsx2Ts,
        Dummy
    };
    Q_ENUM(QConversionType)

    bool convSuccessfull() const;
    QString convMsg() const;
    QString detailedConvMsg() const;

  signals:
    void conversionCompleted();

  public slots:
    void convert(ConverterGuiProxy::QConversionType type, QString input,
                 QString output, const QString &fieldSeparator,
                 const QString &stringSeparator, const QString &tsVersion);

  private:
    bool m_convSuccessfull{ false };
    QString m_convMsg{};
    QString m_detailedConvMsg{};

    void setConversionInfo(bool convSuccessfull,
                           const QString &convMsg         = QString(),
                           const QString &detailedConvMsg = QString());
};
