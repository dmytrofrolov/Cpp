#include <iostream>
#include <boost/asio.hpp>
#include <string>
using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{

    //using "client <host> <port> <address>"
    //<address> is web link or ip address

    if(argc!=3){
        cout << "Error! using: \"client <host> <port> <address>\"" << endl;
        //exit(1);
    }
    argv[1] = "1334";

    //every boost asio program should has io_service
    boost::asio::io_service mainIoService;

    tcp::socket mainSocket(mainIoService);

    mainSocket.connect({ {},  atoi(argv[1])});

    string request("GET /?q=google.com HTTP/1.1\r\n\r\n");
    mainSocket.send(boost::asio::buffer(request));

    string response;

    boost::system::error_code ec;
    std::size_t found;
    do {
        char buf[1024];
        size_t bytes_transferred = mainSocket.receive(boost::asio::buffer(buf), {}, ec);
        if (!ec) response.append(buf, buf + bytes_transferred);
        string endOfHTML = "</html>";
        found = response.find(endOfHTML);
    } while (!found);

    // print and exit
    std::cout << "Response received: '" << response << "'\n";

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
