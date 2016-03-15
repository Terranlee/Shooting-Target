#include <iostream>
#include <vector>
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

void onMouseCatchColor(int mouseEvent, int x, int y, int flags, void* param){
    switch(mouseEvent){
        case CV_EVENT_LBUTTONDOWN:{
            Point* p = (Point*)param;
            cout<<"catch color at: ("<<y<<", "<<x<<")    "<<endl;
            *p = Point(x, y);
            break;
        }
        default:{}
    }
}

void RGB2HSVEqualize(const Mat& picRGB, Mat& picHSV){    
    cout<<"a"<<endl;
    cvtColor(picRGB, picHSV, COLOR_BGR2HSV);
    cout<<"a"<<endl;
    // equalize
    vector<Mat> hsvSplit;
    split(picHSV, hsvSplit);
    equalizeHist(hsvSplit[2],hsvSplit[2]);
    merge(hsvSplit,picHSV);
}

void catchColor(const Mat& pic){
    namedWindow("background");
    imshow("background", pic);
    Point p_back, p_tar;
    setMouseCallback("background", onMouseCatchColor, &p_back);
    waitKey(0);
    //destroyWindow("background");

/*
    namedWindow("catch target");
    imshow("catch target", pic);
    setMouseCallback("catch target", onMouseCatchColor, &p_tar);
    waitKey(0);
    destroyWindow("catch target");
*/
    
    Mat picHSV;    
    RGB2HSVEqualize(pic, picHSV);

    Vec3b background = picHSV.at<Vec3b>(p_back);

    Vec3b low = background - Vec3b(50, 50, 50);
    Vec3b high = background + Vec3b(50, 50, 50);

    Mat picThreshold;
    inRange(picHSV, low, high, picThreshold);
    
    namedWindow("answer");
    imshow("answer", picThreshold);
    waitKey(0);
    destroyWindow("answer");
}

int main(int argc, char const *argv[])
{
    string filename = "origin/image1.JPG";
    Mat pic;
    loadAndScale(filename, pic);
    catchColor(pic);

    return 0;
}