#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note
{
private:
    QString id;
    QString title;
    QString done;

public:
    Note();
    Note(QString id, QString title, QString done);

    ~Note();

    void setId(QString id);
    QString getId();

    void setTitle(QString title);
    QString getTitle();

    void setDone(QString done);
    QString getDone();
};

#endif // NOTE_H
