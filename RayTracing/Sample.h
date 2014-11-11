#ifndef SAMPLE_H
#define SAMPLE_H
#include <vector>
#include <opencv2/opencv.hpp>
#include <cmath>

// jitter sample, SampleNum is a square number
void jitter(std::vector<cv::Vec2d>& samples, int SampleNum){
    int sqrt_num = std::sqrt(SampleNum);
    cv::RNG random(cv::getTickCount());
    for (int i = 0; i < sqrt_num; i++){
        for (int j = 0; j < sqrt_num; j++){
            double x = (i + random.uniform(0.0f, 1.0f)) / (double)sqrt_num;
            double y = (j + random.uniform(0.0f, 1.0f)) / (double)sqrt_num;
            samples.push_back(cv::Vec2d(x,y)); 
        }
    }
}


#endif