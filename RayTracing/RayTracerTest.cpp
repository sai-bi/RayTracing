#include "RayTracerTest.h"
#include <vector>
#include <ctime>
using namespace std;
using namespace cv;

void SingleSampleRayTracer(){
    HitRecord record;
    bool is_a_hit;
    float t_max; 
    Vector3D direction(0,0,-1); // viewing ray direction

    vector<Shape*> shapes;
    shapes.push_back(new Sphere(Vector3D(250,250,-1000), 150, RGB(0.2,0.2,0.8)));
    shapes.push_back(new Triangle(Vector3D(300.0, 600.0, -800),
                                  Vector3D(0.0, 100.0,-1000.0),
                                  Vector3D(450.0, 20.0, -1000.0)
                                  RGB(0.8,0.2,0.2)));

    Mat_<Vec3b> image(500,500);
    int width = image.cols;
    int height = image.rows;

    cout<<"Start single sample ray tracing..."<<endl;
    clock_t start_t = clock();
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            t_max = 100000.0;
            is_a_hit = false;
            Ray ray(Vector3D(i,j,0), direction);

            for(int k = 0;k < shapes.size();k++){
                if(shapes[k]->Hit(ray, 0.00001, t_max,0, record)){
                    t_max = record.t_;
                    is_a_hit = true;
                }
            }
            if(is_a_hit){
                image(i,j) = Vec3b(255 * record.color_);
            }
            else{
                image(i,j) = Vec3b(255 * RGB(0.2,0.2,0.2));
            }
        }
    }
    cout<<"Single sample ray tracing finishes..."<<endl;
    cout<<"Time taken: "<<(clock() - start_t) / CLOCKS_PER_SEC<<endl;

    imshow("Result", image);
    waitKey(0);
};