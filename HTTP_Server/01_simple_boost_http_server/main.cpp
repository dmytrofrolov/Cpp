/*
    This is the simple Boost HTTP Server
    using Boost.Asio
    Creation date: Feb 26, 2015
    Dmytro Frolov
*/

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;


int main()
{
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
        ///boost::asio::write(socket, boost::asio::buffer(message));

        //buffer for socket receiving the info
        char tempBuffer[1024];

        //error code object for handling errors
        boost::system::error_code ec;

        //how big does response is
        size_t bytesTransferred = socket.receive(boost::asio::buffer(tempBuffer), {}, ec);

        //string with response text for future parsing
        string response;

        //if there are not errors write boffer into response
        if (!ec) response.append(tempBuffer, tempBuffer + bytesTransferred);

        cout << "connection " << endl;
        boost::asio::write(socket, boost::asio::buffer(response));
    }

    return 0;
}

//this compiles successfully =) don't forget -lboost_system flag
