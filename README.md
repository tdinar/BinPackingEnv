README.md:

# BinPackingEnv

A high-performance 2D/3D bin-packing reinforcement learning environment built with NVIDIA PhysX for physical simulation and TensorFlow for Deep Q-Learning (DQN).

## Features
- Realistic physical simulation of box placement using PhysX
- Modular C++ core with pybind11 Python bindings
- Compatible with TensorFlow and Gym-style RL interfaces
- Visual debugging with scene snapshots
- Unit tests using GoogleTest

## Getting Started

### Prerequisites
Manually download and place the following third-party libraries into the `external/` directory:

- **PhysX SDK**:
  [https://github.com/NVIDIA/PhysX](https://github.com/NVIDIA/PhysX)
- **pybind11**:
  [https://github.com/pybind/pybind11](https://github.com/pybind/pybind11)
- **GoogleTest**:
  [https://github.com/google/googletest](https://github.com/google/googletest)

Ensure these subfolders are placed properly:
```
external/
  PhysX/
  pybind11/
  googletest/
```

### Build Instructions
```bash
mkdir build && cd build
cmake ..
make
```

### Run Tests
```bash
./run_tests
```

### Python Interface
```python
import py_binpacking
env = py_binpacking.BinPackingEnv2D()
```

## Roadmap
- [x] Minimal 2D bin placement
- [x] Unit test framework
- [ ] Episode-based reward computation
- [ ] TensorFlow DQN agent
- [ ] Visualization via matplotlib / OpenGL / Isaac Sim

## License
MIT License. See LICENSE file for details.

## Author
Tariq Dinar (GitHub: @tdinar)
LICENSE:

MIT License

Copyright (c) 2025 Tariq

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

