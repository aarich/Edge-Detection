#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "cvaux.h"
#include "edgeDetect.h"

#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

// Print usage
static void printPrompt( const string& applName )
{
    cout << "/*\n"
         << " * Edge Detection\n"
         << " */\n" << endl;

    cout << endl << "Format:\n" << endl;
    cout << "./" << applName << " [ImageName] " << endl;
    cout << endl;
}

int main(int argc, char** argv)
{
    if( argc < 2 )
    {
        printPrompt( argv[0] );
        return -1;
    }

    // cv::initModule_nonfree();

    Mat image = imread(argv[1]);

    Mat SobelEdges = Edges::getSobelEdges(image);

    Mat ScharrEdges = Edges::getScharrEdges(image);

    imwrite("Sobel.jpg", SobelEdges);
    imwrite("Scharr.jpg", ScharrEdges);

    return 0;
}