#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QDebug>

const std::int32_t kTcpPort{8881};
const std::string kHost{"127.0.0.1"};

class Server
{
 public:
  Server() = default;
  ~Server() = default;

  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  Server(const Server&&) = delete;
  Server& operator=(const Server&&) = delete;

  bool startSlave() {
    serverLog(u8"Starting server...");
    QObject::connect(&server_, &QTcpServer::newConnection, [this]{
      QTcpSocket *cliSock = server_.nextPendingConnection();
      serverLog(QString(u8"Acepted conection from %1").arg(cliSock->peerAddress().toString()));

      cliSock->disconnectFromHost();
      cliSock->close();
      endSlave();
    });

    if (server_.listen (QHostAddress::Any, kTcpPort))
    {
      serverLog (u8"Server listening...");
      return true;
    } else {
      serverLog (QString(u8"Error starting server: %1").arg (server_.errorString()));
      endSlave();
      return false;
    }
  }

  void endSlave() {
    while (server_.hasPendingConnections()) {
      server_.nextPendingConnection()->close();
    }
    server_.close();
  }

 private:
  QTcpServer server_;
  void serverLog(const QString &msg) {
    qDebug() << "-- [SERVIDOR] -- " << msg;
  }
};

#include <QtCore/QTimer>

#include "Comms/Drivers/ciaa_comm_facade.h"
int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  Server server;
  if (server.startSlave()) {
    ciaaCommFacade client{kHost, kTcpPort};
    CommDriverErrorCode ret = client.connect(10000);
    if (ret == CommDriverErrorCode::without_error) {
        printf("Connection ok!\n");
        client.disconnect(100);
        server.endSlave();
        return EXIT_SUCCESS;
    } else {
      printf("%s\n", client.get_msg_error(ret).c_str());
      QTimer t;
      t.setInterval(2000);
      QObject::connect(&t, &QTimer::timeout, [&app, &t, &server]{
        t.stop();
        server.endSlave();
        app.exit(EXIT_FAILURE);
      });
      t.start();
      return app.exec();
    }
  }
  return EXIT_FAILURE;
}
