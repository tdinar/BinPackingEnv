#include <pybind11/pybind11.h>
#include "BinPackingEnv.h"

namespace py = pybind11;

PYBIND11_MODULE(py_binpacking, m) {
    py::class_<BinPackingEnv>(m, "BinPackingEnv")
        .def(py::init<SimMode>())
        .def("reset", &BinPackingEnv::reset)
        .def("step", &BinPackingEnv::step)
        .def("get_state", &BinPackingEnv::get_state);

    py::enum_<SimMode>(m, "SimMode")
        .value("MODE_2D", SimMode::MODE_2D)
        .value("MODE_3D", SimMode::MODE_3D);
}
