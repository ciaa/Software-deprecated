#include <iostream>

#include "Comms/Drivers/ciaa_comm_facade.h"

int main()
{
    ciaaCommFacade *s = new ciaaCommFacade("10.58.20.150", 8888);
    CommDriverErrorCode ret = s->connect(100);
    if (ret == CommDriverErrorCode::without_error)
    {
        std::cout << "All OK!!!" << std::endl;
    }
    else
    {
        std::cout << s->get_msg_error(s->connect(100)) << std::endl;
    }
    delete s;
    qDebug() << "clientaaaaa";
    if (ret == CommDriverErrorCode::without_error) return 0;
    else return 0;
}
