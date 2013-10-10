#include "note.h"

Note::Note()
{
}

Note::Note(QString id, QString title, QString done)
{
    this->id = id;
    this->title = title;
    this->done = done;
}

Note::~Note()
{
}

void Note::setTitle(QString title)
{
    this->title = title;
}

QString Note::getTitle()
{
    return title;
}

void Note::setId(QString id)
{
    this->id = id;
}

QString Note::getId()
{
    return id;
}

void Note::setDone(QString done)
{
    this->done = done;
}

QString Note::getDone()
{
    return done;
}
