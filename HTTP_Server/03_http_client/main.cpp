#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{

    //using "client <host> <port> <address>"
    //<address> is web link or ip address

    try
    {
        //create connection

        //create socket

        //connect to socket

        //write something to socket

        //read response

        //write response to console

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
