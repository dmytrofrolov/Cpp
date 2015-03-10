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
        exit(1);
    }

    //every boost asio program should has io_service
    boost::asio::io_service mainIoService;

    try
    {
        boost::system::error_code ec;

        //create connection

        //create socket
        tcp::socket mainSocket(mainIoService);

        //connect to socket
        mainSocket.connect({ {},  atoi(argv[1])});

        //write something to socket
        string request("GET /?q="+string(argv[2])+" HTTP/1.1\r\n\r\n");
        mainSocket.send(boost::asio::buffer(request));

        //read response
        string response;

        //is "</html>" found
        std::size_t found = 0;

        //do read while not found </html> or some error occured
        do {
            char buf[1024];
            size_t bytes_transferred = mainSocket.receive(boost::asio::buffer(buf), {}, ec);
            if (!ec) response.append(buf, buf + bytes_transferred);
            string endOfHTML = "</html>";
            found = response.find(endOfHTML);
        } while (!found || !ec);

        //write response to console
        cout << "Response received:\n'" << response << "\n'" << endl;

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


//after compilation use (it runs only if 01_boost_http_server runned)
// LD_LIBRARY_PATH=/home/admin/Boost/boost-bin/lib/ ./03_http_client 1334 udesgo.com
// to run it and it will return html of the site
