/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Radu Andries <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef IRCBOT_H
#define IRCBOT_H

#include <QObject>
#include <IrcSession>
#include <QSslSocket>
#include <QStringList>
#include <boost/random/mersenne_twister.hpp>
#include <ctime>

class QTimer;
class ScriptRunner;
class QScriptEngine;namespace Irc {
class Buffer;
}


class IrcBot : public QObject
{
Q_OBJECT
public:
    IrcBot();
    virtual ~IrcBot();
    QString pickInsult(QString nick);
public slots:
  void ircconnected();
  void parseMessage(QString origin, QString msg);
  void terminateScript();
private:
  Irc::Session *s;
  Irc::Buffer *b;
  QSslSocket* socket;
  QStringList column1;
  QStringList column2;
  QStringList column3;
  boost::mt19937 gen;
  ScriptRunner* runner;
  QTimer *timer;
  MprisReader *iface;
};

#include <qdbusargument.h>

typedef struct _DBusStatus {    // From Clementine.
  int play;            // Playing = 0, Paused = 1, Stopped = 2
  int random;          // Linearly = 0, Randomly = 1
  int repeat;          // Go_To_Next = 0, Repeat_Current = 1
  int repeat_playlist; // Stop_When_Finished = 0, Never_Give_Up_Playing = 1, Never_Let_You_Down = 42

  enum MprisPlayState {
    Mpris_Playing = 0,
    Mpris_Paused = 1,
    Mpris_Stopped = 2,
  };
} DBusStatus;
Q_DECLARE_METATYPE(DBusStatus);

QDBusArgument& operator <<(QDBusArgument& arg, const DBusStatus& status);
const QDBusArgument& operator >>(const QDBusArgument& arg, DBusStatus& status);

#endif // IRCBOT_H
