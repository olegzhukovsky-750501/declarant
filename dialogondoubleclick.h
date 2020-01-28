#ifndef DIALOGONDOUBLECLICK_H
#define DIALOGONDOUBLECLICK_H

#include <QtWidgets>
#include "senderdialog.h"

class DialogOnDoubleClick : public QObject
{
    bool eventFilter(QObject *watched, QEvent *event)
    {
      if(event->type() == QEvent::MouseButtonDblClick)
      {
          dialog->textEditDoubleClicked();
          return true;
      }
      return false;
    }
public:
    explicit DialogOnDoubleClick(QObject *parent = nullptr)
        :QObject(parent)
    {
        addTo(parent);
    }
    void addTo(QObject *obj)
    {
        if (obj)
        {
            obj->installEventFilter(this);
        }
    }
};

#endif // DIALOGONDOUBLECLICK_H
