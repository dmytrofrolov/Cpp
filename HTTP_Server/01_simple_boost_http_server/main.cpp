/*
    This is the simple Boost HTTP Server
    using Boost.Asio
    Creation date: Feb 26, 2015
    Dmytro Frolov
*/

#include <iostream>
#include <string>
#include <boost/asio.hpp>  //for all networking
#include <boost/date_time/posix_time/posix_time.hpp>  //for timing

#include <boost/thread/thread.hpp>  //for sleep for this thread
//dont forget to add -lboost_thread flag for linker

using namespace std;
using boost::asio::ip::tcp;
using boost::system::error_code;
using boost::asio::buffer;
using boost::asio::write;

int main()
{
    //sum all connections
    unsigned int totalConnectionCounter = 0;

    //all boost programs should have at least one io service
    boost::asio::io_service io_service;

    //acceptor object is created to listen for new connections
    tcp::acceptor acceptor (io_service, tcp::endpoint(tcp::v4(), 1334));

    //it is create a socket and wait for a connection
    while(1){
        //create socket object
        tcp::socket socket(io_service);

        //tcp::acceptor accept a new connection
        acceptor.accept(socket);

        //message to return
        ///string message = "Hello world!";

        //write boost::asio::buffer(message) to socket stream
        ///write(socket, buffer(message));

        //buffer for socket receiving the info
        char tempBuffer[1024];

        //error code object for handling errors
        error_code ec;

        //how big does response is
        size_t bytesTransferred = socket.receive(buffer(tempBuffer), {}, ec);

        //string with response text for future parsing
        string response;

        //if there are not errors write boffer into response
        if (!ec) response.append(tempBuffer, tempBuffer + bytesTransferred);

        cout << "Connection #" << totalConnectionCounter++ << endl;
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
        response.append("asd");
        write(socket, buffer(response));

    }

    return 0;
}

//this compiles successfully =) don't forget -lboost_system flag
