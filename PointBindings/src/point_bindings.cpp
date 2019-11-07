#include "point.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

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

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
