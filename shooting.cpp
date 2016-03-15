#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

const int COLS = 1000;

bool loadAndScale(const string& filename, Mat& pic){
    Mat orig = imread(filename);
    if(orig.empty()){
        cout<<"can not find: "<<filename<<endl;
        return false;
    }
    Size dsize = Size(COLS, float(COLS) / float(orig.cols) * orig.rows);
    resize(orig, pic, dsize);
    return true;
}

int main(int argc, char const *argv[])
{
    string filename = "origin/image1.JPG";
    Mat pic;
    loadAndScale(filename, pic);

    namedWindow("cv");
    imshow("cv", pic);
    waitKey(0);

    return 0;
}