#ifndef PARSER_H
#define PARSER_H

#include <QtXml>
#include <QDebug>
#include <QList>
#include <QString>
#include <QXmlStreamWriter>
#include "note.h"

class DomParser
{
private:
    static QDomDocument doc;

public:
    DomParser();
    ~DomParser();

    static void parseXML();
    static QList<Note> collectAllNotes();
    static void saveXML (QList<Note> notesToSave);
    static void saveEmptyXML();
};

#endif // PARSER_H
