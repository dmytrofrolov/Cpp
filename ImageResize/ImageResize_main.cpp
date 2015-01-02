#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

//return a vector with all .jpg file names in "folder"
vector<string> getFilesInFolder(string folder);

int main( int argc, char** argv )

{
	cout << "Usage: \"Resize.exe 50% new_" << endl;

	if (argc < 3) {
		cout << "ERROR #1: Not enought arguments!";
		exit(1);
	}

	// Here we retrieve a percentage value to a integer
	int percent = atoi(argv[1]);

	string newFilePrefix = argv[2];

	vector <string> dirList = getFilesInFolder("");

	for(unsigned int i = 0; i < dirList.size(); i++){
		// Create an IplImage object *image 
		const char * tempSource = dirList[i].c_str();
		IplImage *source = cvLoadImage(tempSource);
		cout << dirList[i] << endl;

		// declare a destination IplImage object with correct size, depth and channels
		IplImage *destination = cvCreateImage( cvSize((int)((source->width*percent)/100) , (int)((source->height*percent)/100) ), source->depth, source->nChannels );

		//use cvResize to resize source to a destination image
		cvResize(source, destination);
		string tempDestinationName = newFilePrefix + dirList[i];
		const char * tempDest = tempDestinationName.c_str();
		
		// save image with a name supplied with a second argument
		cvSaveImage( tempDest, destination );
		cout << "Converting: " << tempSource << " to " << tempDest << " " << (i+1)*100/dirList.size() << "% done." <<  endl;

	}
	
return 0;

}


vector<string> getFilesInFolder(string folder)
{
    vector<string> names;
    char search_path[100];
    sprintf_s(search_path, "%s*.*", folder.c_str());
    WIN32_FIND_DATA fd; 
    HANDLE hFind = ::FindFirstFile(search_path, &fd); 
    if(hFind != INVALID_HANDLE_VALUE) 
    { 
        do 
        { 
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
		string tempFileName = fd.cFileName;
		if(tempFileName.find(".jpg")!=string::npos)
                	names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind); 
    } 
    return names;
}
