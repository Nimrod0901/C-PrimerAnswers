/*
 * @Author: Nimrod
 * @Date: 2018-05-02 20:27:10
 */
#include <iostream>
#include <memory>
#include <string>

struct destination {
    std::string ip_;
    unsigned int port_;
    destination(std::string ip, unsigned int port) : ip_(ip), port_(port) {}
};

struct connection {
    std::string ip_;
    unsigned int port_;
    connection(std::string ip, unsigned int port) : ip_(ip), port_(port) {}
};

connection connect(destination* destp) {
    std::shared_ptr<connection> connp(new connection(destp->ip_, destp->port_));
    std::cout << "Connected(" << connp.use_count() << ")" << std::endl;
    return *connp;
}

void disconnect(connection connp) {
    std::cout << "Disconected" << connp.ip_ << std::endl;
}

void end_connection(connection* pConn) { disconnect(*pConn); }

void f(destination& d) {
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main() {
    destination dest("220.181.111.111", 10086), dest2("222.181.111.111", 10068);
    f(dest);
    f(dest2);
    return 0;
}