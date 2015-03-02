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
#include <vector>
//dont forget to add -lboost_thread flag for linker

using namespace std;
using boost::asio::ip::tcp;
using boost::system::error_code;
using boost::asio::buffer;
using boost::asio::write;

std::size_t completion(const boost::system::error_code& error, std::size_t bytes_transfered)
{
    return ! error;
}

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
        //boost::this_thread::sleep(boost::posix_time::milliseconds(10));

        //here it is necessary to parse response what we get
        string hostToOpen = response.substr(response.find("GET /?q=")+8,response.find(" HTTP/1.1")-8);
        //cout << "S:" << hostToOpen << ":E" << endl;

        //clear respons to not show it in browser
        response.clear();


        //start something strange ___________________
        {
            //
            /*
               when server gets and GET request it tries to find that query user sent
               for example, when you try to type "localhost:1334/?q=google.com"
               it gets "google.com" and send a request to google server for a web page
            */
            //
            try {
                using boost::asio::ip::tcp;

                //it is io_service required for sending an request
                boost::asio::io_service io_service;

                //query object with host to open from previous get request
                tcp::resolver::query query(hostToOpen, "80");
                tcp::resolver resolver(io_service);

                //resolve all possible ip addresses to connect
                tcp::resolver::iterator destination = resolver.resolve(query);

                //last ip address
                tcp::resolver::iterator end ;

                //address to connect (it will be last from destination)
                tcp::endpoint endpoint;

                //previous before last endpoint (last could be IPv6)
                tcp::endpoint previousEndpoint;

                //if it will be one connection it will connect to this one
                unsigned short int possibleConnections = 0;

                //check all possible endpoints
                while ( destination != end ) {
                    possibleConnections++;
                    previousEndpoint = endpoint;
                    endpoint = *destination++;
                    std::cout<<endpoint<<std::endl;
                }

                //if there are more than one possible connection it will connect to one before last
                if(possibleConnections==1)previousEndpoint=endpoint;
                std::cout<<previousEndpoint<<std::endl;

                //open socket to previousEndpoint
                tcp::socket socket(io_service);
                socket.connect(previousEndpoint);

                //request text
                boost::asio::streambuf request;
                std::ostream requestStream(&request);
                requestStream << "GET / HTTP/1.1\r\n"
                              << "Host: "<< hostToOpen <<"\r\n"
                              //<< "User-Agent: Mozilla/5.0 (X11; Linux i686; rv:24.0) Gecko/20140723 Firefox/24.0 Iceweasel/24.7.0\r\n"
                              << "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
                              << "Connection: Keep-Alive\r\n\r\n";

                //write request to socket (where we will send an request)
                boost::asio::write(socket, request);

                //buffer for getting last response
                boost::array< char, 512 > buf;

                //if there are some errors
                boost::system::error_code error;

                //length of response
                std::size_t length;

                //read the response from socket
                length = boost::asio::read(socket, boost::asio::buffer(buf, 1024), boost::asio::transfer_all(), error);

                //add response to string for future writing
                for(unsigned int i = 0; i < length; i++){
                    char tempCh = buf[i];
                    response+=(tempCh);
                }
            }
            catch (std::exception& e){
                std::cerr << e.what() << std::endl;
            }
        }

        //write result to main socket (for localhost)
        write(socket, buffer(response));

    }

    return 0;
}

//this compiles successfully =) don't forget -lboost_system flag
