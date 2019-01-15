//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_POINT_H
#define ALGOPROJECT_POINT_H

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    int getX() {
        return this->x;
    }

    void setY(int y) {
        this->y = x;
    }

    int getY() {
        return this->y;
    }
};

#endif //ALGOPROJECT_POINT_H
