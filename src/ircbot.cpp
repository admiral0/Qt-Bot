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


#include "ircbot.h"

#include <IrcBuffer>

#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>
#include "scriptrunner.h"
#include <QtDBus>
#include "mprisreader.h"

#include <QTimer>
using namespace Irc;





QDBusArgument& operator<< (QDBusArgument& arg, const DBusStatus& status) {
  arg.beginStructure();
  arg << status.play;
  arg << status.random;
  arg << status.repeat;
  arg << status.repeat_playlist;
  arg.endStructure();
  return arg;
}

const QDBusArgument& operator>> (const QDBusArgument& arg, DBusStatus& status) {
  arg.beginStructure();
  arg >> status.play;
  arg >> status.random;
  arg >> status.repeat;
  arg >> status.repeat_playlist;
  arg.endStructure();
  return arg;
}



IrcBot::IrcBot() : QObject()
{
qDBusRegisterMetaType<DBusStatus>();
column1<<"artless";column2<<"base-court";column3<<"apple-john";
column1<<"bawdy";               ;
column1<<"beslubbering";;
column1<<"bootless";    ;
column1<<"churlish";    ;
column1<<"cockered";    ;
column1<<"clouted";     ;
column1<<"craven";      ;
column1<<"currish";     ;
column1<<"dankish";     ;
column1<<"dissembling"; ;
column1<<"droning";     ;
column1<<"errant";     ;
column1<<"fawning";     ;
column1<<"fobbing";     ;
column1<<"froward";     ;
column1<<"frothy";       ;
column1<<"gleeking";    ;
column1<<"goatish";     ;
column1<<"gorbellied";  ;
column1<<"impertinent"; ;
column1<<"infectious";  ;
column1<<"jarring";      ;
column1<<"loggerheaded";;
column1<<"lumpish";     ;
column1<<"mammering";   ;
column1<<"mangled";     ;
column1<<"mewling";     ;
column1<<"paunchy";     ;
column1<<"pribbling";   ;
column1<<"puking";      ;
column1<<"puny";        ;
column1<<"qualling";    ;
column1<<"rank";         ;
column1<<"reeky";       ;
column1<<"roguish";     ;
column1<<"ruttish";      ;
column1<<"saucy";       ;
column1<<"spleeny";     ;
column1<<"spongy";      ;
column1<<"surly";         ;
column1<<"tottering";   ;
column1<<"unmuzzled";   ;
column1<<"vain";          ;
column1<<"venomed";     ;
column1<<"villainous";  ;
column1<<"warped";;
column1<<"wayward";     ;
column1<<"weedy";    ;
column1<<"yeasty";      ;
column2<<"bat-fowling";;
column2<<"beef-witted";;
column2<<"beetle-headed ";;
column2<<"boil-brained";;
column2<<"clapper-clawed";;
column2<<"clay-brained ";;
column2<<"common-kissing";
column2<<"crook-pated";
column2<<"dismal-dreamin";
column2<<"dizzy-eyed";
column2<<"doghearted";
column2<<"dread-bolted";
column2<<"earth-vexing";
column2<<"elf-skinned";
column2<<"fat-kidneyed";
column2<<"fen-sucked";
column2<<"flap-mouthed";
column2<<"fly-bitten";
column2<<"folly-fallen";
column2<<"fool-born";
column2<<"full-gorged";
column2<<"guts-griping";
column2<<"half-faced";
column2<<"hasty-witted";
column2<<"hedge-born";
column2<<"hell-hated";
column2<<"idle-headed";
column2<<"ill-breeding";
column2<<"ill-nurtured";
column2<<"knotty-pated";
column2<<"milk-livered";
column2<<"motley-minded";
column2<<"onion-eyed";
column2<<"plume-plucked";
column2<<"pottle-deep";
column2<<"pox-marked";
column2<<"reeling-ripe";
column2<<"rough-hewn";
column2<<"rude-growing";
column2<<"rump-fed";
column2<<"shard-borne";
column2<<"sheep-biting";
column2<<"spur-galled";
column2<<"swag-bellied";
column2<<"tardy-gaited";
column2<<"tickle-brained";
column2<<"toad-spotted  ";
column2<<"unchin-snouted";
column2<<"weather-bitten";
column3<<"canker-blossom";
column3<<"barnacle"  ;
column3<<"bladder"  ;
column3<<"boar-pig"  ;
column3<<"bugbear"  ;
column3<<"bum-bailey"  ;
column3<<"baggage"  ;
column3<<"clack-dish"  ;
column3<<"clotpole"  ;
column3<<"coxcomb"  ;
column3<<"codpiece"  ;
column3<<"death-token"  ;
column3<<"dewberry"  ;
column3<<"flap-dragon"  ;
column3<<"flax-wench"  ;
column3<<"flirt-gill"  ;
column3<<"foot-licker"  ;
column3<<"fustilarian"  ;
column3<<"giglet"  ;
column3<<"gudgeon"  ;
column3<<"haggard"  ;
column3<<"harpy"  ;
column3<<"nchedge-pig"  ;
column3<<"horn-beast"  ;
column3<<"hugger-mugger"  ;
column3<<"joithead"  ;
column3<<"lewdster"  ;
column3<<"lout"  ;
column3<<"maggot-pie"  ;
column3<<"malt-worm"  ;
column3<<"mammet"  ;
column3<<"measle"  ;
column3<<"minnow"  ;
column3<<"miscreant"  ;
column3<<"moldwarp"  ;
column3<<"mumble-news"  ;
column3<<"nut-hook"  ;
column3<<"pigeon-egg"  ;
column3<<"pignut"  ;
column3<<"puttock"  ;
column3<<"pumpion"  ;
column3<<"ratsbane"  ;
column3<<"scut"  ;
column3<<"skainsmate"  ;
column3<<"strumpet"  ;
column3<<"varlot"  ;
column3<<"vassal"  ;
column3<<"whey-face"  ;
column3<<"wagtail" ;
  s=new Session(this);
   socket= new QSslSocket(s);
    socket->ignoreSslErrors();
    socket->setPeerVerifyMode(QSslSocket::VerifyNone);
    s->setSocket(socket);
    s->setNick(""); //TODO
    s->setRealName("The mean qt bot using SSL");
    s->setHost("Neverland");
    s->connectToServer("crypto.azzurra.org", 9999);
    connect(s,SIGNAL(connected()),this,SLOT(ircconnected()));
    b=NULL;
    runner=NULL;
}

