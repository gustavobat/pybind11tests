#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class Point {

public:
    double m_x;
    double m_y;
    double m_z;

public:
    Point()= default;
    Point(double x, double y, double z) {
    m_x = x;
    m_y = y;
    m_z = z;
}
};

PYBIND11_MODULE(point, m) {

    py::class_<Point>(m, "Point")
            .def(py::init<double, double, double>())
                    .def("__repr__",
            [](const Point& pt) {

                std::string r("Point: ");
                r += pt.m_x;
                r += " ";
                r += pt.m_y;
                r += " ";
                r += pt.m_z;
            	return r;
        	}
    	);
}

#endif //UNTITLED1_POINT_H
