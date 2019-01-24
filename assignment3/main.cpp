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
using namespace std;



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
    
//    istringstream iss(input);
//    vector<string> results(istream_iterator<string>{iss},istream_iterator<string>());
    
    vector<string> results;
    
    istringstream iss(input);
    
    for(string input; iss>>input;)
        results.push_back(input);
 
    
    for(int i=0; i<results.size(); i++){
        shape.push_back(stod(results[i]));
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
        cout<<"invalid"<<endl;
        return "invalid";
    }
    
    //if any 2 points are the same, the input is invalid and cannot form a quadrilateral
    for(int i=0; i<5; i+=2){
        for(int j=i+2; j<coords.size()-1; j+=2){
            if(coords[i]==coords[j]){
                if(coords[i+1]==coords[j+1]){
                    cout<<"invalid"<<endl;
                    return "invalid";
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
        cout<<"invalid"<<endl;
        return "invalid";
    }
    if(slopes[1]==slopes[2]){
        cout<<"invalid"<<endl;
        return "invalid";
    }
    if(slopes[2]==slopes[3]){
        cout<<"invalid"<<endl;
        return "invalid";
    }

    if(isSquare(sideLengths,slopes)){
        cout<<"square"<<endl;
        return "square";
    }
    if(isRectangle(sideLengths,slopes)){
        cout<<"rectangle"<<endl;
        return "rectangle";
    }
    if(isTrapezoid(slopes)){
        cout<<"trapezoid"<<endl;
        return "trapezoid";
    }
    if(isRhombus(sideLengths,slopes)){
        cout<<"rhombus"<<endl;
        return "rhombus";
    }
    if(isParallelogram(sideLengths,slopes)){
        cout<<"parallelogram"<<endl;
        return "parallelogram";
    }
    if(isKite(sideLengths)) {
        cout<<"kite"<<endl;
        return "kite";
    }
//    if(isScalene(sideLengths)){
//        cout<<"scalene"<<endl;
//        return "scalene";
//    }
    cout<<"quadrilateral"<<endl;
    return "quadrilateral";
}

void readInputDetermineShape (){
    //cout<<endl;
    vector <double> coords;
    
    string s;
    while(getline(cin,s)){
        if(!s.empty()){
            coords = parseString(s);
            determineShape(coords);
        }
        
    }
}




int main(int argc, const char * argv[]) {

    readInputDetermineShape();
    
    
    return 0;
}
