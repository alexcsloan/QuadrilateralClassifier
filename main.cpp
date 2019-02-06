//
//  main.cpp
//  assignment3
//
//  Created by Alexander Sloan on 1/15/19.
//  Copyright © 2019 Alexander Sloan. All rights reserved.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <float.h>
#include <assert.h>



using namespace std;

//error 3 detection from: https://codea.io/talk/discussion/5930/line-segment-intersection
struct Point
{
    int x;
    int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);
    
    if (val == 0) return 0;  // colinear
    
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    
    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    
    return false; // Doesn't fall in any of the above cases
}


bool isParallelogram(const vector<double> &sides, const vector<double> &slopes){

    if (slopes[0] == slopes[2] && slopes[1] == slopes[3] && slopes[0] != slopes[1]) {
        return true;
    }
    return false;
}

bool isRhombus(const vector<double> &sides, const vector<double> &slopes){
    
    if(!isParallelogram(sides,slopes)) return false;
    
    for(int i=1; i<4; i++){
        if(sides[0]!=sides[i]) return false;
    }
    return true;
}

bool isRectangle(const vector<double> &sides, const vector<double> &slopes){
    if(sides[0]!=sides[2] || sides[1]!=sides[3]) return false;

    if(slopes[0]==0 && slopes[2]==0 && slopes[1]==0 && slopes[3]==0) return true;
    
    
    return false;
}

bool isSquare(const vector<double> &sides, const vector<double> &slopes){
    if(!isRectangle(sides,slopes)) return false;
    
    for(int i=1; i<4; i++){
        if(sides[0]!=sides[i]) return false;
    }
    return true;
}


bool isTrapezoid(const vector<double> &slopes){
    int sum = 0;
    
    if(slopes[0]==slopes[2]) sum++;
    if(slopes[1]==slopes[3]) sum++;
    
    return sum==1;
}

bool isKite(const vector<double> &sides){
    int counter = 0;
    
    if(sides[0]==sides[1] || sides[0]==sides[3]) counter++;
    if(sides[1]==sides[2] || sides[2]==sides[3]) counter++;
    
    return counter==2;
}


//this function will return a vector with the length of the 4 sides of the shape and the 4 angles
vector<double> parseString (const string& input){
    vector <double> shape;
    //pushing back 0,0 to the vector because this is assumed to be the first coordinate
    shape.push_back(0);
    shape.push_back(0);

    vector<string> results;
    
    istringstream iss(input);
    
    for(string input; iss>>input;)
        results.push_back(input);
    

    for(int i=0; i<results.size(); i++){
        //if the string to double conversion is not possible
        try{
            shape.push_back(stod(results[i]));
        }catch(const std::invalid_argument& e){
            vector<double> fail;
            return fail;
        }
    }
    
    return shape;
}

//function to calculate the length of a line between 2 sets of x and y coordinates
double calculateLength (double x1, double y1, double x2, double y2){
    double distance = 0;
    
    distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    
    return distance;
}


//function to calculate the slope between 2 sets of x and y coordinates
double calculateSlope(double x1, double y1, double x2, double y2){
    double dx = (x2 - x1);
    double dy = (y2 - y1);
    
    if(dy==0){
        return 0;
    }
    
    if(dx==0){
        return 0;
    }
    
    
    double slope = dy / dx;
    
    
    return slope;
}

bool isError3(const vector<double> coords){
    struct Point A = {0,0}, B = {static_cast<int>(coords[2]), static_cast<int>(coords[3])}, C = {static_cast<int>(coords[4]), static_cast<int>(coords[5])}, D = {static_cast<int>(coords[6]), static_cast<int>(coords[7])};
    //only opposite lines can intersect
    if(doIntersect(A, B, C, D)) return true;
    if(doIntersect(B, C, D, A)) return true;
    return false;
}

string determineShape(const vector <double> &coords){
    
    if(coords.size()!=8){
        return "error 1";
    }
    
    for(int i=0; i<coords.size(); i++){
        if(coords[i] < 0 || coords[i] > 100){
            return "error 1";
        }
    }
    
    
    //if any 2 points are the same, the input is invalid and cannot form a quadrilateral
    for(int i=0; i<5; i+=2){
        for(int j=i+2; j<coords.size()-1; j+=2){
            if(coords[i]==coords[j]){
                if(coords[i+1]==coords[j+1]){
                    return "error 2";
                }
            }
        }
    }
    

    //a vector to contain the 4 side lengths of the shape
    vector <double> sideLengths;
    //a vector to contain the slopes of the 4 lines
    vector <double> slopes;
    
    sideLengths.push_back(calculateLength(coords[0],coords[1],coords[2],coords[3]));
    sideLengths.push_back(calculateLength(coords[2],coords[3],coords[4],coords[5]));
    sideLengths.push_back(calculateLength(coords[4],coords[5],coords[6],coords[7]));
    sideLengths.push_back(calculateLength(coords[6],coords[7],coords[0],coords[1]));
    
    slopes.push_back(calculateSlope(coords[0],coords[1],coords[2],coords[3]));
    slopes.push_back(calculateSlope(coords[2],coords[3],coords[4],coords[5]));
    slopes.push_back(calculateSlope(coords[4],coords[5],coords[6],coords[7]));
    slopes.push_back(calculateSlope(coords[6],coords[7],coords[0],coords[1]));
    
    
    //if any 3 points form a line, the input does not form a quadrilateral
    if(slopes[0]==slopes[1]&&!isSquare(sideLengths,slopes)&&!isRectangle(sideLengths,slopes)){
        return "error 4";
    }
    if(slopes[1]==slopes[2]&&!isSquare(sideLengths,slopes)&&!isRectangle(sideLengths,slopes)){
        return "error 4";
    }
    if(slopes[2]==slopes[3]&&!isSquare(sideLengths,slopes)&&!isRectangle(sideLengths,slopes)){
        return "error 4";
    }
    
    if(isError3(coords)){
        return "error 3";
    }

    
    if(isSquare(sideLengths,slopes)){
        assert (isRectangle(sideLengths, slopes));
        return "square";
    }
    if(isRectangle(sideLengths,slopes)){
        return "rectangle";
    }
    
    if(isTrapezoid(slopes)){
        return "trapezoid";
    }
    
    if(isRhombus(sideLengths,slopes)){
        assert(isParallelogram(sideLengths,slopes));
        return "rhombus";
    }
    if(isParallelogram(sideLengths,slopes)){
        return "parallelogram";
    }
    if(isKite(sideLengths)) {
        return "kite";
    }

    return "quadrilateral";
}

void readInputDetermineShape (){
    vector <double> coords;
    string s;
    while(getline(cin,s)){
        if(!s.empty()){
            coords = parseString(s);
            if(determineShape(coords)=="error 1"){
                cout<<"error 1"<<endl;
                break;
            }
            if(determineShape(coords)=="error 2"){
                cout<<"error 2"<<endl;
                break;
            }
            if(determineShape(coords)=="error 3"){
                cout<<"error 3"<<endl;
                break;
            }
            if(determineShape(coords)=="error 4"){
                cout<<"error 4"<<endl;
                break;
            }else{
                cout<<determineShape(coords)<<endl;
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    
    readInputDetermineShape();
    
    return 0;
}

