#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <opencv2/core.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

#ifdef _DEBUG
#pragma comment(lib,"opencv_world490d.lib")
#else
#pragma comment(lib,"opencv_world490.lib")
#endif


Mat wienerfilter(const Mat& img,const Mat& ker,double K) {
	Mat img32, k, img32FFT, kf;
	img.convertTo(img32, CV_32F, 1 / 255.f);
	ker.convertTo(k, CV_32F, 1 / 255.f);
	k /= sum(k);
	dft(img32, img32FFT, DFT_COMPLEX_OUTPUT);
	dft(k, kf, DFT_COMPLEX_OUTPUT);
	Mat channels[2], mag;
	split(kf, channels);
	magnitude(channels[0], channels[1], mag);
	pow(mag, 2, mag);
	mag += K;
	Mat real, imag;
	divide(channels[0], mag, real);
	divide(-channels[1], mag, imag);
	Mat wiener;
	Mat mergedchannels[] = { real,imag };
	merge(mergedchannels, 2, wiener);
	Mat Deconv, DeconvFFT;
	mulSpectrums(img32FFT, wiener, DeconvFFT, 0);
	dft(DeconvFFT, Deconv, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
	return Deconv;

};
int main(void) {

	Mat img1 = imread("C:/Users/choij/Desktop/Wiener_Input1.png", IMREAD_GRAYSCALE); //Èæ¹é
	Mat img2 = imread("C:/Users/choij/Desktop/Wiener_Input2.png", IMREAD_GRAYSCALE); //Èæ¹é
	Mat kernel = imread("C:/Users/choij/Desktop/Wiener_Kernel.png", IMREAD_GRAYSCALE); //Èæ¹é
	
	Mat img1res=wienerfilter(img1, kernel, 0.001);
	Mat img2res = wienerfilter(img2, kernel, 0.01);
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img1 restore", img1res);
	imshow("img2 restore", img2res);
	waitKey();


}