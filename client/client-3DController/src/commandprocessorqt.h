#ifndef COMMANDPROCESSORQT_H
#define COMMANDPROCESSORQT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <string>
#include "parser.h"
#include "parservalidate.h"
#include "brazovirtual.h"
#include "commanddispatcher.h"
class CommandProcessorQT : public QObject
{
    Q_OBJECT

public:
    explicit CommandProcessorQT(QObject *parent = nullptr);
public slots:
    void setBrazo(BrazoVirtual& BrazoVirt);
    void sendMessage(QString Message);
signals:
private:
    Parser m_parser;
    ParserValidate m_parserValider;
    CommandDispatcher m_cmdDispatcher;
};

#endif // COMMANDPROCESSORQT_H