IrcBot::~IrcBot()
{

}

void IrcBot::ircconnected()
{
  
  b=s->addBuffer("#poul");s->join("#poul");
  s->message("NickServ","identify "); //TODO
  //s->raw("PRIVMSG NickServ identify botbotpwd");
  connect(b,SIGNAL(messageReceived(QString,QString)),this,SLOT(parseMessage(QString,QString)));
  
}
void IrcBot::parseMessage(QString origin, QString msg)
{
  qDebug()<<origin<<": "<<msg;
  if(msg.startsWith("@insult")){
    QStringList lst= msg.split(" ");
    lst.removeFirst();
    if(lst.size()>=1 && lst.size()<5){
      foreach(QString nick,lst){
	b->message(pickInsult(nick));
      }
    }else{
      b->message(pickInsult(origin));
    }
  }else if(msg.contains("la risposta alla domanda fondamentale sulla vita",Qt::CaseInsensitive)){
      b->message(origin+": 42");
  }else if(msg.startsWith("@greet")){
    QStringList lst= msg.split(" ");
    lst.removeFirst();
    if(lst.size()>=1 && lst.size()<5){
      foreach(QString nick,lst){
	b->message(nick+", ciao");
      }
    }else{
      b->message(pickInsult(origin));
    }
  }else if(msg.startsWith("@js")){
    if(runner){
      b->message("Runner is busy.");
      return;
    }
    runner=new ScriptRunner(origin, msg.remove("@js "),b);
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(terminateScript()));
    connect(runner,SIGNAL(finished()),this,SLOT(terminateScript()));
    runner->start();
    timer->start(10000);
  }else if(msg.startsWith("@listening")){
    MprisReader *iface= new MprisReader("org.mpris.amarok","/Player",QDBusConnection::sessionBus());
    if(!iface)
      return;
    DBusStatus s=iface->GetStatus();
    if(s.play==2)
      b->message("Player is stopped");
    else{
      QVariantMap track=iface->GetMetadata();
      b->message(QString("admiral0 listens to ")+track.value("artist").toString()+" - "+track.value("title").toString()+ "(" +track.value("album").toString()+ ")");
    }
  }else if(msg.contains("botbot")){
    b->message("eh?oh?");
  }
}
extern "C"{
  int rdtsc() {   __asm__ __volatile__("rdtsc"); }
}
QString IrcBot::pickInsult(QString nick)
{
  qDebug("picking insult");
  gen=boost::mt19937(rdtsc());
  boost::uniform_int<> dist1(1, column1.size()-1);
  boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die1(gen, dist1);
  boost::uniform_int<> dist2(1, column2.size()-1);
  boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die2(gen, dist2);
  boost::uniform_int<> dist3(1, column3.size()-1);
  boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die3(gen, dist3);
  return nick+", thou "+ column1.at(die1())+" "+column2.at(die2())+" "+column3.at(die3());
}
void IrcBot::terminateScript()
{
  qDebug()<<"finished";
  if(runner && runner->isFinished()){
    
  }else{
    runner->terminate();
    b->message("Script failed");
  }
  delete runner;
  delete timer;
  runner=NULL;
}
