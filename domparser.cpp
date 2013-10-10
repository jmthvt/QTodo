#include "domparser.h"


QDomDocument DomParser::doc = QDomDocument("database");

DomParser::DomParser()
{
}

DomParser::~DomParser()
{
}

void DomParser::parseXML()
{

    QFile file("database.xml");
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }

    file.close();
}

QList<Note> DomParser::collectAllNotes()
{
    parseXML();

    QList<Note> result;
    QString id;
    QString title;
    QString done;

    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.namedItem("note");
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {

            id = e.attribute("id");
            title = e.firstChildElement("title").text();
            done = e.firstChildElement("done").text();

            result.append(Note (id,title,done));
        }
        n = n.nextSibling();
    }

    return result;
}

void DomParser::saveXML(QList<Note> notesToSave)
{
    QFile file("database.xml");
    if (!file.open(QIODevice::WriteOnly))
        qDebug("File not writable");

    QXmlStreamWriter stream(&file);
    int id = 0;

    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("notes");

    foreach(Note item, notesToSave)
    {
        id++;
        stream.writeStartElement("note");
        stream.writeAttribute("id", QString::number(id));
        stream.writeTextElement("title", item.getTitle());
        stream.writeTextElement("done", item.getDone());
        stream.writeEndElement();
    }

    stream.writeEndElement();
    stream.writeEndDocument();
}

void DomParser::saveEmptyXML()
{
    QFile file("database.xml");
    if (!file.open(QIODevice::WriteOnly))
        qDebug("File not writable");

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("notes");
    stream.writeEndElement();
    stream.writeEndDocument();
}
