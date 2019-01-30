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



using namespace std;

// This pair is used to store the X and Y
// coordinates of a point respectively
#define pdd pair<double, double>

//https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
    
    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
    
    double determinant = a1*b2 - a2*b1;
    
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

bool doLinesIntersect (const vector<double> &coords){
    pdd A = make_pair(coords[0], coords[1]);
    pdd B = make_pair(coords[2], coords[3]);
    pdd C = make_pair(coords[4], coords[5]);
    pdd D = make_pair(coords[6], coords[7]);
    
    //line AB BC CD DA
    pdd intersection1 = lineLineIntersection(A, B, C, D);
    pdd intersection2 = lineLineIntersection(A, D, C, B);
    
    int xMax = coords[0];
    int yMax = coords[1];
    
    for(int i=2; i<coords.size(); i+=2){
        if(coords[i]>xMax){
            xMax=coords[i];
        }
    }
    
    for(int i=3; i<coords.size(); i+=2){
        if(coords[i]>yMax){
            yMax=coords[i];
        }
    }

    if(intersection1.first<xMax && intersection1.second<yMax && intersection1.first>0 && intersection1.second>0){

        //if intersection y > AB max y
        if(intersection1.second > coords[3]){
            return false;
        }
        return true;
    }
    if(intersection2.first<xMax && intersection2.second<yMax && intersection2.second>0 && intersection2.second>0){
        return true;
    }
    
    return false;
}


bool isParallelogram(const vector<double> &sides, const vector<double> &slopes){
    int counter = 0;
    if(slopes[0]==slopes[2] && slopes[1]==slopes[3]) counter++;
    if(sides[0]==sides[2] && sides[1]==sides[3]) counter++;
    
    return counter==2;
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
    if(slopes[0]==0 && slopes[2]==0 && slopes[1]==90 && slopes[3]==90) return true;
    
    
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
    
    //decided to make a vertical line return 90 while a horizontal line will return 0
    if(dx==0){
        return 90;
    }
    
    double slope = dy / dx;
    
    return slope;
}

string determineShape(const vector <double> &coords){
    
    if(coords.size()!=8){
        //cout<<"error 1"<<endl;
        return "error 1";
    }
    
    for(int i=0; i<coords.size(); i++){
        if(coords[i] < 0 || coords[i] > 100){
            //cout<<"error 1"<<endl;
            return "error 1";
        }
    }
    
    
    //if any 2 points are the same, the input is invalid and cannot form a quadrilateral
    for(int i=0; i<5; i+=2){
        for(int j=i+2; j<coords.size()-1; j+=2){
            if(coords[i]==coords[j]){
                if(coords[i+1]==coords[j+1]){
                    //cout<<"error 2"<<endl;
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
    if(slopes[0]==slopes[1]){
        return "error 4";
    }
    if(slopes[1]==slopes[2]){
        return "error 4";
    }
    if(slopes[2]==slopes[3]){
        return "error 4";
    }
    
    if(doLinesIntersect(coords)){
        return "error 3";
    }
    
    if(isSquare(sideLengths,slopes)){
        //cout<<"square"<<endl;
        return "square";
    }
    if(isRectangle(sideLengths,slopes)){
        //cout<<"rectangle"<<endl;
        return "rectangle";
    }
    
    if(isTrapezoid(slopes)){
        //cout<<"trapezoid"<<endl;
        return "trapezoid";
    }
    
    if(isRhombus(sideLengths,slopes)){
        //cout<<"rhombus"<<endl;
        return "rhombus";
    }
    if(isParallelogram(sideLengths,slopes)){
        //cout<<"parallelogram"<<endl;
        return "parallelogram";
    }
    if(isKite(sideLengths)) {
        //cout<<"kite"<<endl;
        return "kite";
    }

    //cout<<"quadrilateral"<<endl;
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

