#include "line.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(line, m) {

    py::class_<Line>(m, "Line")
        .def(py::init<Point, Point>())
        .def("__repr__",
            [](const Line& vec) {

                std::string r("A line\n");
                py::print(vec.m_p1);
                py::print(vec.m_p2);
            	return r;
        	}
    	);
}