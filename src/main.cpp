#include <QApplication>
#include "ircbot.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    IrcBot bot;

    return app.exec();
}
