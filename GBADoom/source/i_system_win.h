#ifndef I_SYSTEM_WIN_H
#define I_SYSTEM_WIN_H

#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QWidget>

//GBA Keys
#define KEYD_A          1
#define KEYD_B          2
#define KEYD_L          3
#define KEYD_R          4
#define KEYD_UP         5
#define KEYD_DOWN       6
#define KEYD_LEFT       7
#define KEYD_RIGHT      8
#define KEYD_START      9
#define KEYD_SELECT     10

extern "C"
{

extern const byte gammatable[2][32];

typedef enum
{
  ev_keydown,
  ev_keyup,
  ev_mouse,
  ev_joystick
} evtype_t;

// Event structure.
typedef struct
{
  evtype_t  type;
  int       data1;    // keys / mouse/joystick buttons
  int       data2;    // mouse/joystick x move
  int       data3;    // mouse/joystick y move
} event_t;

void D_PostEvent(event_t* ev);
}

extern unsigned char* pb;
extern unsigned char* pl;

class DoomWindow : public QWidget
{
    protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter p(this);

        QImage i((uchar*)pb, 240, 160, QImage::Format_Indexed8);
        i.setColorCount(256);

        for(int p = 0; p < 256; p++)
        {
            int r = pl[3*p];
            int g = pl[(3*p)+1];
            int b = pl[(3*p)+2];

            i.setColor(p, qRgb(r, g, b));
        }

        p.drawImage(this->rect(), i, i.rect());
    }

    void closeEvent(QCloseEvent *event) override
    {
        exit(0);
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        event_t ev;

        ev.type = ev_keydown;

        ev.data1 = 0;

        if(event->key() == Qt::Key_Escape)
            ev.data1 = KEYD_START;

        if(event->key() == Qt::Key_Return)
            ev.data1 = KEYD_A;

        if(event->key() == Qt::Key_Up)
            ev.data1 = KEYD_UP;

        if(event->key() == Qt::Key_Down)
            ev.data1 = KEYD_DOWN;

        if(event->key() == Qt::Key_Left)
            ev.data1 = KEYD_LEFT;

        if(event->key() == Qt::Key_Right)
            ev.data1 = KEYD_RIGHT;

        if(event->key() == Qt::Key_Tab)
            ev.data1 = KEYD_SELECT;

        if(event->key() == Qt::Key_Space)
            ev.data1 = KEYD_A;

        if(event->key() == Qt::Key_Control)
            ev.data1 = KEYD_B;

        if(event->key() == Qt::Key_Comma)
            ev.data1 = KEYD_L;

        if(event->key() == Qt::Key_Period)
            ev.data1 = KEYD_R;

        ev.data2 = 0;
        ev.data3 = 0;

        if(ev.data1 != 0)
            D_PostEvent(&ev);
    }

    void keyReleaseEvent(QKeyEvent *event) override
    {
        event_t ev;

        ev.type = ev_keyup;

        ev.data1 = 0;

        if(event->key() == Qt::Key_Escape)
            ev.data1 = KEYD_START;

        if(event->key() == Qt::Key_Return)
            ev.data1 = KEYD_A;

        if(event->key() == Qt::Key_Up)
            ev.data1 = KEYD_UP;

        if(event->key() == Qt::Key_Down)
            ev.data1 = KEYD_DOWN;

        if(event->key() == Qt::Key_Left)
            ev.data1 = KEYD_LEFT;

        if(event->key() == Qt::Key_Right)
            ev.data1 = KEYD_RIGHT;

        if(event->key() == Qt::Key_Tab)
            ev.data1 = KEYD_SELECT;

        if(event->key() == Qt::Key_Space)
            ev.data1 = KEYD_A;

        if(event->key() == Qt::Key_Control)
            ev.data1 = KEYD_B;

        if(event->key() == Qt::Key_Comma)
            ev.data1 = KEYD_L;

        if(event->key() == Qt::Key_Period)
            ev.data1 = KEYD_R;

        ev.data2 = 0;
        ev.data3 = 0;

        if(ev.data1 != 0)
            D_PostEvent(&ev);
    }
};

#endif // I_SYSTEM_WIN_H
