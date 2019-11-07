#ifndef UNTITLED1_LINE_H
#define UNTITLED1_LINE_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include "point.h"

class Line {
private:
    Point m_p1;
    Point m_p2;
public:
    Line(Point p1, Point p2);
};

PYBIND11_MODULE(line, m) {

    py::class_<Line>(m, "Line")
        .def(py::init<Point, Point>())
        .def("__repr__",
            [](const Line& vec) {

                std::string r("A line\n");
            	return r;
        	}
    	);
}

#endif //UNTITLED1_LINE_H
