#include <iostream>

class Window{
    int leftCornerX=3;
    int leftCornerY=25;
    int height=5;
    int width=8;

public:
    int getLeftCornerX () {
        return leftCornerX;
    }

    int getRightCornerY () {
        return leftCornerY;
    }

    int getHeightW () {
        return height;
    }

    int gatWidthW () {
        return width;
    }

    void move (int valueW, int valueH) {
        leftCornerX=0;
        leftCornerY=0;
        if (leftCornerY+valueH<0) leftCornerY=0;
        if (leftCornerY+valueH>50) leftCornerY=50;
        if (leftCornerX+valueW<0) leftCornerX=0;
        if (leftCornerX+valueW>80) leftCornerX=80;
        if (leftCornerY+valueH>=0 && leftCornerY+valueH<=50) leftCornerY+=valueH;
        if (leftCornerX+valueW>=0 && leftCornerX+valueW<=80) leftCornerX+=valueW;
        std::cout<<"Coordinate window: "<<getLeftCornerX()<<";"<<getRightCornerY()<<std::endl;
    }

    void resize (int widthX, int heightY) {
        width=0;
        height=0;
        if (width+widthX<0) width=0;
        if (height+heightY<0) height=0;
        if (width+widthX>80) width=80;
        if (height+heightY>50) height=50;
        if (width+widthX>=0 && width+widthX<=80) width+=widthX;
        if (height+heightY>=0 && height+heightY<=50) height+=heightY;
        std::cout<<"New size: width "<<gatWidthW()<<" height "<<getHeightW()<<std::endl;
    }

    void display () {
        for (int y = 50; y>0; --y) {
            for (int x = 0; x < 80; ++x) {
                if (x>=leftCornerX-1 && x<leftCornerX+width && y<=leftCornerY && y>leftCornerY-height) {
                    std::cout << " 1 ";
                } else {
                    std::cout << " 0 ";
                }
            }
            std::cout<<std::endl;
        }
    }
};

class Monitor {
    int height = 50;
    int width = 80;

public:
    int getHeightM () {
        return height;
    }

    int getWidthM () {
        return width;
    }
};

int main() {
    Monitor *monitor = new Monitor;
    Window * window = new Window;
    while (true) {
        std::cout << "Enter the command (move/resize/display/close):" << std::endl;
        std::string command;
        std::cin >> command;

        if (command=="close"){
            break;
        } else {
            if (command=="move") {
                std::cout<<"Enter coordinate: "<<std::endl;
                int x,y;
                std::cin>>x>>y;
                window->move(x,y);
            } else {
                if (command=="resize") {
                    std::cout<<"Enter new size: "<<std::endl;
                    int width, height;
                    std::cin>>width>>height;
                    window->resize(width,height);
                } else {
                    if (command=="display") {
                        window->display();
                    }
                }
            }
        }
    }
    delete window;
    delete monitor;
}
